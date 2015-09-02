/*
   UvaOJ 1225
   Emerald
   Sat 10 Apr, 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 10000 + 50;
int counter[ MAXN ][ 10+5 ];

void countDigit( int N ) {
    int i;
    int d = N;
    int vis[10];
    memset( vis, 0, sizeof(vis) );
    while( N!=0 ) {
        i = N % 10;
        vis[i] ++;
        N /= 10;
    }
    for( i=0; i<10; i++ ) {
        counter[d][i] = counter[d-1][i] + vis[i];
    }
}

int main() {
    memset( counter, 0, sizeof(counter) );
    int i;
    for( i=1; i<MAXN; i++ ) {
        countDigit( i );
    }
    int T;
    cin >> T;
    int N;
    while( T-- ) {
        scanf( "%d", &N );
        for( i=0; i<9; i++ ) {
            printf( "%d ", counter[N][i] );
        }
        printf( "%d\n", counter[N][9] );
    }
    return 0;
}
