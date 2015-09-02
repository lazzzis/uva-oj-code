#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>

using namespace std;

const int MAXN = 26 + 8;
int inDeg[MAXN], outDeg[MAXN];
bool link[MAXN][MAXN];
bool vis[MAXN];

bool Judge() {
    int more = 0, less = 0;
    for( int i=0; i<26; i++ ) {
        if( inDeg[i] == outDeg[i] + 1 ) {
            more ++;
        } else if( outDeg[i] == inDeg[i] + 1 ) {
            less ++;
        } else if( inDeg[i] == outDeg[i] ) {
            continue;
        } else {
            return false;
        }
    }
    if( ( more == less ) && ( more==1 || more==0 ) ) {
        return true;
    }
    return false;
}

int counter;
set<int> s;
void Dfs( int c ) {
    counter ++;
    if( counter == s.size() ) {
        return ;
    }
    for( int i=0; i<26; i++ ) {
        if( link[c][i] && !vis[i] ) {
            vis[i] = true;
            Dfs( i );
        }
    }
}

int main() {
    int T;
    cin >> T;
    while( T -- ) {
        int N;
        cin >> N;
        memset( inDeg, 0, sizeof(inDeg) );
        memset( outDeg, 0, sizeof(outDeg) );
        memset( link, false, sizeof(link) );
        string in;
        s.clear();
        while( N -- ) {
            cin >> in;
            inDeg[in[0]-'a'] ++;
            outDeg[in[ in.length()-1 ]-'a'] ++;
            link[ in[0]-'a' ][ in[ in.length()-1 ]-'a' ] = true;
            link[ in[ in.length()-1 ]-'a' ][ in[0]-'a' ] = true;
            s.insert( in[0]-'a' );
            s.insert( in[ in.length()-1 ]-'a' );
        }
        memset( vis, false, sizeof(vis) );
        counter = 0;
        vis[ *s.begin() ] = true;
        Dfs( *s.begin() );
        if(  counter == s.size() && Judge() ) {
            printf("Ordering is possible.\n");
        } else {
            printf("The door cannot be opened.\n");
        }
    }
    return 0;
}