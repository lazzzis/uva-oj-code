/*
    UvaOJ 140
    Emerald
    Tue 4 Aug
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int MAXN = 26 + 5;
std::vector<int> link[MAXN];
std::vector<int> permu, ans;
int pos[MAXN]; // per : the permutation for print

void Read(string &in) {
    bool linked[MAXN][MAXN] = {false};
    for( size_t i = 0; i < in.length(); ++i ) {
        int ch = in[i] - 'A';
        i +=2; // over the char ':'
        while(i < in.length() && in[i] != ';') {
            linked[ch][in[i] - 'A'] = true;
            linked[in[i] - 'A'][ch] = true;
            i ++;
        }
    }
    for(int i = 0; i < MAXN; i ++) {
        link[i].clear();
        for(int j=0; j<MAXN; ++j)
            if(linked[i][j]) {
                link[i].push_back(j);
            }
    }
}        

void InitPos() {
    for(size_t i = 0; i < permu.size(); i ++) {
        pos[permu[i]] = i;
    }
}

int Abs(int s) {
    return s > 0 ? s : -s;
}

int main() {
    string in;
    while(cin >> in && in != "#") {
        Read(in);
        permu.clear();
        for(int i=0; i<MAXN; i++) {
            if(link[i].size()) {
                permu.push_back(i);
            }
        }
        int minWB = 1 << 20;
        do{
            InitPos();
            int tmpWB = -1, ok;
            for(size_t i = 0; i < permu.size(); i ++) {
                ok = 1;
                int x = permu[i], y;
                for(size_t j = 0; j < link[x].size(); ++ j) {
                    y = link[x][j];
                    if(Abs(pos[x] - pos[y]) > minWB || ceil(link[x].size()/2) > minWB) {
                        ok = 0;
                        break;
                    }
                    tmpWB = tmpWB > Abs(pos[x] - pos[y]) ? tmpWB : Abs(pos[x] - pos[y]);
                }
                if( !ok ) {
                    break;
                }
            }
            if( ok && minWB > tmpWB ) {
                minWB = tmpWB;
                ans = permu;
            }
        }while(next_permutation(permu.begin(), permu.end()));
        for(size_t i = 0; i < ans.size(); ++ i) {
            printf("%c ", ans[i] + 'A');
        }
        printf("-> %d\n", minWB);
    }
    return 0;
}