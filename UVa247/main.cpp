/**
 * AC @ 22nd Jan 2015
 * Run Time : 0.016s
 */
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 25 + 5;
int N, M;
int d[MAXN][MAXN];
int root[MAXN];

map<string, int> mapId;
map<int, string> mapId2Str;
vector<string> circles[MAXN];

int getId(string str) {
    if (mapId.count(str)) {
        return mapId[str];
    } else {
        int s = mapId.size();
        mapId[str] = s;
        mapId2Str[s] = str;
        return s;
    }
}

void init() {
    mapId.clear();
    mapId2Str.clear();
    memset(d, 0, sizeof(d));
    for (int i = 0 ; i < MAXN; ++ i) {
        circles[i].clear();
        root[i] = i;
        d[i][i] = 1;
    }
}

void read() {
    string caller, callee;
    for (int i = 0; i < M; ++ i) {
        cin >> caller >> callee;
        d[getId(caller)][getId(callee)] = 1;
    }
}

void link() {
    for (int k = 0; k < N; ++ k) {
        for (int i = 0; i < N; ++ i) {
            for (int j = 0; j < N; ++ j) {
                d[i][j] = d[i][j] ||  (d[i][k] && d[k][j]);
            }
        }
    }
}

int Find(int n) {
    if (root[n] == n) {
        return n;
    }
    return root[n] = Find(root[n]);
}

void newlink() {
    for (int i = 0; i < N; ++ i) {
        for (int j = 0; j < N; ++ j) {
            if (d[i][j] && d[j][i]) {
                int ra = Find(i), rb = Find(j);
                if (ra != rb) {
                    root[ra] = rb;
                }
            }
        }
    }
}

void work() {
    for (int i = 0; i < N; ++ i) {
        int r = Find(i);
        circles[r].push_back(mapId2Str[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 0;
    while (cin >> N >> M && (N + M)) {
        if (Case) {
            cout << endl;
        }
        init();
        read();
        link();
        newlink();
        work();
        cout << "Calling circles for data set " << (++ Case) << ":" << endl;
        for (int i = 0; i < N; ++ i) {
            if (circles[i].size()) {
                cout << circles[i][0];
                for (int j = 1; j < (int) circles[i].size(); ++ j) {
                    cout << ", " << circles[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
