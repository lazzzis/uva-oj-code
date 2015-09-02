#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 20 + 5;
vector <int> link[MAXN];
int path[MAXN], vis[MAXN];
int N, counter;

void Init() {
    for(int i=0; i<MAXN; ++i) {
        link[i].clear();
    }
}

void Read() {
    int x, y;
    while(true) {
        scanf("%d%d", &x, &y);
        if(!x && !y) {
            break;
        }
        link[x].push_back(y);
        link[y].push_back(x);
    }
    for(int i=0; i<MAXN; i++) {
        if(link[i].size()) {
            sort(link[i].begin(), link[i].end());
        }
    }
}

void Print(int cur) {
    for(int i = 1; i < cur; ++ i) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[cur]);
}

void Dfs(int value, int cur) {
    if(value == N) {
        ++ counter;
        Print(cur);
        return ;
    }
    for(size_t i = 0; i < link[value].size(); ++ i) {
        int node = link[value][i];
        if(!vis[node]) {
            vis[node] = 1;
            path[cur+1] = node;
            Dfs(node, cur + 1);
            vis[node] = 0;
        }

    }
}

bool IsConnect() {
    int front = 0, rear = 1;
    int q[MAXN * MAXN];
    q[front] = 1;
    bool is[MAXN] = {false};
    is[1] = true;
    while(front < rear) {
        int t = q[front];
        if(t == N) {
            return true;
        }
        for(size_t i = 0; i < link[t].size(); ++ i) {
            if(!is[link[t][i]]) {
                is[link[t][i]] = true;
                q[rear ++] = link[t][i];
            }
        }
        front ++;
    }
    return false;
}

int main() {
    int Case = 0;
    while(scanf("%d", &N)!=EOF) {
        Init();
        Read();
        counter = 0;
        printf("CASE %d:\n", ++Case);
        if(IsConnect()) {
            memset(vis, 0, sizeof(vis));
            vis[1] = 1;
            path[1] = 1;
            Dfs(1, 1);
        }
        printf("There are %d routes from the firestation to streetcorner %d.\n", counter, N);
    }
    return 0;
}