/*
	UvaOJ 10562
	Emerald -> exp
	Wed 24 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>

using namespace std;

const int MAXN = 200 + 10;
int N;
char buf[MAXN][MAXN];

void Dfs( int row, int col ) {
	printf("%c(", buf[row][col] );
	if( row+1 < N && buf[row+1][col] == '|' ) {
		int i = col;
		while( i-1>=0 && buf[row+2][i-1]=='-' ) {
			i --;
		}
		while( buf[row+2][i] == '-' && buf[row+3][i] != '\0' ) {
			if( !isspace( buf[row+3][i] ) && buf[row+3][i]!='\0' ) {
				Dfs( row+3, i );
			}
			i ++;
		}
	}
	printf(")");
}

void UnDrawTree() {
	N = 0;
	while( true ) {
		fgets( buf[N], MAXN, stdin );
		if( buf[N][0] == '#' ) {
			break;
		}else {
			N ++;
		}
	}
	printf("(");
	if( N ) {
		int length = strlen( buf[0] );
		for ( int i=0; i<length; i++ ) {
			if( buf[0][i] != ' ' ) {
				Dfs( 0, i );
				break;
			}
		}
	}
	printf(")\n");
}

int main() {
	int T;
	cin >> T;
	cin.get(); // eat the '\n'
	while( T -- ) {
		UnDrawTree();
	}
	return 0;
}