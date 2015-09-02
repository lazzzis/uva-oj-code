#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 50;
typedef pair<int ,int> Node;
vector<Node> link[MAXN];
bool vis[MAXN];
int path[MAXN], dis[MAXN];
int N, M;

void Init() {
    for(int i=1; i<N+1; ++ i) {
        link[i].clear();
    }
}

void Read() {
    int f, t, c;
    for(int i=0; i<M; ++ i) {
        cin >> f >> t >> c;
        if(t != f) {
            link[f].push_back(make_pair(t, c));
            link[t].push_back(make_pair(f, c));
        }
    }
}

void Rev_Bfs() {
    memset(vis, false, sizeof(vis));
    queue<int> q;
    q.push(N);
    dis[N] = 0;
    vis[N] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if(t == 1) {
            return ;
        }
        int next;
        for(size_t i=0; i<link[t].size(); ++ i) {
            next = link[t][i].first;
            if (!vis[next]) {
                vis[next] = true;
                dis[next] = dis[t] + 1;
                q.push(next);
            }
        }
    }
}

void Bfs() {
    queue<int> q;
    q.push(1);
    memset(path, -1, sizeof(path));
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        int next, color, d;
        int minColor = 1e9 + 50;
        for(size_t i=0; i<link[t].size(); ++ i) {
            next = link[t][i].first;
            if(dis[next] + 1 == dis[t]) {            
                color = link[t][i].second;
                minColor = minColor < color ? minColor : color;
                // d = dis[1] - dis[next];
                // if(path[d] == -1 || path[d] >= color) {
                // the worse next may be pushed into q
                //     q.push(next);
                //     path[d] = color;
                // }
            }
        }
    }
}

void Print() {
    cout << dis[1] << endl;
    for(int i=1; i<dis[1]; ++ i) {
        cout << path[i] << " ";
    }
    cout << path[dis[1]] << endl;
}

void Work() {
    Init();
    Read();
    Rev_Bfs();
    Bfs();
    Print();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> N >>M) {
        Work();
    }
    return 0;
}