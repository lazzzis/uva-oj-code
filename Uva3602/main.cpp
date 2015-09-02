/*
    UvaOJ 3602
    Emerald
    Sat 18 Apr, 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 50 + 5;
string dna[ MAXN ];
int amou, length;

int max( int a, int b, int c, int d ) {
    a = ( a>b ? a : b );
    a = ( a>c ? a : c );
    a = ( a>d ? a : d );
    return a;
}

int main() {
    int T;
    int i, j;
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d%d", &amou, &length );
        for( i=0; i<amou; i++ ) {
            cin >> dna[i];
        }
        /*-------- Print the consensud string ---------*/
        int a, t, c, g;
        int error = 0;
        for( i=0; i<length; i++ ) {
            a = t = c = g = 0;
            for( j=0; j<amou; j++ ) {
                if( dna[j][i] == 'A' ) {
                    a ++;
                } else if( dna[j][i] == 'C' ) {
                    c ++;
                } else if( dna[j][i] == 'G' ) {
                    g ++;
                } else if( dna[j][i] == 'T' ) {
                    t ++;
                }
            }
            /*------Print the letter-------*/
            int maxC = max( a, t ,c ,g );
            if( maxC == a ) {
                printf( "A" );
            } else if( maxC == c ) {
                printf( "C" );
            } else if( maxC == g ) {
                printf( "G" );
            } else if( maxC == t ) {
                printf( "T" );
            }
            /*------Consensus error-------*/
            error = error + amou - maxC;
        }
        printf( "\n%d\n", error );
    }
    return 0;
}
