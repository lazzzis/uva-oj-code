/**
 * AC @ Oct 20th 2015
 * Run Time : 0.865s
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> pr_int;

const int MAXN = 1000 + 50;
const int INF = 1 << 30;
int dp[MAXN][MAXN], L, value2pos[MAXN], N, sticks[MAXN];

void read() {
    cin >> N;
    for (int i = 1; i < N + 1; ++i) {
        cin >> sticks[i];
        // value2pos[t] = i;
    }
}

int cut(int b, int e) {
    if (dp[b][e] != -1) {
        return dp[b][e];
    }
    dp[b][e] = INF;
    for (int i = 1; i < N + 1; ++i) {
        if (sticks[i] >= b && sticks[i] < e) { // [b, e)
            dp[b][e] = min(dp[b][e], cut(b, sticks[i]) + cut(sticks[i] + 1, e) + (e - b + 1));
        }
    }
    dp[b][e] = dp[b][e] == INF ? 0 : dp[b][e]; // cut isn't done, so it's zero
    return dp[b][e];
}

void work() {
    read();
    memset(dp, -1, sizeof(dp));
    dp[1][L] = INF;
    for (int i = 1; i < N + 1; ++i) {
        dp[1][L] = min(dp[1][L], cut(1, sticks[i]) + cut(sticks[i] + 1, L) + L);
    }
    dp[1][L] = dp[1][L] == INF ? 0 : dp[1][L];
    cout << "The minimum cutting is " << dp[1][L] << "." << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> L && L) {
        work();
    }
    return 0;
}