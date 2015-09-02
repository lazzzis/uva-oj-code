#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10 + 3;
bool vis[MAXN][MAXN];
char plan[MAXN][MAXN];
int M, N, Guard, maxD;
int dir[8][2] = {0,1, 1,0, 0,-1, -1,0, 1,1, 1,-1, -1,1, -1,-1};

bool Init() {
    Guard = 0;
    memset(vis, false, sizeof(vis));
    return true;
}

}

bool Read() {
    cin >> M;
    if(!M)  return false;
    cin >> N;
    for(int i=0; i<M; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> plan[i][j];
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(Init() && Read()) {

    }
    return 0;
}