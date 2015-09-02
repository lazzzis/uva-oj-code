#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20 + 5;
int plan[MAXN][MAXN], vis[MAXN][MAXN];
int M, N;
string ans;
string tmpStrAns[MAXN][MAXN];
int dir[4][2] = {0,1, 1,0, -1,0, 0,-1};
int planId[MAXN][MAXN], blockCount[MAXN], maxLen;
struct Node{
    int x, y, key;
    friend bool operator < (const Node& a, const Node& b) {
        return a.key > b.key;
    }
};
Node node[MAXN*MAXN];
int nodeNum;

void Init() {
    memset(vis, false, sizeof(vis));
    ans = "";
    memset(blockCount, 0, sizeof(blockCount));
}

void Read() {
    char c;
    maxLen = 0;
    nodeNum = 0;
    for(int i=0; i<M; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> c;
            plan[i][j] = c == '#' ? -1 : c - '0';
            maxLen = c=='#' ? maxLen : maxLen + 1;
            node[nodeNum].x = i;
            node[nodeNum].y = j;
            node[nodeNum].key = c;
        }
    }
}

// s > a ? compare length first
bool StrCmp(string& s, string& a) {
    if(s.length() > a.length()) {
        return true;
    } else if(s.length() == a.length()){
        return s > a;
    }
    return false;
}

typedef pair<int, int> Point;
Point q[35];
string LittleBfs(int x, int y) {
    string s = "";
    bool littleVis[MAXN][MAXN] = {false};
    int front = 0, rear = 1;
    q[front] = make_pair(x, y);
    littleVis[x][y] = 1;
    while(front < rear) {
        Point t = q[front];
        s.push_back(plan[t.first][t.second] + '0');
        for(int i=0; i<4; ++i) {
            int newX = t.first + dir[i][0], newY = t.second + dir[i][1];
            if(newX>=0 && newX<M && newY>=0 && newY<N && !littleVis[newX][newY] && !vis[newX][newY] && plan[newX][newY]!=-1) {
                littleVis[newX][newY] = true;
                q[rear ++] = make_pair(newX, newY);
            }
        }
        ++ front;
    }
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    // cout << s << endl;
    return s;
}

void Bfs(int x, int y, int id) {
    int front = 0, rear = 1;
    q[front] = make_pair(x, y);
    vis[x][y] = 1;
    while(front < rear) {
        Point t = q[front];
        planId[t.first][t.second] = id;
        blockCount[id] ++;
        for(int i=0; i<4; ++i) {
            int newX = t.first + dir[i][0], newY = t.second + dir[i][1];
            if(newX>=0 && newX<M && newY>=0 && newY<N && !vis[newX][newY] && plan[newX][newY]!=-1) {
                vis[newX][newY] = true;
                q[rear ++] = make_pair(newX, newY);
            }
        }
        ++ front;
    }
}

string tmpans;
void Dfs(int x, int y, string str) {
    string a;
    a = str + LittleBfs(x, y);
    if(!StrCmp(a, ans)) {
        return;
    }
    str.push_back(plan[x][y] + '0');
    bool flag = false;
    for(int i=0; i<4; ++i) {
        int newX = x + dir[i][0], newY = y + dir[i][1];
        if(newX>=0 && newX<M && newY>=0 && newY<N && !vis[newX][newY] && plan[newX][newY]!=-1) {
            vis[newX][newY] = true;
            Dfs(newX, newY, str);
            vis[newX][newY] = false;
            flag = true;
        }
    }
    // if(!flag) {
        tmpans = StrCmp(tmpans, str) ? tmpans : str;
        ans = StrCmp(ans, tmpans) ? ans : tmpans;
    // }
}

void Work() {
    string s;
    sort(node, node + nodeNum);
    for(int i=0; i<nodeNum; ++i) {
            memset(vis, false, sizeof(vis));
            vis[node[i].x][node[i].y] = 1;
            tmpans = "";
            Dfs(node[i].x, node[i].y, "");
            ans = StrCmp(ans, tmpans) ? ans : tmpans;
            if(ans.length() == maxLen) {
                return ;
            }
            tmpStrAns[node[i].x][node[i].y] = tmpans;
            vis[node[i].x][node[i].y] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> M >> N) {
        if(!M && !N)
            break;
        Init();
        Read();

        //Block();
        
        Work();
        cout << ans << endl;
    }
    return 0;
}