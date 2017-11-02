#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <unordered_set>
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

using namespace std;

#ifndef ONLINE_JUDGE
std::string GetCurrentWorkingDir( void ) {
  char buff[10000];
  GetCurrentDir( buff, 10000 );
  std::string current_working_dir(buff);
  return current_working_dir;
}
#endif

#define REP(i,n) for(int i = 0; i < (n); i++)
#define REPS(i,s,n) for(int i = (s); i < (n); i++)

struct Node {
    int v, k, c, l;
};

Node createNode (int v, int k, int c, int l) {
    Node n;
    n.v = v; n.k = k; n.c = c; n.l = l;
    return n;
}

int N;
int vis[1000 + 50][1000 * 100 + 5];
Node nodes[1000 + 5];

int solve (int n, int num) {
    if (vis[n][num] != -1) {
        return vis[n][num];
    }
    if (n == N - 1) {
        vis[n][num] = nodes[n].c * (num + nodes[n].l) + nodes[n].k;
        return vis[n][num];
    }
    vis[n][num] = min(
        solve(n + 1, num + nodes[n].l),
        solve(n + 1, 0) + nodes[n].k + (num + nodes[n].l) * nodes[n].c
    );
    // cout << n << " " << num << " " << vis[n][num] << endl;
    return vis[n][num];
}

int main(int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    // string cwd = GetCurrentWorkingDir() + "/test.in";
    // freopen(cwd.c_str(), "r", stdin);
    #endif
    while (cin >> N && N) {
        REP (i, N) {
            int v, k, c, l;
            cin >> v >> k >> c >> l;
            nodes[i] = createNode(v, k, c, l);
        }
        sort(nodes, nodes + N, [] (Node& a, Node& b) {
            return a.v < b.v;
        });

        memset(vis, -1, sizeof(vis));
        cout << solve(0, 0) << endl;
    }
}
