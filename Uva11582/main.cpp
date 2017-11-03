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

int N;
int dp[1000 + 50];
int p[1000 + 50][1000 + 50];
int vis[1000 + 50][1000 + 50];
std::vector<vector<int>> v[30];
string str;

int isPad (int s, int t) {
    if (s >= t) return 1;
    if (vis[s][t]) return p[s][t];
    vis[s][t] = 1;
    if (str[s] != str[t]) p[s][t] = 0;
    else p[s][t] = isPad(s + 1, t - 1);
    return p[s][t];
}

int solve () {
    memset(p, 0, sizeof(p));
    memset(vis, 0, sizeof(vis));
    dp[0] = 0;
    for (int i = 1; i < str.length() + 1; i++) {
        dp[i] = 999 * 9999;
        for (int j = 0; j < i; j++) {
            dp[i] = min(
                dp[i],
                dp[j] + (isPad(j, i - 1) ? 1 : i - j)
            );
        }
    }
    return dp[str.length()];
}

int main(int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
    // string cwd = GetCurrentWorkingDir() + "/test.in";
    // freopen(cwd.c_str(), "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    while (N --) {
        cin >> str;
        cout << solve() << endl;
    }
}
