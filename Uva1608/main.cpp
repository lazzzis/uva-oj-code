/**
 * AC @ Sep 7th 2015
 * Run Time : 0.432s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000 + 50;
int num[MAXN], left_pos[MAXN], right_pos[MAXN];
int N;

void left_near() {
    std::map<int, int> cur;
    for (int i = 1; i < N + 1; ++i) {
        left_pos[i] = !cur.count(num[i]) ? 0 : cur[num[i]];
        cur[num[i]] = i;
    }
}

void right_near() {
    std::map<int, int> cur;
    for (int i = N; i > 0; --i) {
        right_pos[i] = !cur.count(num[i]) ? N + 2 : cur[num[i]];
        cur[num[i]] = i;
    }
}

bool is_unique(int d, int l, int r) {
    return left_pos[d] < l && right_pos[d] > r;
}

bool dfs(int l, int r) {
    if (r <= l) {
        return true;
    }
    for (int d = 0; l + d <= r - d; ++ d) {
        if (is_unique(l+d, l, r)) {
            return dfs(l, l+d-1) && dfs(l+d+1, r);
        }
        if (l+d == r-d) {
            break;
        }
        if (is_unique(r-d, l, r)) {
            return dfs(l, r-d-1) && dfs(r-d+1, r);
        }
    }
    return false;
}

void work() {
    cin >> N;
    for (int i = 1; i < N + 1; ++i) {
        cin >> num[i];
    }
    left_near();
    right_near();
    if (dfs(1, N)) {
        cout << "non-boring" << endl;
    } else {
        cout << "boring" << endl;
    }
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