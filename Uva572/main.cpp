/*
	UvaOJ 572
	Emerald
	Sat 20 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

const int MAXN = 100 + 50;
const char EXIST = '@';
int M, N;
string oil[MAXN];
int idx[MAXN][MAXN];

void Dfs( int row, int col, int id ) {
	if( row < 0 || row >= M || col < 0 || col >= N ) {
		return ;
	}
	if( oil[row][col] != EXIST || idx[row][col]!=-1 ) {
		return ;
	}
	idx[row][col] = id;
	for( int dx = -1; dx <= 1; dx ++ ) {
		for( int dy = -1; dy <= 1; dy ++ ) {
			if( dx!=0 || dy!=0 ) {
				Dfs( row+dx, col+dy, id );
			}
		}
	}
}

int main() {
	while( cin >> M >> N && M!=0 ) {
		for( int i=0; i<M; i++ ) {
			cin >> oil[i];
		}
		memset( idx, -1, sizeof( idx ) );
		int counter = 0;
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				if( oil[i][j] == EXIST && idx[i][j] == -1 ) {
					Dfs( i, j, ++counter );
				}
			}
		}
		printf("%d\n", counter );
	}
	return 0;
}