/*
    UvaOJ 40
    Emerald
    Wed 29 Apr 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 1000 + 50;

int main() {
    int N;
    int M, tmp;
    int i, counter = 0;;
    while( scanf( "%d", &N )!=EOF && N ) {
        map < int, int > team;
        queue < int > mainQueue, q[ MAXN ];
        for( i=0; i<N; i++ ) {
            scanf( "%d", &M );
            while( M -- ) {
                scanf( "%d", &tmp );
                team[ tmp ] = i; // the person tmp belongs to team i
            }
        }
        
        printf( "Scenario #%d\n", ++counter );
        char op[15];
        while( scanf( "%s", op )!=EOF && op[0]!='S' ) {
            if( op[0] == 'D' ) {
                tmp = mainQueue.front();
                printf( "%d\n", q[ tmp ].front() );
                q[ tmp ].pop();
                if( q[ tmp ].empty() ) {
                    mainQueue.pop(); // pop the team tmp
                }
            } else {
                scanf( "%d", &tmp );
                int t = team[ tmp ];
                q[ t ].push( tmp );
                if( q[t].size()==1 ) {
                    mainQueue.push( t ); // push the team t
                }
            }
        }
        printf( "\n" ); // attention here
    }
    return 0;
}
