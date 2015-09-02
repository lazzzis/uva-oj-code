/*
	UvaOJ 12657
	Emerald
	Sat 13 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 100000 + 50;
int leftPos[ MAXN ], rightPos[ MAXN ];

void Init( const int& N ) {
	for( int i=1; i<=N; i++ ) {
		leftPos[i] = i-1;
		rightPos[i] = ( i + 1 ) % ( N + 1 );
	}
	/*leftPos[1] = N;
	rightPos[N] = 1;*/
	// This is wrong when the N is put leftPos to the 1
	rightPos[0] = 1;
	leftPos[0] = N;
}

void Link( int x, int y ) {
	rightPos[ x ] = y;
	leftPos[ y ] = x;
}

template<typename T>
void Swap( T& a, T& b ) {
	T t = a;
	a = b;
	b = t;
}

int main() {
	int N, M;
	int counter = 0;
	while( cin >> N >> M ) {
		int op, x, y;
		bool isRes = false;
		Init( N );
		while( M -- ) {
			scanf( "%d", &op );
			if( op == 4 ) {
				isRes = !isRes;
				continue;
			}
			scanf( "%d%d", &x, &y );
			if( ( op == 1 || op == 2 ) && isRes ) {
				op = 3 - op;
			}
			if( op == 1 && leftPos[ y ] == x ) { // put x to the leftPos of y
				continue;
			}
			if( op == 2 && rightPos[ y ] == x  ) { // put x to the rightPos of y
				continue;
			}
			if( op == 3 && rightPos[y] == x ) {
				Swap( x, y );
			}
			int LX = leftPos[x], RX = rightPos[x], LY = leftPos[y], RY = rightPos[y];
			if( op == 1 ) { // put x to the leftPos of y
				Link( LX, RX );
				Link( LY, x );
				Link( x, y );
			} else if( op == 2 ) { // put x to the rightPos of y
				Link( LX, RX );
				Link( y, x );
				Link( x, RY );
			} else {
				if( leftPos[y] == x ) {
					Link( LX, y );
					Link( y, x );
					Link( x, RY );
				} else {
					Link( LX, y );
					Link( y, RX );
					Link( LY, x );
					Link( x, RY );
				}
			}
		}
		long long ans = 0;
		int b = 0;
		for( int i = 1; i <= N; i ++ ) {
			b = rightPos[b];
			if( i%2 ) {
				ans += b;
			}
		}
		if( isRes && ( N%2==0 ) ) {
			ans = ( long long ) N*(N+1)/2 - ans;
		}
		printf( "Case %d: %lld\n", ++counter, ans );
	}
	return 0;
}