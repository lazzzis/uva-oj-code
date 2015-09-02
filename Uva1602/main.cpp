#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10+2;
bool put[MAXN][MAXN];
int n, w ,h;
int counter;
int dir[4][2] = {0,1, 1,0, -1,0, 0, -1};

// bool IsBlock(int x, int y) {
//     for(int i=0; i<4; ++i) {
//         int r = x + dir[i][0], c = y + dir[i][1];
//         if(r>=0 && r<h && c>=0 && c<w && put[r][c]) {
//             return true;
//         }
//     }
//     return false;
// }

typedef pair<int, int> Node;
bool IsBlock(int x, int y) {
    bool vis[MAXN][MAXN] = {false};
    queue<Node> q;
    Node t = make_pair(x, y);
    q.push(t);
    vis[t.first][t.second] = true;
    int cnt = 0;
    while(!q.empty()) {
        t = q.front();
        q.pop();
        cnt ++;
        for(int i=0; i<4; ++i) {
            int r = t.first + dir[i][0];
            int c = t.second + dir[i][1];
            if(r>=0 && r<h && c>=0 && c<w && put[r][c] && !vis[r][c]) {
                vis[r][c] = true;
                q.push(make_pair(r, c));
            }
        }
    }
    return cnt == n;
}

bool IsHash() {
    
    return false;
}

void Dfs(int x, int y, int c) {
    if( w * h - (x * w + y + 1) < (n - c - 1) ) {
        return ;
    }
    if(x >= h) {
        return ;
    }
    put[x][y] = true;
    // if(c && !IsBlock(x, y)) {
    //     put[x][y] = false;
    //     return ;
    // }
    if(IsHash()) {
        
    } else if(c + 1 == n && IsBlock(x, y)) {
        counter ++;
    } else {
        if(y == w - 1 ) {
            Dfs(x+1, 0, c + 1);
        } else {
            Dfs(x, y + 1, c + 1);
        }
    }
    put[x][y] = false;
    if(y == w - 1 ) {
        Dfs(x+1, 0, c);
    } else {
        Dfs(x, y + 1, c);
    }
}

void Solve() {
    Dfs(0, 0, 0);
}

int main() {
    while(cin >> n >> w >> h) {
        counter = 0;
        Solve();
        cout << counter << endl;
    }
    return 0;
}