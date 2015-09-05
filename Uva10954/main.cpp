/**
 * AC @ Sep 5th 2015
 * Run Time : 0.006s
 */
#include <bits/stdc++.h>

using namespace std;

int N;

void work() {
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    int ans = 0, a, b;
    while (q.size() > 1) {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        ans = ans + a + b;
        q.push(a + b);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> N && N) {
        work();
    }
    return 0;
}