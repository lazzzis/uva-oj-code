// #include <iostream>
// #include <cstring>
// #include <cstdio>
// #include <algorithm>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x, y;
    Point(){}
    Point(int a, int b){
        x = a; y = b;
    }
};
vector<Point> point;
int dirPath[30];
int dir[4][2] = {1, 0, 0, 1, 0, -1, -1, 0};
int revDir[4] = {3, 2, 1, 0};
char dirChar[10] = "ensw";
int N, K, C;

void Read() {
    scanf("%d%d", &N, &K);
    point.clear();
    int x, y;
    for(int i=0; i<K; ++ i) {
        scanf("%d%d", &x, &y);
        point.push_back(Point(x, y));
    }
}

const int MAXN = 600;
const int OFFSET = 256;
bool vis[MAXN][MAXN];
bool IsVis(const Point &p) {
    return vis[p.x+OFFSET][p.y+OFFSET];
}

void SetVis(const Point &p, bool flag) {
    vis[p.x+OFFSET][p.y+OFFSET] = flag;
}

bool CanPut(const Point& p1, const Point& p2) {
    if(p1.x == p2.x) {
        for(size_t i = 0; i < point.size(); ++ i) {
            if(point[i].x == p1.x && point[i].y >= p1.y && point[i].y <= p2.y) {
                return false;
            }else if(point[i].x == p1.x && point[i].y >= p2.y && point[i].y <= p1.y) {
                return false;
            }
        }
    } else if(p1.y == p2.y) {
        for(size_t i = 0; i < point.size(); ++ i) {
            if(point[i].y == p1.y && point[i].x >= p1.x && point[i].x <= p2.x) {
                return false;
            }else if(point[i].y == p1.y && point[i].x >= p2.x && point[i].x <= p1.x) {
                return false;
            }
        }
    }
    return true;
}

void Print() {
    for(int i=1; i<N+1; i++) {
        printf("%c", dirChar[dirPath[i]]);
    }
    printf("\n");
}

void Dfs(Point p, int key) {
    if(abs(p.x) + abs(p.y) > (key+N) * (N-key+1) >> 1) {
        return ;
    }
    if(abs(p.x) > (1+N) * N >> 1 || abs(p.y) > (1+N) * N >> 1) {
        return ;
    }
    if(key == N + 1) {
        if(p.x == 0 && p.y == 0) {
            ++ C;
            Print();
        }
        return ;
    } else if(p.x == 0 && p.y == 0) {
        return ;
    }
    for(int i=0; i<4; i++) {
        if(dirPath[key - 1] != i && i != revDir[dirPath[key - 1]]) {
            Point next( p.x + key * dir[i][0], p.y + key * dir[i][1] );
            if(!IsVis(next) && CanPut(p, next)) {
                dirPath[key] = i;
                SetVis(next, true);
                Dfs(next, key+1);
                SetVis(next, false);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while(T --) {
        Read();
        memset(vis, false, sizeof(vis));
        Point start(0, 0);
        C = 0;
        for(int i=0; i<4; i++) {
            Point next( start.x+dir[i][0], start.y+dir[i][1] );
            if(CanPut(start, next)) {
                dirPath[1] = i;
                SetVis(next, true);
                Dfs(next, 2);
                SetVis(next, false);
            }
        }
        printf("Found %d golygon(s).\n", C);
        printf("\n");
    }
    return 0;
}