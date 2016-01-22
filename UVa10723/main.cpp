#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 30 + 5;
int d[MAXN][MAXN], vis[MAXN][MAXN];
string str1, str2;
set<string> s[MAXN][MAXN];

int dp(int pos1, int pos2, string str) {
    if (d[pos1][pos2] && str.length() > d[pos1][pos2]) {
        return ;
    }
    if (str1[pos1] == str2[pos2]) {
        if (!s[pos1][pos2].count(str + str1[pos1])) {
            if (d[pos1][pos2] == 0) {
                d[pos1][pos2] = str.length() + 1;
            } else if (d[pos1][pos2] > str.length() + 1 ) {
                d[pos1][pos2] = str.length() + 1;
                s.clear();
            }
            s.insert(str + str1[pos1]);
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int _ = 0; _ < T; ++ _) {
        cin >> str1 >> str2;
        memset(vis, 0, sizeof(vis));
        dp(0, 0);
        int ans1 = str1.size() + str2.size() - d[str1.size() - 1][str2.size() - 1];
        s.clear();
        maxLen = ans1;
        srh(0, 0, "", d[str1.size() - 1][str2.size() - 1]);
        cout << "Case #" << (_ + 1) << ": " << ans1 << " " << s.size() << endl;
    }
    return 0;
}
