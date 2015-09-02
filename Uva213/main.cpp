/*
    UvaOJ 213
    Emerld
    Mon 20 Apr, 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int readChar() {
    char ch;
    while( true ) {
        ch = getchar();
        if( ch !='\r' && ch!='\n' ) {
            return ch;
        }
    }
}

const int MAXN = 8;
int code[ MAXN ][ 1 << MAXN ];

int readInt( int n ) {
    int v = 0;
    while( n -- ) {
        v = v * 2 + readChar() - '0';
    }
    return v;
}

int readCode() {
    code[1][0] = readChar();
    int len, i;
    char ch;
    for( len = 2; len <=7; len ++ ) {
        for( i=0; i < (1<<len)-1; i++ ) {
            ch = getchar();
            if( ch == EOF ) {
                return 0;
            } else if( ch=='\n' || ch=='\r' ) {
                return 1;
            }
            code[len][i] = ch;
        }
    }
    return 1;
}

int main() {
    while( readCode() ) {
        while( true ) {
            int len = readInt( 3 );
            if( len == 0 ) {
                break;
            }
            while( true ) {
                int value = readInt( len );
                if( value == ( 1<<len )-1 ) {
                    break;
                }
                printf( "%c", code[len][value] );
            }
        }
        printf( "\n" );
    }
    return 0;
}
