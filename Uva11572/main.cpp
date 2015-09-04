/**
 * AC @ Sep 4th 2015
 * Run Time : 0.086s
 */
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value, pos;
    Node(int v, int p):value(v),pos(p){}
};

const int MAXN = 299993;
std::vector<Node> table[MAXN];

void init() {
    for (int i = 0; i < MAXN; ++i) {
        table[i].clear();
    }
}

int find(int value, int pos) {
    int v = value % MAXN;
    for (std::vector<Node>::iterator it = table[v].begin(); it != table[v].end(); ++it) {
        if (v == it->value) {
            int p = it->pos;
            it->pos = pos;
            return p;
        }
    }
    table[v].push_back(Node(value, pos));
    return 0;
}

void work() {
    int N;
    cin >> N;
    init();
    int maxC = -1, tmp, pos;
    int cur = 0; // the nearest duplicated position
    for (int i = 1; i <= N; ++i) {
        cin >> tmp;
        pos = find(tmp, i);
        cur = cur > pos ? cur : pos;
        maxC = maxC > i - cur ? maxC : i - cur;
    }
    cout << maxC << endl;
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