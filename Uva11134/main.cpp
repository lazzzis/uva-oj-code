/**
 * AC @ Sep 4th 2015
 * Run Time : 0.009s
 */
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int xl, xr, yl, yr;
    int x, y, order;
};

// global
const int MAXN = 5000 + 50;
int N;
std::vector<Node> v;

bool read() {
    cin >> N;
    if (N == 0) {
        return false;
    }
    v.clear();
    Node t;
    for (int i = 0; i < N; ++i) {
        cin >> t.xl >> t.yl >> t.xr >> t.yr;
        t.order = i;
        v.push_back(t);
    }
    return true;
}

bool cmp_x(Node &a, Node &b) {
    return a.xr < b.xr || (a.xr == b.xr && a.xl < b.xl);
}
// bool cmp_x(Node &a, Node &b) {
//     return a.xl < b.xl || (a.xl == b.xl && a.xr < b.xr);
// }
// this function is wrong used for sorting in this problem
// cmp the r first, then l

bool cmp_y(Node &a, Node &b) {
    return a.yr < b.yr || (a.yr == b.yr && a.yl < b.yl);
}

bool cmp_order(Node &a, Node &b) {
    return a.order < b.order;
}

bool is_possile() {
    bool vis[MAXN] = {false};
    sort(v.begin(), v.end(), cmp_x);
    for (int i = 0; i < N; ++i) {
        int l = v[i].xl, r = v[i].xr;
        while (l <= r && vis[l]) {
            ++l;
        }
        if (l > r) {
            return false;
        }
        vis[l] = true;
        v[i].x = l;
    }
    sort(v.begin(), v.end(), cmp_y);
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < N; ++i) {
        int l = v[i].yl, r = v[i].yr;
        while (l <= r && vis[l]) {
            ++l;
        }
        if (l > r) {
            return false;
        }
        vis[l] = true;
        v[i].y = l;
    }
    return true;
}

void output() {
    sort(v.begin(), v.end(), cmp_order);
    for (std::vector<Node>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << it->x << " " << it->y << endl;
    }
}

void work() {
    if(is_possile() == false) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        output();
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (read()) {
        work();
    }
    return 0;
}