/**
 * AC @ Oct 9th 2015
 * Run Time : 0.016s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 50;
bool is_par[MAXN][MAXN];
string str;
int dp[MAXN];

void init_is_par() {
    memset(is_par, false, sizeof(is_par));
    int len = (int) str.length();
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (i - j < 0 || i + j >= len || str[i - j] != str[i + j]) {
                break;
            }
            is_par[i - j][i + j] = true;
        }
        for (int j = 0; j < len; ++j) {
            if (i - j < 0 || i + 1 + j >= len || str[i - j] != str[i + 1 + j]) {
                break;
            }
            is_par[i - j][i + 1 + j] = true;
        }
    }
}

void work() {
    cin >> str;
    init_is_par();
    dp[0] = 1;
    int len = (int) str.length();
    for (int i = 1; i < len; ++i) {
        dp[i] = is_par[0][i] ? 1 : i + 1;
        for (int j = 1; j <= i; ++j) {
            if (is_par[j][i]) {
                dp[i] = min(dp[j - 1] + 1, dp[i]);
            }
        }
    }
    cout << dp[len - 1] << endl;
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