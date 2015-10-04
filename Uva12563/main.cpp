/**
 * AC @ Oct 4th 2015
 * Run Time : 0.006s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 180 * 50 + 100;
int N, T, dp[MAXN];

int Case = 0;
void work() {
    cin >> N >> T;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int t;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        for (int j = min(MAXN - 50, T); j >= t; --j) {
            if (dp[j - t] != -1 && dp[j - t] + 1 > dp[j]) {
                dp[j] = dp[j - t] + 1;
            }
        }
    }
    int max_ans = -1, pos = 0;
    for (int i = 0; i < min(T, MAXN); ++i) {
        if (max_ans <= dp[i]) {
            max_ans = dp[i];
            pos = i;
        }
    }
    cout << "Case " << (++ Case) << ": " << (max_ans + 1) << " " << (pos + 678) << endl;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T --) {
        work();
    }
    return 0;
}