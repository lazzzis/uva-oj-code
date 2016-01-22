
/**
 * AC @ Sep 9th 2015
 * Run Time : 0.000s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 50;
string name[MAXN], ans;
int N;

bool read() {
    cin >> N;
    if (!N) {
        return false;
    }
    for (int i = 0; i < N; ++i) {
        cin >> name[i];
    }
    return true;
}

bool dfs(int pos) {
    ans.append(1, '0');
    char start, limit;
    start = pos < name[N/2-1].length() ? name[N/2-1][pos] : 'A';
    limit = pos < name[N/2].length() ? name[N/2][pos] : 'Z';
    for (char c = start; c<=limit; ++ c) {
        ans[ans.length()-1] = c;
        if (ans >= name[N/2-1] && ans < name[N/2]) {
            return true;
        }
    }
    for (char c = start; c<=limit; ++ c) {
        ans[ans.length()-1] = c;
        if (dfs(pos + 1)) {
            return true;
        }
    }
    return false;
}

void work() {
    ans = "";
    sort(name, name + N);
    dfs(0);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (read()) {
        work();
    }
    return 0;
}
/**
 * Test case:
4
ACB 
ABC
ABB
ACC
2
ABAB
ABB
2 
ABABC
ABB
 */