/*
	Uva514
	Emerald
	Sun 17 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

const int MAXN = 1000 + 50;
int permu[ MAXN ];

int main() {
	int N;
	bool isFirst = true;
	while( scanf( "%d", &N )!=EOF && N ) {
		if( isFirst ) {
			isFirst = false;
		} else {
			cout << endl;
		}
		while( true ) {
			scanf( "%d", &permu[0] ); // the first element
			if( permu[0] == 0 ) {
				break;
			}
			for( int i=1; i<N; i++ ) {
				scanf( "%d", &permu[i] ); // read the permutation
			}
			stack <int> station;
			int inOder = 1, outPos = 0;
			bool isOk = true;
			while( outPos < N ) {
				if( inOder == permu[ outPos ] ) {
					inOder ++;
					outPos ++;
				} else if( !station.empty() && station.top() == permu[ outPos ] ) {
					station.pop();
					outPos ++;
				} else if( inOder <= N ) {
					station.push( inOder ++ );
				} else {
					isOk = false;
					break;
				}
			}
			printf( "%s\n", isOk ? "Yes" : "No" );
		}
	}
}