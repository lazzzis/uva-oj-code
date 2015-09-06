/**
 * AC @ Sep 6th 2015
 * Run Time : 0.103s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100001 + 50;
int N;
int add[MAXN], sub[MAXN];

int is_possible(int start) {
    int gas = 0;
    for (int i = start; i < N + start; ++i) {
        gas += add[i % N];
        gas -= sub[i % N];
        if (gas < 0) {
            return i % N + 1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, Case = 0;
    cin >> T;
    while (T --) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> add[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> sub[i];
        }
        int pos = -1, ans = -1;
        for (int i = 0; i < N; ++i) {
            pos = is_possible(i);
            if (pos == -1 ) {
                ans = i;
                break;
            } else if (pos > i){
                i = pos - 1;
            } else if (pos < i) {
                break;
            }
        }
        if (ans == -1) {
            cout << "Case " << (++ Case) <<": Not possible" << endl;
        } else {
            cout << "Case " << (++ Case) <<": Possible from station " << ans + 1 << endl;
        }
    }
    return 0;
}