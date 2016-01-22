/*
 * AC @ Nov 25th 2015
 * Run Time : 0.369s
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> pr_int;

const int MAXN = 40 + 5;
int dpArr[MAXN][MAXN][MAXN][MAXN];
int pile[5][MAXN];

int dp(vector<int> v, int state, int basket_con) {
    if (basket_con == 5) {
        return 0;
    }
    if (dpArr[v[0]][v[1]][v[2]][v[3]] != -1) {
        return dpArr[v[0]][v[1]][v[2]][v[3]];
    }
    int ans = 0, flag;
    for (int i = 0; i < 4; ++ i) {
        if (v[i]) {
            vector<int> nv = v;
            flag = (1 << (pile[i + 1][v[i]] - 1)) & state;
            nv[i] -= 1;
            if (flag) {
                ans = max(dp(nv, state - flag, basket_con - 1) + 1, ans);
            } else {
                ans = max(dp(nv, state + (1 << (pile[i + 1][v[i]] - 1)), basket_con + 1), ans);
            }
        }
    }
    return dpArr[v[0]][v[1]][v[2]][v[3]] = ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while(cin >> N && N) {
        for (int i = N; i >= 1; -- i) {
            for(int j = 1; j < 5; ++ j){
                cin >> pile[j][i];
            }
        }
        memset(dpArr, -1, sizeof(dpArr));
        dpArr[0][0][0][0] = 0;
        vector<int> v;
        v.push_back(N);
        v.push_back(N);
        v.push_back(N);
        v.push_back(N);
        cout << dp(v, 0, 0) << endl;
    }
    return 0;
}
