/*
    UvaOJ 1339
    Emerald
    Sun 19 Apr, 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 26 + 5;
int c1[ MAXN ], c2[ MAXN ];

bool cmp( int a, int b ) {
    return a > b;
}

int main() {
    string a, b;
    while( cin >> a >> b ) {
        int len1 = a.length();
        int len2 = b.length();
        int i;
        memset( c1, 0, sizeof(c1) );
        memset( c2, 0, sizeof(c2) );
        for( i=0; i<len1; i++ ) {
            c1[ a[i]-'A' ] ++;
        }
        for( i=0; i<len2; i++ ) {
            c2[ b[i]-'A' ] ++;
        }
        sort( c1, c1+'Z'-'A'+1, cmp );
        sort( c2, c2+'Z'-'A'+1, cmp );
        for( i=0; i<'Z'-'A'+1; i++ ) {
            if( c1[i]!=c2[i] ) {
                break;
            }
        }
        if( i=='Z'-'A'+1 ) {
            printf( "YES\n" );
        } else {
            printf( "NO\n" );
        }
    }
    return 0;
}
