#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 26 + 5;
std::vector<int> permu, ans, link[MAXN];

void Link(string &s) {
    int isLink[MAXN][MAXN] = {false};
    size_t pos = 0;
    while(pos < s.size()) {
        int head = s[pos] - 'A';
        pos += 2; // jump over :
        while(pos < s.size() && s[pos] != ';') {
            isLink[head][s[pos] - 'A'] 
                = isLink[s[pos] - 'A'][head] = true;
            ++ pos;
        }
        ++ pos; // jump over ';'
    }
    for(int i=0; i<MAXN; ++ i) {
        link[i].clear();
        for(int j = 0; j < MAXN; ++ j) {
            if(isLink[i][j]) {
                link[i].push_back(j);
            }
        }
    }
}

int Abs(int s) {
    return s > 0 ? s : -s;
}

int minBW;
int GetBW() {
    int pos[MAXN];
    for(size_t i = 0; i < permu.size(); ++ i) {
        pos[permu[i]] = i;
    }
    int maxBW = -1;
    for(size_t i = 0; i < permu.size(); ++ i) {
        int tmp = -1;
        int order = permu[i];
        if( ceil(link[order].size() / 2.0) > minBW ) {
            return 1 << 10;
        }
        for(size_t j = 0; j < link[order].size(); ++ j) {
            int dis = Abs(pos[link[order][j]] - i);
            if(dis > minBW) {
                return 1 << 10;
            }
            tmp = tmp > dis ? tmp : dis;
        }
        maxBW = maxBW > tmp ? maxBW : tmp;
    }
    return maxBW;
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    while(cin >> s && s != "#") {
        Link(s);
        permu.clear();
        for(int i=0; i<MAXN; ++ i) {
            if(link[i].size()) {
                permu.push_back(i);
            }
        }
        minBW = 1 << 10;
        do{
            int value = GetBW();
            if(minBW > value) {
                minBW = value;
                ans = permu;
            }
        }while(next_permutation(permu.begin(), permu.end()));
        for(size_t i = 0; i < ans.size(); ++ i) {
            cout << char(ans[i]+'A') << " ";
        }
        cout << "-> " << minBW << endl;
    }
    return 0;
}