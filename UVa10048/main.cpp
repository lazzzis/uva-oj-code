/**
 * AC @ 23rd Jan 2016
 * Run Time : 0.015s
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int INF = 1000000;
const int MAXN = 100 + 50;
int dis[MAXN][MAXN];
int C, S, Q;

void init() {
    for (int i = 0; i < MAXN; ++ i) {
        for (int j = 0; j < MAXN; ++ j) {
            dis[i][j] = INF;
        }
    }
}

void read() {
    int s, t, p;
    for (int i = 0; i < S; ++ i) {
        cin >> s >> t >> p;
        dis[s][t] = dis[t][s] = p;
    }
}

void floyd() {
    for (int k = 1; k < C + 1; ++ k) {
        for (int i = 1; i < C + 1; ++ i) {
            for (int j = 1; j < C + 1; ++ j) {
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 0;
    while(cin >> C >> S >> Q && (C + S + Q)) {
        if (Case) {
            cout << endl;
        }
        init();
        read();
        floyd();
        cout << "Case #" << (++ Case) << endl;
        int s, t;
        for (int i = 0; i < Q; ++ i) {
            cin >> s >> t;
            if (dis[s][t] == INF) {
                cout << "no path" << endl;
            } else {
                cout << dis[s][t] << endl;
            }
        }
    }
    return 0;
}
