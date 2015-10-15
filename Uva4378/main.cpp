/**
 * AC @ Oct 15th 2015
 * Run Time : 0.119
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 100000 + 50;
int N, op[MAXN];
struct Node {
    int value, pos;
};

void work() {
    std::vector<Node> v;
    LL sum = 0;
    Node t;
    for (int i = 1; i <= N; ++i) {
        cin >> t.value;
        t.pos = i;
        v.push_back(t);
        sum += t.value;
    }
    if (sum & 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        sum /= 2;
        for (int i = N - 1; i >= 0; --i) {
            if (sum >= v[i].value) {
                op[v[i].pos] = 1;
                sum -= v[i].value;
            } else {
                op[v[i].pos] = -1;
            }
        }
        for (int i = 1; i < N; ++i) {
            cout << op[i] << " ";
        }
        cout << op[N] << endl;
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> N) {
        work();
    }
    return 0;
}