/**
 * AC @ Sep 30th 2015
 * Run Time : 0.000s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 24;

struct Point {
    double x, y;
}points[MAXN];

double dp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int N;

double dist(int id1, int id2) {
    return sqrt((points[id1].x - points[id2].x) * (points[id1].x - points[id2].x)
        + (points[id1].y - points[id2].y) * (points[id1].y - points[id2].y));
}

void read() {
    for (int i = 1; i < N + 1; ++i) {
        cin >> points[i].x >> points[i].y;
    }
}

double dp_fun(int a, int b) {
    if (vis[a][b]) {
        return dp[a][b];
    }
    vis[a][b] = true;
    if (a == N - 1) {
        return dp[a][b] = dist(N, N - 1) + dist(b, N);
    }
    return dp[a][b] = min(dp_fun(a + 1, b) + dist(a, a + 1), dp_fun(a + 1, a) + dist(b, a + 1));
}

void work() {
    read();
    memset(vis, false, sizeof(vis));
    cout << fixed << setprecision(2) << dp_fun(1, 1) << endl;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> N) {
        work();
    }
    return 0;
}