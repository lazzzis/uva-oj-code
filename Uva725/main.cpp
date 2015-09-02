/**
 * UvaOJ 725
 * Emerald
 * Sat 4 Jul 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool IsTenDigit( int a, int b ) {
    int hash[10] = {0};
    for( int i=0; i<5; i++ ) {
        hash[a%10] ++;
        hash[b%10] ++;
        a /= 10;
        b /= 10;
    }
    for( int i=0; i<10; i++ ) {
        if( hash[i] != 1 ) {
            return false;
        }
    }
    return true;
}

void Solve( int N ) {
    bool vis = false;
    for( int i=01234; i*N<100000; i++ ) {
        if( IsTenDigit( i, i*N ) ) {
            printf("%.5d / %.5d = %d\n", i*N, i, N);
            vis = true;
        }
    }
    if( !vis ) {
        printf("There are no solutions for %d.\n", N );
    }
}

int main() {
    int counter = 0;
    int N;
    while( cin >> N && N ) {
        if( counter ) {
            printf( "\n" );
        }
        counter = 1;
        Solve(N);
    }
    return 0;
}