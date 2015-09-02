/*
    UvaOJ 679
    Emerald
    Wed 20 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    int T;
    while( cin >> T && T!=-1 ) {
        while( T -- ) {
            int N, depth;
            int order = 1;
            scanf( "%d%d", &depth, &N );
            while( order < 1<<(depth-1) ) {
                // N%2 == 1 -> left, or else right
                order = order*2 + !( N&1 );
                N = ( N + (N&1) )/ 2;
            }
            printf( "%d\n", order );
        }
    }
    return 0;
}