#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 8 + 5;
bool vis[MAXN][MAXN];

struct Node{
    int x, y;
    int steps;
};

int dir[8][2] = { 1,2, 2,1, -1,2, -2,1, 1,-2, 2,-1, -1,-2, -2,-1 };

int Bfs( int x, int y, int sx, int sy ) {
    queue <Node> q;
    Node t, next;
    memset( vis, false, sizeof(vis) );
    t.x = x;
    t.y = y;
    t.steps = 0;
    vis[x][y] = true;
    q.push( t );
    while( !q.empty() ) {
        t = q.front();
        q.pop();
        if( t.x == sx && t.y == sy ) {
            return t.steps;
        }
        for( int i=0; i<8; i++ ) {
            next.x = t.x + dir[i][0];
            next.y = t.y + dir[i][1];
            next.steps = t.steps + 1;
            if( next.x>=1 && next.y<=8 && next.y>=1 && next.y<=8 && !vis[ next.x ][ next.y ] ) {
                vis[ next.x ][ next.y ] = true;
                q.push( next );
            }
        }
    }
}

int main() {
    char s[5], t[5];
    while( scanf( "%s%s", s, t )!=EOF ) {
        printf( "To get from %s to %s takes %d knight moves.\n",
        s, t, Bfs( s[0]-'a'+1, s[1]-'1'+1, t[0]-'a'+1, t[1]-'1'+1 ) );
    }
    return 0;
}
