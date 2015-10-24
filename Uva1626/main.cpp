/**
 * Run Time : 1.809s
 * AC @ Oct 24th 2015
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 50;
const int INF = 1 << 30;
string line;
int dp[MAXN][MAXN], vis[MAXN][MAXN];

int match(int i, int j) {
    return (line[i] == '(' && line[j] == ')') || (line[i] == '[' && line[j] == ']');
}

int search(int x, int y) {
    if (vis[x][y]) {
        return dp[x][y];
    }
    if (x > y) {
        return 0;
    }
    if (x == y) {
        return dp[x][y] = 1;
    }
    vis[x][y] = 1;
    dp[x][y] = INF;
    if (match(x, y)) {
        dp[x][y] = search(x + 1, y - 1);
    }
    for (int i=x; i<y; i++) {
        dp[x][y] = min(dp[x][y], search(x, i) + search(i + 1, y));
    }
    return dp[x][y];
}

void print(int x, int y) {
    if (x > y) {
        return ;
    }
    if (x == y) {
        if (line[x] == '(' || line[x] == ')') {
            cout << "()";
        } else {
            cout << "[]";
        }
        return ;
    }
    if (match(x, y) && dp[x][y] == dp[x + 1][y - 1]) {
        cout << line[x];
        print(x + 1, y - 1);
        cout << line[y];
        return ;
    }
    for (int i = x; i < y; ++ i) {
        if (dp[x][i] + dp[i + 1][y] == dp[x][y]) {
            print(x, i);
            print(i + 1, y);
            return ;
        }
    }
}

void work() {
    getline(cin, line);
    memset(vis, 0, sizeof(vis));
    search(0, (int) line.size() - 1);
    print(0, (int)line.size() - 1);
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    cin.get();
    while(T --) {
        getline(cin, line);
        work();
        if (T) {
            cout << endl;
        }
    }
    return 0;
}