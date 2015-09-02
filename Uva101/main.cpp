/*
    UvaOJ 101
    Emerald
    Sun 26 Apr 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 30 + 5;
vector <int> pile[MAXN];
int N;

void FindBlocks( int a, int& p, int& h ) {
    for( p=0; p<N; p++ ) {
        for( h=0; h<pile[p].size(); h++ ) {
            if( pile[p][h] == a ) {
                return ;
            }
        }
    }
}

//  returning any blocks that are stacked on top of block p to their initial positions
void ClearAbove( int p, int h ) {
    for( int i=h+1; i<pile[p].size(); i++ ) {
        int b = pile[p][i];
        pile[b].push_back( b );
    }
    pile[p].resize( h+1 );
}

void PileOnto( int p, int h, int p2 ) {
    for( int i = h; i < pile[p].size(); i++ ) {
        pile[p2].push_back( pile[p][i] );
    }
    pile[p].resize( h );
}

void Print() {
    for( int i=0; i<N; i++ ) {
        printf( "%d:", i );
        for( int j=0; j<pile[i].size(); j++ ) {
            printf( " %d", pile[i][j] );
        }
        printf( "\n" );
    }
}

int main() {
//freopen( "1.txt", "r", stdin );
    int a, b;
    cin >> N;
    string s1, s2;
    for( int i=0; i<N; i++ ) {
        pile[i].push_back( i );
    }
    while( cin >> s1 >> a >> s2 >> b ) {
//        if( s1=="quit" ) {
//            break;
//        }
//        cin >> a >> s2 >> b;
        int pa, pb, ha, hb;
        FindBlocks( a, pa, ha );
        FindBlocks( b, pb, hb );
        if( pa==pb ) {
            continue;
        }
        if( s2 == "onto" ) {
            ClearAbove( pb, hb );
        }
        if( s1 == "move" ) {
            ClearAbove( pa, ha );
        }
        PileOnto( pa, ha, pb );
    }
    Print();
    return 0;
}
