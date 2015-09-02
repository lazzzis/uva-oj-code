/*
    UvaOJ 253
    Emerald
    Wed 23 Apr 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 6 + 10;
char firstCube[ MAXN ], secondCube[ MAXN ];
int chain[ 7 ][ 7 ] = { 0, 0,0, 0,0,0,0,
                        0, 1,6, 2,3,5,4,
                        0, 6,1, 4,5,3,2,
                        0, 3,4, 1,2,6,5,
                        0, 4,3, 1,5,6,2,
                        0, 2,5, 1,4,6,3,
                        0, 5,2, 1,3,6,4 };

void Init() {
    int i;
    for( i=1; i<=6; i++ ) {
        secondCube[i] = firstCube[i+6];
    }
    secondCube[7] = firstCube[7] = '\0';
}

bool ChainCmp( char *s, char *k ) {
    int i, j;
    bool flag;
    for( i=0; i<4; i++ ) {
        flag = true;
        for( j=0; j<4; j++ ) {
            if( s[j] != k[ (j+i)%4 ] ) {
                flag = false;
                break;
            }
        }
        if( flag ) {
            return true;
        }
    }
    return false;
}

bool Try( int pos ) { // connect 1 and 6 position
    if( firstCube[1] != secondCube[ chain[pos][1] ] ||
        firstCube[6] != secondCube[ chain[pos][2] ]  ) {
        return false;
    }
    char firS[7], secS[7];
    int i;
    for( i=3; i<=6;i++ ) {
        firS[ i-3 ] = firstCube [ chain[ 1 ][ i ] ];
        secS[ i-3 ] = secondCube [ chain[ pos ][ i ] ];
    }
    return ChainCmp( firS, secS );
}

bool IsSame() {
    int i;
    for( i=1; i<=6; i++ ) {
        if( Try( i ) ) {
            return true;
        }
    }
    return false;
}

bool QuickJudge() {
    int g1 = 0, g2 = 0, r1 = 0, r2 = 0, b1 = 0, b2 = 0;
    for( int i=1; i<=6; i++ ) {
        if( firstCube[i] == 'g' ) {
            g1 ++;
        } else if( firstCube[i] == 'r' ) {
            r1 ++;
        } else if( firstCube[i] == 'b' ) {
            b1 ++;
        }
        if( secondCube[i] == 'g' ) {
            g2 ++;
        } else if( secondCube[i] == 'r' ) {
            r2 ++;
        } else if( secondCube[i] == 'b' ) {
            b2 ++;
        }
    }
    return ( g1==g2 ) && ( r1==r2 ) && ( b1==b2 );
}

int main() {
    while( scanf( "%s",firstCube+1 ) != EOF ) {
        Init();
        if( QuickJudge() && IsSame() ) {
            printf( "TRUE\n" );
        } else {
            printf( "FALSE\n" );
        }
    }
    return 0;
}
