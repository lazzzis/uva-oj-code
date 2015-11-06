/**
 * AC @ 2015 Nov 6th
 * Run Time : 0.000s
 */
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 200 + 50;
int N;
int boss[MAXN];
map<string, int> id_map;
vector<int> son[MAXN];
int dp[MAXN][2], f[MAXN][2];

void init() {
    id_map.clear();
    for(int i = 0; i < N + 1; ++ i) {
        son[i].clear();
    }
}

int get_id(string name) {
    if(id_map.count(name)) {
        return id_map[name];
    }else {
        int s = id_map.size();
        id_map[name] = s;
        return s;
    }
}

int search(int order, int flag) {
    //cout << order << " " << son[order].size() << endl;
    if (dp[order][flag] != -1) {
        return dp[order][flag];
    }
    if(son[order].size() == 0) { // the work
        f[order][flag] = 1; // must be unique
        return dp[order][flag] = flag;
    }
    int ans;
    int unique = 1; // suppose it's unique
    if(flag) { // 1
        ans = 1;
        for(int i = 0; i < (int)son[order].size(); ++i){
            ans = ans + search(son[order][i], 0);
            unique = unique && f[son[order][i]][0];
        }
    } else { // 0
        ans = 0;
        for(int i = 0; i < (int)son[order].size(); ++i){
            int zero = search(son[order][i], 0), one = search(son[order][i], 1);
            if(zero == one) {
                ans += zero;
                unique = 0;
            } else if (zero > one) {
                ans += zero;
                unique = unique && f[son[order][i]][0];
            }else if(one > zero) {
                ans += one;
                unique = unique && f[son[order][i]][1];
            }
        }
    }
    f[order][flag] = unique;
    return dp[order][flag] = ans;
}

void work() {
    init();
    string name, boss_name;
    cin >> boss_name;
    get_id(boss_name);
    for(int i = 0; i < N - 1; i ++) {
        cin >> name >> boss_name;
       // boss[get_id(name)] = get_id(boss_name);
        son[get_id(boss_name)].push_back(get_id(name));
    }
    memset(dp, -1, sizeof(dp));
    memset(f, 1, sizeof(f));
    int unique, ans;
    // equal: so there exists at least two choices
    if (search(0, 0) == search(0, 1)) {
        ans = search(0, 0);
        unique = 0;
    } else if (search(0, 0) > search(0, 1)) {
        ans = search(0, 0);
        unique = f[0][0];
    } else {
        ans = search(0 ,1);
        unique = f[0][1];
    }
    cout << ans << " ";
    if (unique) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);    
    cin.tie(0);
    while(cin >> N && N) {
        work();       
    }
    return 0;
}
