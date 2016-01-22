/**
 * AC @ Sep 12th 2015
 * Run Time : 0.113s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10e6 + 50;
int ceil_h[MAXN], floor_h[MAXN], N;
int h1[MAXN], h2[MAXN];

void read() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> floor_h[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> ceil_h[i];
    }
}

void work() {
    int level = ceil_h[0];
    for (int i = 0; i < N; ++i) {
        if (floor_h[i] > level) {
            level = floor_h[i];
        } else if (ceil_h[i] < level) {
            level = ceil_h[i];
        }
        h1[i] = level;
    }
    level = ceil_h[N-1];
    for (int i = N - 1; i >=0; --i) {
        if (floor_h[i] > level) {
            level = floor_h[i];
        } else if (ceil_h[i] < level) {
            level = ceil_h[i];
        }
        h2[i] = level;
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = ans + min(h1[i], h2[i]) - floor_h[i];
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T --) {
        read();
        work();
    }
    return 0;
}