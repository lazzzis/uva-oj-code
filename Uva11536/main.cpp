/**
 * AC @ Sep 11th 2015
 * Run Time : 0.739s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 50;
int var[MAXN*1000];
int Case = 0;
int N, M, K;

void init() {
    for (int i = 1; i <= 3; ++i) {
        var[i] = i;
    }
    int sum = 6;
    for (int i = 4; i <=N ; ++i) {
        var[i] = sum % M + 1;
        sum -= var[i-3];
        sum += var[i];
    }
}

void done() {
    int pos[MAXN] = {0};
    int counter = 0;
    for (int i = 1; i <= N && counter < K; ++i) {
        if (var[i] >= 1 && var[i] <= K && !pos[var[i]]) {
            ++ counter;
        }
        pos[var[i]] = max(pos[var[i]], i);
    }
    if (counter < K) {
        cout << "Case " << (++Case) <<  ": sequence nai" << endl;
        return ;
    }
    int minPos = MAXN * 1000, maxPos = -1;
    for (int i = 1; i <= K; ++i) {
        minPos = min(minPos, pos[i]);
        maxPos = max(maxPos, pos[i]);
    }
    int ans = maxPos - minPos + 1;
    for (int i = 1; i <= N; ++i) {
        if (var[i] >= 1 && var[i] <= K) {
            if (pos[var[i]] == minPos || pos[var[i]] == maxPos || i > maxPos) {
                pos[var[i]] = i;
                minPos = MAXN * 1000, maxPos = -1;
                for (int j = 1; j <= K; ++j) {
                    minPos = min(minPos, pos[j]);
                    maxPos = max(maxPos, pos[j]);
                }
                ans = min(ans, maxPos - minPos + 1);
            }
        }
    }
    cout << "Case " << (++Case) <<  ": " << ans << endl;
}

void work() {
    cin >> N >> M >> K;
    init();
    done();
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