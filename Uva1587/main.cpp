/*
    UvaOJ 3214
    Emerald
    Sun 19 Apr, 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct Node{
    int len, width;
}Node;

const int MAXN = 6 + 2;
Node rectan[ MAXN ];

void Swap( int &a, int &b ) {
    if( a < b ) {
        int t = a;
        a = b;
        b = t;
    }
}

void drawRec( int order, int len, int width ) {
    Swap( len, width );
    rectan[order].len = len;
    rectan[order].width = width;
}

bool cmp( Node a, Node b ) {
    if( a.len > b.len ) {
        return true;
    } else {
        return a.width > b.width;
    }
}

/*--- Can repair a box ---*/
/*
    0.a b   1.a b    2.a c   3.a c   4.b c   5. b c
*/
bool repair() {
    if( rectan[0].len!=rectan[1].len || rectan[1].len!=rectan[2].len || rectan[2].len!=rectan[3].len ) {
        return false;
    } // a
    if( rectan[0].width!=rectan[1].width || rectan[1].width!=rectan[4].len || rectan[4].len!=rectan[5].len ) {
        return false;
    } // b
    if( rectan[2].width!=rectan[3].width || rectan[3].width!=rectan[4].width || rectan[4].width!=rectan[5].width ) {
        return false;
    } // c
    return true;
}

int main() {
    int i;
    int len, width;
    while( scanf( "%d%d", &len, &width )!=EOF ) {
        drawRec( 0, len, width );
        for( i=1; i<6; i++ ) {
            scanf( "%d%d", &len, &width );
            drawRec( i, len, width );
        }
        sort( rectan, rectan + 6, cmp );
        if( repair() ) {
            printf( "POSSIBLE\n" );
        } else {
            printf( "IMPOSSIBLE\n" );
        }
    }
    return 0;
}
