#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 100000 + 50;
const int INF = (10e9) + 50;
std::vector<int> link[MAXN];
std::vector<int> color[MAXN];
// the color value of edge i to link[i][j] is color[i][j]
int dis[MAXN];
int pathColor[MAXN];
// the color of step i is pathColor[i]
int N, M;

void Rev_Bfs() {
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    q.push(N);
    dis[N] = 0;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        if( t == 1 ) {
            return ;
        }
        int next;
        for(size_t i = 0; i<link[t].size(); ++i) {
            next = link[t][i];
            if(dis[next] == -1) {
                dis[next] = dis[t] + 1;
                q.push(next);
            }
        }
    }
}

void Bfs() {
    queue<int> q;
    q.push(1);
    int t, next;
    bool vis[MAXN] = {false};
    memset(pathColor, -1, sizeof(pathColor));
    while(!q.empty()) {
        // cout << t << endl;
        t = q.front();
        q.pop();
        if(t == N) {
            return ;
        }
        int minColor = INF;
        for(size_t i=0; i<link[t].size(); ++i) {
            next = link[t][i];
            if( dis[next] == dis[t]-1 && color[t][i] < minColor ) {
                minColor = color[t][i];
            }
        }
        int distance = dis[1] - dis[t]+1;
        if( pathColor[distance] == -1 ) {
            pathColor[distance] = minColor;
        } else if( pathColor[distance] >= minColor ) {
            pathColor[distance] = minColor;
        } else {
            continue;
        }
        for(size_t i=0; i<link[t].size(); ++i) {
            next = link[t][i];
            if( !vis[next] && color[t][i] == minColor && dis[next] == dis[t]-1 ) {
                q.push(next);
                vis[next] = true;
            }
        }
    }
}

bool Read() {
    if(scanf("%d%d", &N, &M)==EOF) {
        return false;
    }
    int x, y, c;
    // init
    for(int i=1; i<N+1; i++) {
        link[i].clear();
        color[i].clear();
    }
    while(M --) {
        scanf("%d%d%d", &x, &y, &c);
        if(x == y) { // loop
            continue;
        }
        link[x].push_back(y);
        color[x].push_back(c);
        link[y].push_back(x);
        color[y].push_back(c);
    }
    return true;
}

int main() {
    while(Read()) {
        Rev_Bfs();
        Bfs();
        printf("%d\n", dis[1]);
        printf("%d", pathColor[1]);
        for(int i=2; i<dis[1]+1; i++) {
            printf(" %d", pathColor[i]);
        }
        printf("\n");
    }
    return 0;
}