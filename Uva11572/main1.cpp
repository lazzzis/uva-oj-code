/**
 * AC @ sep 4th 2015
 * Run Time : 0.249s
 */
#include <bits/stdc++.h>

using namespace std;

void work() {
    std::vector<int> v;
    set<int> s;
    int N, tmp;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        v.push_back(tmp);
    }
    int L = 0, R = 0, ans = 0;
    while (R < N) {
        while (R < N && !s.count(v[R])) {
            s.insert(v[R ++]);
        }
        ans = max(R - L, ans);
        s.erase(v[L ++]);
    }
    cout << ans << endl;
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