/*
    UvaOJ 133
    Emerald
    Sun 19 Apr, 2015 
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 20 + 5;
//int ring[ MAXN ];
int N, k, m;
int leave; // the amount of leave person
bool vis[ MAXN ];

int go( int pos, int step, int dir ) {
    while( step-- ) {
        do{
            pos = pos + dir;
            pos = pos == 0 ? N : pos;
            pos = pos == N+1 ? 1 : pos;
        }while( vis[pos] );
    }
    return pos;
}

int main() {
    while( scanf( "%d%d%d", &N, &k, &m )!=EOF ) {
        if( N==k && k==m && m==0 ) {
            break;
        }
        leave = N;
        int p1 = N;
        int p2 = 1;
        memset( vis, false, sizeof( vis ) );
        while( leave ) {
            p1 = go( p1, k, 1 );
            p2 = go( p2, m, -1 );
            if( p1 == p2 ) {
                printf( "%3d", p1 );
                leave --;
            } else {
                printf( "%3d%3d", p1, p2 );
                leave -= 2;
            }
            vis[p1] = vis[p2] = true;
            if( leave ) {
                printf( "," );
            }
        }
        printf( "\n" );
    }
    return 0;
}
