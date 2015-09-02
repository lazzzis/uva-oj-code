/*
    UvaOJ 699
    Emerald
    Fri 29 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

typedef int Position, Amount;
const int UNIT = 1;

map < Position, Amount > leafPiles;

void FallLeaf( Position pos ) {
    Amount amo;
    scanf( "%d", &amo );
    if( amo == -1 ) {
        return ;
    }
    if( leafPiles.count( pos ) ) {
        leafPiles[ pos ] += amo;
    } else {
        leafPiles[ pos ] = amo;
    }
    FallLeaf( pos - UNIT ); // left subtree
    FallLeaf( pos + UNIT ); // right subtree
}

int main() {
    int counter = 0;
    int root;
    while( cin >> root && root != -1 ) {
        leafPiles.clear();
        leafPiles[0] = root;
        FallLeaf( 0 - UNIT ); // left subtree
        FallLeaf( 0 + UNIT ); // right subtree
        printf( "Case %d:\n", ++counter );
        map< Position, Amount> :: iterator it = leafPiles.begin();
        printf( "%d", it->second );
        for( it ++; it != leafPiles.end(); it ++ ) {
            printf(" %d", it->second );
        }
        printf("\n\n");
    }
    return 0;
}