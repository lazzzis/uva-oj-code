/**
 * AC @ sep 4th 2015
 * Run Time : 0.279s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000 + 50;
std::vector<int> v, last;
std::map<int, int> cur;

void work() {
    int N;
    cur.clear();
    v.clear();
    last.clear();
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        last.push_back( !cur.count(v.back()) ? -1 : cur[v.back()] );
        cur[v.back()] = i;
    }
    int L = 0, R = 0, ans = 0;
    while (R < N) {
        while (R < N && last[R] < L) {
            R ++;
        }
        ans = max(ans, R - L);
        L ++;
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