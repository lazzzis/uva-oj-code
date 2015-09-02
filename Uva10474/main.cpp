/*
    UvaOJ 10474
    Emerald
    Thu 23 Apr 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10000 + 50;
int marbles[ MAXN ];

int main() {
    int N, Q;
    int i;
    int query;
    int T = 0;
    while( scanf( "%d%d", &N, &Q )!=EOF ) {
        if( N==0 && Q==0 ) {
            return 0;
        }
        for( i=0; i<N; i++ ) {
            scanf( "%d", &marbles[i] );
        }
        sort( marbles, marbles+N );
        printf( "CASE# %d:\n", ++T );
        while( Q-- ) {
            scanf( "%d", &query );
            int p = lower_bound( marbles, marbles+N, query ) - marbles;
            if( marbles[p] == query ) {
                printf( "%d found at %d\n", query, p+1 );
            } else {
                printf( "%d not found\n", query );
            }
        }
    }
    return 0;
}
