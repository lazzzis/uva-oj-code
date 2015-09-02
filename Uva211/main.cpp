/*
    UvaOJ 211
    Emerald
    Sun 9 Aug 2015
 */
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Point;

const int MAXN = 6 + 2;
vector<Point> point[MAXN];
int plan[MAXN][MAXN], // the grid
    path[550][MAXN][MAXN]; // the ans to be printed
bool vis[MAXN][MAXN];
int c;
int dir[4][2] = {0,1, 1,0, 0,-1, -1,0};

bool Init() {
    c = 0;
    memset(vis, false, sizeof(vis));
    for(int i=0; i<MAXN; ++i) {
        point[i].clear();
    }
    return true;
}

bool Read() {
    for(int i=0; i<7; ++i) {
        for(int j=0; j<8; ++j) {
            if(scanf("%d", &plan[i][j]) == EOF) {
                return false;
            }
            point[plan[i][j]].push_back(make_pair(i, j));
        }
    }
    return true;
}

void Print(int p[][8]) {
    for(int i=0; i<7; ++i) {
        printf(" ");
        for(int j=0; j<8; j++) {
            printf("%4d", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool Inside(int x, int y) {
    return x >= 0 && x < 7 && y >= 0 && y < 8;
}

bool PathJudge(int c) {
    for(int i=0; i<c; ++i) {
        if(memcmp(&path[i], &path[c], sizeof(path[i])) == 0) {
            return true;
        }
    }
    return false;
}

void Dfs(int bone, int thBone, int all) {
    for(size_t i=0; i<point[bone].size(); ++ i) {
        // int the dir j : there exists bone (bone, thBone)
        if(!vis[point[bone][i].first][point[bone][i].second]) {
            int limit = bone == thBone ? 2 : 4;
            for(int j=0; j<limit; ++ j) {
                int x = point[bone][i].first + dir[j][0], y = point[bone][i].second + dir[j][1];
                // put (bone, thBone)
                if(Inside(x, y) && !vis[x][y] && plan[x][y] == thBone) {
                    vis[ point[bone][i].first ][ point[bone][i].second ] = vis[x][y] = true;
                    path[c][ point[bone][i].first ][ point[bone][i].second ] = path[c][x][y] = all;
                    if(all == 28 && !PathJudge(c)) {
                        Print(path[c]);
                        vis[ point[bone][i].first ][ point[bone][i].second ] = vis[x][y] = false;
                        ++ c;
                        memcpy(&path[c], &path[c-1], sizeof(path[c]));
                        return ;
                    } else if(all < 28 ) {
                        if(thBone == 6) {
                            Dfs(bone + 1, bone + 1, all + 1);
                        } else {
                            Dfs(bone, thBone + 1, all + 1);
                        }
                    }
                    vis[ point[bone][i].first ][ point[bone][i].second ] = vis[x][y] = false;
                }
            }
        }
    }
}

int main() {
    int Case = 0;
    while(Init() && Read()) {
        if(Case) {
            printf("\n\n\n");
        }
        printf("Layout #%d:\n\n", ++Case);
        Print(plan);
        printf("Maps resulting from layout #%d are:\n\n", Case);

        Dfs(0, 0, 1);
        printf("There are %d solution(s) for layout #%d.\n", c, Case);

    }
    return 0;
}