/**
 * AC @ Sep 30th 2015
 * Run Time : 0.000s
 */
#include <bits/stdc++.h>

using namespace std;

const int INF = 65535;
int t[50 + 5]; // t[i] the time from i to i + 1
bool has_train[200 + 100][50 + 10][2]; // 0 : to right, 1 : to left
// time, station
int dp[200 + 10][50 + 10];

int N, T; 

void read() {
    cin >> T;
    for (int i = 0; i < N - 1; ++i) {
        cin >> t[i + 1];
    }
    int M;
    int tim;
    memset(has_train, false, sizeof(has_train));
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> tim; // time is up to 250 (included)
        has_train[tim][1][0] = true;
        for (int j = 1; j < N && tim + t[j] <= T; ++j) {
            tim += t[j];
            has_train[tim][j + 1][0] = true;
        }
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> tim;
        has_train[tim][N][1] = true;
        for (int j = N - 1; j > 0 && tim + t[j] <= T; --j) {
            tim += t[j];
            has_train[tim][j][1] = true;
        }
    }
}

int Case = 0;
void work() {
    read();
    for (int i = 1; i < N; ++i) {
        dp[T][i] = INF;
    }
    dp[T][N] = 0;
    for (int i = T - 1; i >= 0; --i) {
        for (int j = 1; j <= N; ++j) {
            dp[i][j] = dp[i + 1][j] + 1;
            if (j < N && has_train[i][j][0] && i + t[j] <= T) { // right
                dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);
            }
            if (j > 1 && has_train[i][j][1] && i + t[j - 1] <= T) { // left
                dp[i][j] = min(dp[i][j], dp[i + t[j-1]][j - 1]);
            }
        }
    }
    cout << "Case Number " << (++Case) << ": ";
    if (dp[0][1] >= INF) {
        cout << "impossible" << endl;
    } else {
        cout << dp[0][1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> N && N) {
        work();
    }
    return 0;
}