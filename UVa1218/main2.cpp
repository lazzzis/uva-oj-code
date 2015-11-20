#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000 + 50;
const int INF = 1 << 29;

vector<int> table[MAXN], vertices;
int parent[MAXN], dp[MAXN][3];

void dfs(int u, int fa) {
    vertices.push_back(u);
    parent[u] = fa;
    for (int i = 0; i < (int) table[u].size(); ++ i) {
        int v = table[u][i];
        if (v != fa) {
            dfs(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while(cin >> N) {
        for(int i = 0; i < N; ++ i) {
            table[i].clear();
        }
        int x, y;
        for(int i = 0; i < N - 1; ++ i) {
            cin >> x >> y;
            x --; y --;
            table[x].push_back(y);
            table[y].push_back(x);
        }
        vertices.clear();
        dfs(0, -1);
        for(int i = (int) vertices.size() - 1; i >= 0; -- i) {
            int u = vertices[i];
            dp[u][0] = 1;
            dp[u][1] = 0;
            for(int j = 0; j < (int) table[u].size(); ++ j) {
                int v = table[u][j];
                if (v == parent[u])
                    continue;
                dp[u][0] += min(dp[v][1], dp[v][0]);
                dp[u][1] += dp[v][2];
                if(dp[u][0] > INF)
                    dp[u][0] = INF;
                if(dp[u][1] > INF)
                    dp[u][1] = INF;
            }
            dp[u][2] = INF;
            for(int j = 0; j < (int) table[u].size(); ++ j) {
                int v = table[u][j];
                if (v == parent[u])
                    continue;
                dp[u][2] = min(dp[u][2], dp[u][1] - dp[v][2] + dp[v][0]);
            }
        }
        cout << min(dp[0][2], dp[0][0]) << endl;
        cin >> N;
    }
    return 0;
}
