#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 100 + 10;
char maze[MAXN][MAXN];
int squareMineAmou[ MAXN ][ MAXN ];

const char MINE = '*';
const char NOT_MINE = '.';

int N, M;// line and colomn

void SquareAdd( int n, int m ) { // the surrounded should be add 1
	int i, j;
	for( i=n-1; i<=n+1; i++ ) {
		for( j=m-1; j<=m+1; j++ ) {
			if( i>=0 && i<N && j>=0 && j<M && ( i!=N && j!=M ) ) {
				squareMineAmou[ i ][ j ] ++;
			}
		}
	}
}

void Print() {
	int i, j;
	for( i=0; i<N; i++ ) {
		for( j=0; j<M; j++ ) {
			if( maze[i][j]==MINE ) {
				printf( "%c", MINE );
			} else {
				printf( "%d", squareMineAmou[i][j] );
			}
		}
		printf( "\n" );
	}
}

int main() {
	int i, j;
	int counter = 0; // count the field
	while( scanf( "%d%d", &N, &M ) != EOF ) {
		if( N==0 && M==0 ) {
			break;
		}
		memset( squareMineAmou, 0, sizeof( squareMineAmou ) );
		for( i=0; i<N; i++ ) {
			getchar();
			for( j=0; j<M; j++ ) {
				scanf( "%c", &maze[i][j] );
				if( maze[i][j] == MINE ) {
					SquareAdd( i, j );
				}
			}
		}
		if( counter ) {
			printf( "\n" );
		}
		counter ++;
		printf( "Field #%d:\n", counter );
		Print();
	}
	return 0;
}
