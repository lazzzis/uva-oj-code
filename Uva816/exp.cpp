#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

const char* dirs = "NESW";
const char* turns = "FLR";

const int direction[4][2] = { -1,0, 0,1, 1,0, 0,-1 };
bool hasEdge[10][10][5][5]; // x, y, from_id, to_id
int vis[10][10][5];
int startX, startY, endX, endY;
char startDir;

struct Node{
    int row, col, dirId;
    Node(){};
    Node(int r, int c, int d){
        row = r;
        col = c;
        dirId = d;
    };
};

Node path[10][10][5]; // the front row, col, dir is path[row][col][dir]

int dir_id( char c ) {
    return strchr( dirs, c ) - dirs;
}

int turn_id( char c ) {
    return strchr( turns, c ) - turns;
}

void input() {
    memset(hasEdge, false, sizeof(hasEdge));
    int x, y;
    string dir;
    while( true ) {
        scanf( "%d", &x );
        if( x == 0 ) {
            break;
        }
        scanf( "%d", &y );
        while( cin >> dir && dir!="*" ) {
            for( int i=1; i<dir.length(); i ++ ) {
                hasEdge[x][y][ dir_id( dir[0] ) ][ turn_id( dir[i] ) ] = true;
            }
        }
    }
}

bool Inside( int x, int y ) {
    return x > 0 && x < 10 && y > 0 && y < 10;
}

Node nextWalk( Node u, int i ) {
    int dir = u.dirId;
    if( i == 1 ) {
        dir = ( dir+3 ) % 4;
    }
    if( i == 2 ) {
        dir = ( dir+1 ) % 4;
    }
    return Node( u.row + direction[dir][0], u.col + direction[dir][1], dir );
}

void Print( Node t ) {
    stack<Node> st;
    while( true ) {
        st.push( t );
        if( vis[t.row][t.col][t.dirId] == 0 ) {
            break;
        }
        t = path[t.row][t.col][t.dirId];
    }
    st.push( Node( startX, startY, startDir ) );
    int size = st.size();
    for( int i=0; i < size; i++ ) {
        if( i % 10 == 0 ) {
            printf(" ");
        }
        printf(" (%d,%d)", st.top().row, st.top().col );
        st.pop();
        if( i % 10 == 9 ) {
            printf("\n");
        }
    }
    if( size % 10 != 0 ) {
        printf("\n");
    }
}

bool bfs() {
    memset( vis, -1, sizeof(vis) );
    queue <Node> q;
    Node t, next;
    t.row = startX + direction[ dir_id( startDir ) ][0];
    t.col = startY + direction[ dir_id( startDir ) ][1];
    t.dirId = dir_id( startDir );
    vis[t.row][t.col][t.dirId] = 0;
    q.push(t);
    while(!q.empty()) {
        t = q.front();
        q.pop();
        if( t.row == endX && t.col == endY ) {
            Print( t );
            return true;
        }
        for( int i=0; i<3; i++ ) {
            Node v = nextWalk( t, i );
            if( hasEdge[t.row][t.col][t.dirId][i] && Inside( v.row, v.col ) && vis[v.row][v.col][v.dirId] < 0 ) {
                vis[v.row][v.col][v.dirId] = vis[t.row][t.col][t.dirId] + 1;
                path[v.row][v.col][v.dirId] = t;
                q.push( v );
            }
        }
    }
    return false;
}

int main() {
    string caseName;
    while( cin >> caseName && caseName != "END" ) {
        cout << caseName << endl;
        cin >> startX >> startY >> startDir >> endX >> endY;
        input();
        if( !bfs() ) {
            printf("  No Solution Possible\n");
        }
    }
    return 0;
}