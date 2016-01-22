/**
 * Time Limit Exceeded @ Sep 6th 2015
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int K, A, B;
LL blue;

void dfs(int x, int y, int len) {
    // cout << x << " " << y << " " << len << endl;
    if (len == 1) {
        return ;
    }
    int w = len >> 1;
    if (y + w > A && y <= B) {
        dfs(x, y, w);
        dfs(x + w, y, w);
    }
    if (y + w <= B && A < y + len) {
        int a = max(y + w, A);
        int b = min(y + len - 1, B);
        blue = blue + (b - a + 1) * w;
        // cout << a << "   " << b << "   " << w << endl;
        dfs(x, y + w, w);
        // dfs(x + w, y + w, w);
    }

}

LL work() {
    int len = 1 << K;
    blue = 0;
    dfs(0, 0, len);
    return len * (B - A + 1) - blue;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, Case = 0;
    cin >> T;
    while (T --) {
        cin >> K >> A >> B;
        A --;
        B --;
        cout << "Case " << (++ Case) <<": " << work() << endl;
    }
    return 0;
}