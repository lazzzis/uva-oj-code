/**
 * AC @ 2015 21st Nov
 * Run Time : 0.662s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = (1 << 8) + 100;
const int INF = (1 << 28) + 100;
int S, M, N;
int d[MAXN][MAXN][MAXN];
int cost[MAXN], sub[MAXN];

int dp(int i, int s0, int s1, int s2) {
    if (i == M + N) {
        return s2 == (1 << S) - 1 ? 0 : INF;
    }
    int& ans = d[i][s1][s2];
    if (ans != -1) {
        return ans;
    }
    ans = INF;
    if (i >= M) {
        ans = dp(i + 1, s0, s1, s2);
    }
    int m0 = sub[i] & s0, m1 = sub[i] & s1;
    s0 = s0 ^ m0;
    s1 = (s1 ^ m1) | m0;
    s2 = s2 | m1;
    ans = min(ans, cost[i] + dp(i + 1, s0, s1, s2));
    return ans;
}

void read() {
    int t;
    cin.get();
    for (int i = 0; i < M + N; ++ i) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        ss >> cost[i];
        sub[i] = 0;
        while(ss >> t) {
            sub[i] = sub[i] | (1 << (t - 1));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> S >> M >> N) {
        if (S == 0) {
            break;
        }
        read();
        memset(d, -1, sizeof(d));
        cout << dp(0, (1 << S) - 1, 0, 0) << endl;
    }
    return 0;
}
