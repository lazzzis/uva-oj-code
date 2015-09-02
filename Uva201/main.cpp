/*
    UvaOJ 201
    Emerald
    Wed 22 Apr 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 7 + 3;
bool hor[ MAXN ][ MAXN ]; // means whether hor[i][j] is connected with hor[i][j+1]
bool ver[ MAXN ][ MAXN ]; // means whether ver[i][j] is connected with ver[i+1][j]
int N, lines;

void Init() {
    memset( hor, false, sizeof( hor ) );
    memset( ver, false, sizeof( ver ) );
}

int ConSquare( int x, int y, int length ) {
    int i;
    for( i=x; i<x+length; i++ ) {
        if( !ver[i][y] || !ver[i][y+length] ) { 
            return 0;
        }
    }
    for( i=y; i<y+length; i++ ) {
        if( !hor[x][i] || !hor[x+length][i] ) { 
            return 0;
        }
    }
    return 1;
}

int Find( int length ) {
    int total = 0;
    int i, j;
    for( i=1; i<=N-length; i++ ) {
        for( j=1; j<=N-length; j++ ) {
            total = total + ConSquare( i, j, length );
        }
    }
    return total;
}

int main() {
    int counter = 0;
    char s[3];
    int x, y;
    int i, j;
    while( scanf( "%d%d", &N, &lines )!=EOF ) {
        Init();
        for( i=0; i<lines; i++ ) {
            scanf( "%s%d%d", s, &x, &y );
            s[0] == 'H' ? hor[x][y] = true : ver[y][x] = true; // paying attention to x. y
        }
//        for( i=1; i<=N; i++ ) {
//            for( j=1; j<=N; j++ ) {
//                printf( "%2d", ver[i][j] );
//            }
//            printf( "\n" );
//        }
        if( counter ) {
            printf( "\n**********************************\n\n" );
        }
        counter ++;
        printf( "Problem #%d\n\n", counter );
        int flag = false;
        int sum;
        for( i=1; i<N; i++ ) {
            sum = Find( i );
            if( sum != 0 ) {
                flag = true;
                printf( "%d square (s) of size %d\n", sum, i );
            }
        }
        if( !flag ) {
            printf( "No completed squares can be found.\n" );
        }
//        printf( "\n**********************************\n\n" );
    }
    return 0;
}
