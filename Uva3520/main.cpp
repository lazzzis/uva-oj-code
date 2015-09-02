/*
    UvaOJ 3520
    Emerald
    Thu 23 Apr 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 10;
const int INF = 65523;
int maxIp[MAXN], minIp[MAXN];
int ansIp[MAXN], ansMask[MAXN];

void Init() {
    for( int i=0; i<MAXN; i++ ) {
        maxIp[i] = -INF;
        minIp[i] = INF;
    }
}    

int GetMask( int N ) {
    return 256 - (int)pow( 2.0, ceil( log(N)/log(2) ) );
}

void Print() {
    printf( "%d.%d.%d.%d\n", ansIp[0], ansIp[1], ansIp[2], ansIp[3] );
    printf( "%d.%d.%d.%d\n", ansMask[0], ansMask[1], ansMask[2], ansMask[3] );
}

int main() {
    int T, i;
    int tmpIp[MAXN];
    while( cin >> T ) {
        scanf( "%d.%d.%d.%d", &ansIp[0], &ansIp[1], &ansIp[2], &ansIp[3] );
        for( i=0; i<4; i++ ) {
            maxIp[i] = minIp[i] = ansIp[i];
        }
        T--;
        while( T-- ) {
            scanf( "%d.%d.%d.%d", &tmpIp[0], &tmpIp[1], &tmpIp[2], &tmpIp[3] );
            for( i=0; i<4; i++ ) {
                maxIp[i] = maxIp[i] > tmpIp[i] ? maxIp[i] : tmpIp[i];
                minIp[i] = minIp[i] < tmpIp[i] ? minIp[i] : tmpIp[i];
                ansIp[i] = ansIp[i] & tmpIp[i];
            }
        }
        for( i=0; i<4; i++ ) {
            if( maxIp[i] == minIp[i] ) {
                ansMask[i] = 255;
            } else {
                ansMask[i] = GetMask( maxIp[i]-minIp[i]+1 );
                break;
            }
        }
        for( i++; i<4; i++ ) {
            ansMask[i] = 0;
        }
        Print();
    }
    return 0;
}
