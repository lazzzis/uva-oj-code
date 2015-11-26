/*
 * AC @ Nov 26th 2015
 * Run Time : 0.003s
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> pr_int;

int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
const int MAXN = 100 + 40;
int height[MAXN][MAXN], d[MAXN][MAXN];
string name;
int rows, cols;

void read() {
    cin >> name >> rows >> cols;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> height[i][j];
        }
    }
}

int dp(int x, int y) {
    if (d[x][y] != -1) {
        return d[x][y];
    }
    int ans = 1;
    for (int i = 0; i < 4; ++ i) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        //cout << nx << " : " << ny  << " " << height[x][y] << " " << height[nx][ny] << endl;
        if (nx >=0 && nx < rows && ny >=0 && ny < cols && height[x][y] > height[nx][ny]) {
            ans = max(dp(nx, ny) + 1, ans);
        }
    }
    //cout << x << " " << y << endl;
    return d[x][y] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) {
        read();
        int ans = 1;
        memset(d, -1, sizeof(d));
        for (int i = 0; i < rows; ++ i) {
            for (int j = 0; j < cols; ++ j) {
                ans = max(ans, dp(i, j));
            }
        }
        cout << name << ": " << ans << endl;
    }
    return 0;
}
