/*
    UvaOJ 816
    Emerald
    Sun 26 Jul 2015
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const char *defaultDir = "NESW";
const char *defaultTurn = "FLR";
int dirArray[4][2] = {-1, 0, 0,1, 1,0, 0,-1}; // NESW
bool hasDir[9+5][9+5][5][5]; // x, y, dirId, turnId

int DirId(char ch) {
    return strchr(defaultDir ,ch) - defaultDir;
}

int TurnId(char ch) {
    return strchr(defaultTurn ,ch) - defaultTurn;
}

int startX, startY, endX, endY;
char startDir;
void Read() {
    cin >> startX >> startY >> startDir >> endX >> endY;
    int x, y;
    memset(hasDir, false, sizeof(hasDir));
    while(scanf("%d", &x)!=EOF && x != 0) {
        scanf("%d", &y);
        string next;
        while(cin >> next && next != "*") {
            for(int i=1; i<int(next.length()); i ++) {
                hasDir[x][y][ DirId(next[0]) ][ TurnId(next[i]) ] = true;
            }
        }
    }
}

struct Node{
    int x, y, curDirId;
    Node(){}
    Node(int i, int j, int k){
        x = i; y = j; curDirId = k;
    }
};

Node NextWalk(int x, int y, int dir, int turn) {
    if( turn == 1 ) {
        dir = (dir + 3) % 4;
    } else if(turn == 2) {
        dir = (dir + 1) % 4;
    }
    return Node(x + dirArray[dir][0], y + dirArray[dir][1], dir);
}

bool isVis[9+5][9+5][4+2]; // x, y, dirId
Node path[9+5][9+5][4+2]; // x, y, dirId

bool Inside(int x, int y) {
    return x>=1 && x <= 9 && y >= 1 && y <=9;
}

void Print(Node u);

void Bfs() {
    queue<Node> q;
    Node t, next;
    t = NextWalk( startX, startY,DirId(startDir), TurnId('F') );
    memset(isVis, false, sizeof(isVis));
    isVis[t.x][t.y][t.curDirId] = true;
    path[t.x][t.y][t.curDirId] = Node(-1, -1, -1);
    q.push( t );
    while( !q.empty() ) {
        t = q.front();
        q.pop();
        if( t.x == endX && t.y == endY ) {
            Print( t );
            return ;
        }
        for( int i = 0; i < 3; i ++ ) {
            if( !hasDir[t.x][t.y][t.curDirId][i] ) {
                continue;
            }
            next = NextWalk(t.x, t.y, t.curDirId, i);
            if( Inside(next.x, next.y) && !isVis[next.x][next.y][next.curDirId] ) {
                isVis[next.x][next.y][next.curDirId] = true;
                path[next.x][next.y][next.curDirId] = t;
                q.push(next);
            }
        }
    }
    printf("  No Solution Possible\n");
    return ;
}

void Print(Node u) {
    std::vector<Node> v;
    while( true ) {
        v.push_back(u);
        u = path[u.x][u.y][u.curDirId];
        if(u.x == u.y && u.x == -1) {
            break;
        }
    }
    v.push_back( Node(startX, startY, 0) );
    int cnt = 0;
    for( int i=v.size()-1; i>=0; i-- ) {
        if( cnt == 0 ) {
            printf(" ");
        }
        printf(" (%d,%d)", v[i].x, v[i].y);
        if ( cnt == 9 ) {
            printf("\n");
        }
        cnt = (cnt + 1) % 10;
    }
    if( cnt ) {
        printf("\n");
    }
}

void Work() {
    Read();
    Bfs();
}

int main() {
    string name;
    while(cin >> name && name != "END") {
        cout << name << endl;
        Work();
    }
    return 0;
}