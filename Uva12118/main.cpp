#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1000 + 50;
bool vis[MAXN];
int cnt, trees; // cnt: directly linked, trees: extraly linked
int cases = 0; // coutn cases
int cities, edges, unitTime;

std::vector<int> link[MAXN]; // link table

void VecInit() {
    for(int i=1; i<cities+1; i++) {
        link[i].clear();
    }
}

void ReadEdge() {
    int x, y;
    for(int i=0; i<edges; i++) {
        scanf("%d%d", &x, &y);
        link[x].push_back(y);
        link[y].push_back(x);
    }
}

void Bfs(int x) {
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while( !q.empty() ) {
        x = q.front();
        q.pop();
        for( int i=0; i<(int)link[x].size(); i++ ) {
            if( ! vis[ link[x][i] ] ) {
                vis[ link[x][i] ] = true;
                cnt ++;
                q.push( link[x][i] );
            }
        }
    }
}

void Fetch() {
    memset(vis, false, sizeof(vis));
    trees = cnt = 0;
    for( int i=1; i<cities + 1; i++ ) {
        if( link[i].size() && !vis[i] ) { 
        // if the vector is empty. this point is useless
            trees ++;
            Bfs( i );
        }
    }
}

void Print() {
    printf("Case %d: %d\n", ++cases, trees + cnt - 1);
}

void Work() {
    VecInit();
    ReadEdge();
    Fetch();
    Print();
}

int main() {
    while( cin >> cities >> edges >> unitTime ) {
        if( !cities && !edges && !unitTime ) {
            break;
        }
        Work();
    }
    return 0;
}