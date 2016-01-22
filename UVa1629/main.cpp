/*
 * AC @ Nov 27th 2015
 * Run Time : 0.799s
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> pr_int;
int dir[4][2] = {1, 0, -1,0, 0,1, 0,-1};
const int MAXN = 20 + 5;
const int INF = 1 << 28;
int row, col, cherry;
int daze[MAXN][MAXN], d[MAXN][MAXN][MAXN][MAXN], cherries[MAXN][MAXN][MAXN][MAXN];

int read() {
    if (!(cin >> row  >> col >> cherry)) {
        return 0;
    }
    memset(daze, 0, sizeof(daze));
    memset(cherries, -1, sizeof(cherries));
    for (int i = 0; i < cherry; ++ i) {
        int x, y;
        cin >> x >> y;
        daze[x][y] ++;
    }
    return 1;
}

int contain(int x, int y, int bx, int by) {
    if (cherries[x][y][bx][by] != -1) {
        return cherries[x][y][bx][by];
    }
    int ans = 0;
    for (int i = x; i <= bx; ++i) {
        for (int j = y; j <= by; ++j) {
            if (daze[i][j]) {
                ans ++;
            }
        }
    }
    return cherries[x][y][bx][by] = ans;
}

int dp(int x, int y, int bx, int by) {
    if (d[x][y][bx][by] != -1) {
        return d[x][y][bx][by];
    }
    if (contain(x, y, bx, by) == 0) {
        return d[x][y][bx][by] = INF;
    } else if (contain(x, y, bx, by) == 1) {
        return 0;
    }
    int ans = INF;
    for (int i = x; i < bx; ++ i) {
        ans = min(ans, dp(x, y, i, by) + dp(i + 1, y, bx, by) + (by - y + 1));
    }
    for (int i = y; i < by; ++ i) {
        ans = min(ans, dp(x, y, bx, i) + dp(x, i + 1, bx, by) + (bx - x + 1));
    }
    return d[x][y][bx][by] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 0;
    while (read()) {
        memset(d, -1, sizeof(d));
        cout << "Case " << (++ Case) << ": " << dp(1, 1, row, col) << endl;
    }
    return 0;
}
