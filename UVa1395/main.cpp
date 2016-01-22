/*
 * AC @ 22nd Jan 2016
 * Run Time : 0.033s
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int first, second;
    int len;
};

bool cmp(Node a, Node b) {
    return a.len < b.len;
}

const int INF = 1000000;
const int MAXN = 100 + 50;
int N, M;
vector<Node> nodes;
int size[MAXN], root[MAXN];

void read() {
    int a, b, k;
    nodes.clear();
    for (int i = 0; i < M; ++ i) {
        cin >> a >> b >> k;
        Node n;
        n.first = a; n.second = b; n.len = k;
        nodes.push_back(n);
    }
}

int ans;

int Find(int n) {
    if (root[n] == n) {
        return n;
    }
    return root[n] = Find(root[n]);
}

void work() {
    sort(nodes.begin(), nodes.end(), cmp);
    ans = INF;
    for (int i = 0, j; i < M; ++ i) {
        for (j = 1; j <= N; ++ j) {
            size[j] = 1;
            root[j] = j;
        }
        for (j = i; j < M; ++ j) {
            int ra = Find(nodes[j].first);
            int rb = Find(nodes[j].second);
            if (ra != rb) {
                root[rb] = ra;
                size[ra] += size[rb];
            }
            if (size[Find(1)] == N) {
                break;
            }
        }
        if (size[Find(1)] == N) {
            ans = min(nodes[j].len - nodes[i].len, ans);
        } else if (size[Find(1)] < N) {
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> N >> M && (N + M)) {
        read();
        work();
        cout << (ans == INF ? -1 : ans) << endl;
    }
    return 0;
}
