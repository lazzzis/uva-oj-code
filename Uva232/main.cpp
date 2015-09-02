/*
    UvaOJ 232
    Emerald
    Sat 18 Apr, 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 10 + 2;
char puzzle[ MAXN ][ MAXN ];
int isStart[ MAXN ][ MAXN ];
//bool used[ MAXN ][ MAXN ];
int rows, cols, posCount;

const char BLACK_GRID = '*';

int isStarted( int i, int j ) { // judge whether the puzzle[i][j] is a starting point
    if( puzzle[i][j] == BLACK_GRID ) {
        return -1; // 这个
    }
    if( i-1<0 || j-1<0 ) {
        return ++posCount;
    }
    if( puzzle[i-1][j]==BLACK_GRID || puzzle[i][j-1]==BLACK_GRID ) {
        return ++posCount;
    }
    return -1;
}

void across( int x, int y ) { // whether can output a word
    if( ( y-1<0 || puzzle[x][y-1]==BLACK_GRID ) && puzzle[x][y]!=BLACK_GRID ) { // presention !!!
        printf( "%3d.", isStart[x][y] );
        while( y<cols && puzzle[x][y]!=BLACK_GRID ) {
            printf( "%c", puzzle[x][y++] );
        }
        printf("\n");
    }
}

void down( int x, int y ) { // whether can output a word
    if( ( x-1<0 || puzzle[x-1][y]==BLACK_GRID ) && puzzle[x][y]!=BLACK_GRID ) {
        printf( "%3d.", isStart[x][y] ); // presention !!!
        while( x<rows && puzzle[x][y]!=BLACK_GRID ) {
            printf( "%c", puzzle[x++][y] );
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    int counter = 0;
    while( scanf( "%d", &rows )!=EOF && rows ) {
        scanf( "%d", &cols );
        posCount = 0;
        for( i=0; i<rows; i++ ) {
            getchar();
            for( j=0; j<cols; j++ ) {
                scanf( "%c", &puzzle[i][j] );
                isStart[i][j] = isStarted( i, j );
            }
        }
        if( counter ) {
            printf( "\n" );
        }
        printf( "puzzle #%d:\n", ++counter );
        /* --------Across---------- */
        printf( "Across\n" );
        for( i=0; i<rows; i++ ) {
            for( j=0; j<cols; j++ ) {
                across( i, j );
            }
        }
        /* --------Down---------- */
        printf( "Down\n" );
        for( i=0; i<rows; i++ ) {
            for( j=0; j<cols; j++ ) {
                down( i, j );
            }
        }
    }
    return 0;
}
