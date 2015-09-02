#include <bits/stdc++.h>

using namespace std;

const int MAXN = 7 + 3;
char chess[MAXN][MAXN];
int point[MAXN][MAXN];
bool link[MAXN][MAXN][MAXN][MAXN];
int N;
int go[4][2] = {1,1, 1,-1,  -1,-1, -1,1};

void Read() {
    for(int i=0; i<N+1; ++ i) {
        for(int j=0; j<N+1; ++ j) {
            cin >> chess[i][j];
        }
    }
}

// whether the chess forms an enclosed loop
bool vis[MAXN][MAXN];
bool found;
void Loop(int x, int y, int a, int b) {
    if(found || x<0 || x>N || y<0 || y>N || !link[x][y][a][b] ) {
        return ;
    }
    if(vis[x][y]) {
        found = true;
        return ;
    }
    vis[x][y] = true;
    for(int i=0; i<4; ++i) {
        if( x+go[i][0]!=a || y+go[i][1]!=b ) {
            Loop(x+go[i][0], y+go[i][1], x, y);
        }
    }
}

// the preparsion before Loop
bool Any(int x, int y) {
    memset(vis, false, sizeof(vis));
    found = false;
    vis[x][y] = true;
    Loop(x+1, y+1, x, y);
    Loop(x-1, y-1, x, y);
    Loop(x-1, y+1, x, y);
    Loop(x+1, y-1, x, y);
    return !found;
}

// the r, c means the left-up corner of a grid
bool Dfs(int r, int c) {
    if(c == N) {
        if(isdigit(chess[r][c]) && point[r][c] != chess[r][c] - '0') {
            return false;
        }
        ++ r; c = 0;
        if(r == N) {
            for(int i=0; i<N+1;i++) {
                if(isdigit(chess[r][i]) && point[r][i] != chess[r][i] - '0') {
                    return false;
                }
            }
            return true;
        } else {
            return Dfs(r, c);
        }
    }

    // put '\'
    int x = r, y = c;
    point[x][y] ++;
    point[x+1][y+1] ++;
    link[x][y][x+1][y+1] = true;
    link[x+1][y+1][x][y] = true;
    if( isdigit(chess[x][y]) && point[x][y] != chess[x][y] - '0') {
        ;
    } else if(isdigit(chess[x+1][y+1]) && point[x+1][y+1] > chess[x+1][y+1] - '0') {
        ;
    } else if(Any(x, y)) {
        ++ y;
        if(Dfs(x, y)) {
            return true;
        }
    }
    x = r, y =c;
    link[x][y][x+1][y+1] = false;
    link[x+1][y+1][x][y] = false;
    point[x][y] --;
    point[x+1][y+1] --;

    // put /
    point[x][y+1] ++;
    point[x+1][y] ++;
    link[x][y+1][x+1][y] = true;
    link[x+1][y][x][y+1] = true;
    if( isdigit(chess[x][y]) && point[x][y] != chess[x][y] - '0') {
        ;
    } else if(isdigit(chess[x][y+1]) && point[x][y+1] > chess[x][y+1] - '0') {
        ;
    } else if(isdigit(chess[x+1][y]) && point[x+1][y] > chess[x+1][y] - '0') {
        ;
    } else if(Any(x, y+1)) {
        ++ y;
        if(Dfs(x, y)) {
            return true;
        }
    }
    x = r, y =c;
    link[x][y+1][x+1][y] = false;
    link[x+1][y][x][y+1] = false;
    point[x][y+1] --;
    point[x+1][y] --;
    return false;
}

void Work() {
    memset(point, 0, sizeof(point));
    memset(link, false, sizeof(link));
    Dfs(0 ,0);
}

void Print() {
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if(point[i][j] && point[i+1][j+1] && link[i][j][i+1][j+1]) {
                cout << "\\";
            } else {
                cout << "/";
            }
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) {
        cin >> N;
        Read();
        Work();
        Print();
    }
    return 0;
}