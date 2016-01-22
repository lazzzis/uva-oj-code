/**
 * AC @ Sep 9th 2015
 * Run Time : 0.536s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300 + 50;
int N, pos[MAXN];
std::vector<int> v, ans, per;

void output() {
    for (int j, i = 0; i < (int)ans.size(); ++i) {
        if (ans[i] == 2) {
            for (j = 0; j < N && (i + j) < (int)ans.size(); ++ j) {
                if (ans[i + j] == 1) {
                    break;
                }
            }
            if (j == N) {
                for (int j = 0; j < N; ++j) {
                    ans.erase(ans.begin() + i);
                }
            } else {
                i += j;
            }
        }
    }
    for (std::vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
        cout << *it;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> N && N) {
        v.clear();
        per.clear();
        int tmp;
        for (int i = 0; i < N; ++i) {
            cin >> tmp;
            v.push_back(i+1);
            per.push_back(tmp);
        }
        ans.clear();
        for (int i = N-2; i >= 0; --i) {
            while (v[0] != per[i]) {
                v.push_back(v[0]);
                v.erase(v.begin());
                ans.push_back(2);
            }
            while (v[1] != per[i + 1]) {
                v.push_back(v[1]);
                v.erase(v.begin() + 1);
                ans.push_back(1);
                ans.push_back(2);
            }
            for (int j = i; j < N ; ++ j) {
                v.push_back(v[0]);
                v.erase(v.begin());
                ans.push_back(2);
            }
        }
        output();
    }
    return 0;
}