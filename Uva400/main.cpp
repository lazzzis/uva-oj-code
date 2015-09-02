/*
    UvaOJ 400
    Emerald
    Wed 29 Apr 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_LEN = 60;

int max( int a, int b ) {
    return a > b ? a : b;
}

void Print( string s, char extra, int len ) {
    cout << s ;
    len = len - s.length();
    for( int i=0; i<len; i++ ) {
        printf( "%c", extra );
    }
}

void Print( char extra, int len ) {
    for( int i=0; i<len; i++ ) {
        printf( "%c", extra );
    }
}

int main() {
    int N;
    int i, j;
    while( cin >> N ) {
        vector <string> v;
        string s;
        int maxLen = -1;
        for( i=0; i<N; i++ ) {
            cin >> s;
            v.push_back( s );
            int len = s.length();
            maxLen = max( len, maxLen );
        }
        sort( v.begin(), v.end() );
        Print( '-', 60 );
        printf( "\n" );
        int cols = ( MAX_LEN - maxLen ) / ( maxLen + 2 ) + 1;
        int rows = ( N-1 ) / cols + 1 ;
//        cout << rows << " " << cols << endl;
        for( i=0; i<rows; i++ ) {
            for( j=0; j<cols; j++ ) {
                if( j*rows + i < N && i*cols + j == N-1 ) {
                    Print( v[ j*rows + i ], ' ', v[ j*rows+i ].length() );
                    continue;
                }
                if( j*rows + i < N ) {
                    Print( v[ j*rows + i ], ' ', j == cols-1 ? maxLen : maxLen + 2 );
                }
            }
            printf( "\n" );
        }
    }
    return 0;
}