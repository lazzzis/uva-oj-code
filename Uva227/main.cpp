/*
    UvaOJ: 227
    Emerald
    Sat 10 Apr, 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cctype>

using namespace std;

const int MAXN = 5 + 2;
const int LENGTH = 5;
char puzzle[ MAXN ][ MAXN ];
int counter = 0;
bool flag = true;

bool move( int &si, int &sj, char op  ) {
    if( op == 'A' ) {
        if( si-1 < 0 ) {
            return false;
        }
        puzzle[si][sj] = puzzle[si-1][sj];
        puzzle[si-1][sj] = ' ';
        si = si - 1;
    } else if( op == 'B' ) {
        if( si+1 >= LENGTH ) {
            return false;
        }
        puzzle[si][sj] = puzzle[si+1][sj];
        puzzle[si+1][sj] = ' ';
        si = si + 1;
    } else if( op == 'L' ) {
        if( sj-1 < 0 ) {
            return false;
        }
        puzzle[si][sj] = puzzle[si][sj-1];
        puzzle[si][sj-1] = ' ';
        sj = sj - 1;
    } else if( op=='R' ){
        if( sj+1 >= LENGTH ) {
            return false;
        }
        puzzle[si][sj] = puzzle[si][sj+1];
        puzzle[si][sj+1] = ' ';
        sj = sj + 1;
    }
    return true;
}

void PrintPuzzle() {
    int i, j;
    for( i=0; i<LENGTH; i++ ) {
        for( j=0; j<4; j++ ) {
            printf( "%c ", puzzle[i][j] );
        }
        printf( "%c\n", puzzle[i][4] );
    }
}

int main() {
    int i, j;
    int si, sj;
    char op;
    while( gets( puzzle[0] ) != NULL && !(puzzle[0][0]=='Z' ) ) {
        for( i=1; i<LENGTH; i++ ) {
            gets( puzzle[i] );
        }
        //PrintPuzzle();
        // find the space grid
        for( i=0; i<LENGTH; i++ ) {
            for( j=0; j<LENGTH; j++ ) {
                if( puzzle[i][j] == ' ' ) {
                    si = i;
                    sj = j;
                    break;
                }
            }
        }
        // move
        //PrintPuzzle();
        flag = true;
        while( scanf( "%c", &op )!=EOF && op!='0' ) {
            if( isalpha(op) ) {
                flag = flag ? move( si, sj, op ) : false;
                //PrintPuzzle();
            }
        }
        if( counter ) {
            printf( "\n" );
        }
        getchar();
        printf( "Puzzle #%d:\n", ++counter );
        if( flag ) {
            PrintPuzzle();
        } else {
            printf( "This puzzle has no final configuration.\n" );
        }
        //getchar();
    }
    return 0;
}
