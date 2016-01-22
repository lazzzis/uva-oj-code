/**
 * AC @ 13 Dec 2015
 * Run Time : 199ms
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000 + 5;
int N, M, K;
int colored[MAXN], vis[MAXN];
vector<int> links[MAXN];

void srh(int root) {
    memset(vis, 0, sizeof(vis));
    vector<int>& link = links[root];
    for (int i = 0; i < (int)link.size(); ++ i) {
        if (colored[link[i]] != -1) {
            vis[colored[link[i]]] = 1;
        }
    }
    for (int i = 1; i <= K; ++ i) {
        if (vis[i] == 0) {
            colored[root] = i;
            break;
        }
    }
   for (int i = 0; i < (int)link.size(); ++ i) {
        if (colored[link[i]] == -1) {
            srh(link[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 0;
    while (cin >> N >> M) {
        if ( _ ) {
            cout << endl;
        }
        _ = 1;
        for (int i = 1; i < N + 1; ++ i) {
           links[i].clear();
        }
        int x, y;
        for (int i = 0; i < M; ++ i) {
            cin >> x >> y;
            links[x].push_back(y);
            links[y].push_back(x);
        }
        K = 0;
        for (int i = 1; i < N + 1; ++ i) {
            K = max(K, (int) links[i].size());
        }
        K = K % 2 == 0 ? K + 1 : K;
        memset(colored, -1, sizeof(colored));
        srh(1);
        cout << K << endl;
        for (int i = 1; i <= N; ++ i) {
            cout << colored[i] << endl;
        }
    }
    return 0;
}
