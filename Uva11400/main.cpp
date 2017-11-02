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
int dp[1000 + 50];
Node nodes[1000 + 5];

int solve () {
    for (int i = 0; i < N; i ++) {
        dp[i] = 99999999;
    }
    dp[0] = nodes[0].k + nodes[0].c * nodes[0].l;
    for (int i = 1; i < N; i ++) {
        int total = 0;
        for (int j = i - 1; j >= 0; j--) {
            total += nodes[j + 1].l;
            dp[i] = min(dp[i], dp[j] + total * nodes[i].c + nodes[i].k);
        }
        total += nodes[0].l;
        dp[i] = min(dp[i], 0 + total * nodes[i].c + nodes[i].k);
    }
    return dp[N - 1];
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

        cout << solve() << endl;
    }
}
