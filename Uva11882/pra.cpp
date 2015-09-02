#include <bits/stdc++.h>

using namespace std;

const int MAXN = (20 + 5) * (20 + 5);
int plan[20][20], vis[MAXN], planVal[MAXN];
int M, N;
vector<int> v[MAXN];
string ans;
string tmpStrAns[MAXN];
int dir[4][2] = {0,1, 1,0, -1,0, 0,-1};
int planId[MAXN], blockCount[MAXN], maxLen;

void Init() {
    memset(vis, false, sizeof(vis));
    ans = "";
    memset(blockCount, 0, sizeof(blockCount));
}

void Read() {
    char c;
    for(int i=0; i<M; ++i) {
        for(int j=0; j<N; ++j) {
            cin >> c;
            plan[i][j] = c == '#' ? -1 : c - '0';
            planVal[i * N + j] = plan[i][j];
            tmpStrAns[i * N + j] = "";
        }
    }
}

void MakeLink() {
    for(int i=0; i<M; ++i) {
        for(int j=0; j<N; ++j) {
            v[i*N+j].clear();
            if(plan[i][j] == -1){
                continue;
            }
            for(int k=0; k<4; ++ k) {
                int newX = i + dir[k][0], newY = j + dir[k][1];
                if(newX>=0 && newX<M && newY>=0 && newY<N && plan[newX][newY]!=-1) {
                    v[i*N+j].push_back(newX * N + newY);
                    // cout << i << " " << j << " " << newX << " " << newY << endl;
                }
            }
        }
    }
}

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
void Bfs(int x, int y, int id) {
    int front = 0, rear = 1;
    q[front] = make_pair(x, y);
    vis[x * N + y] = 1;
    while(front < rear) {
        Point t = q[front];
        // cout << t.first << " " << t.second << endl;
        planId[t.first * N + t.second] = id;
        blockCount[id] ++;
        for(int i=0; i<4; ++i) {
            int newX = t.first + dir[i][0], newY = t.second + dir[i][1];
            if(newX>=0 && newX<M && newY>=0 && newY<N && !vis[newX * N + newY] && plan[newX][newY]!=-1) {
                vis[newX * N + newY] = true;
                q[rear ++] = make_pair(newX, newY);
            }
        }
        ++ front;
    }
}

string LittleBfs(int value) {
    string s = "";
    bool littleVis[MAXN] = {false};
    int front = 0, rear = 1;
    int q2[MAXN];
    q2[front] = value;
    littleVis[value] = 1;
    while(front < rear) {
        int t = q2[front];
        s.push_back(planVal[value] + '0');
        for(size_t i=0; i<v[value].size(); ++i) {
            int next = v[value][i];
            if(!littleVis[next] && !vis[next]) {
                littleVis[next] = true;
                q2[rear ++] = next;
            }
        }
        ++ front;
    }
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    // cout << s << endl;
    return s;
}

string tmpans;
void Dfs(int value, string str) {
    // cout << value / M << " " << value%M << " " << str << endl;
    string a;
    if(tmpStrAns[value]!="") {
        a = str+tmpStrAns[value];
        if( !StrCmp(a, ans) ) {
            return ;
        }
    }
    a = str + LittleBfs(value);
    if(!StrCmp(a, ans)) {
        return;
    }
    str.push_back(planVal[value] + '0');
    bool flag = false;
    for(size_t i=0; i<v[value].size(); ++i) {
        int next = v[value][i];
        if(!vis[next]) {
            vis[next] = true;
            Dfs(next, str);
            vis[next] = false;
            flag = true;
        }
    }
    if(!flag) {
        tmpans = StrCmp(tmpans, str) ? tmpans : str;
    }
}

void Work() {
    string s;
    for(int k = 9; k>=1; -- k) {    
        for(int i=0; i<M; ++i) {
            for(int j=0; j<N; ++j) {
                if(plan[i][j] == k) {
                    memset(vis, false, sizeof(vis));
                    vis[i * N + j] = 1;
                    tmpans = "";
                    Dfs(i * N + j, "");
                    ans = StrCmp(ans, tmpans) ? ans : tmpans;
                    tmpStrAns[i * N + j] = tmpans;
                    vis[i * N + j] = 0;
                }
            }
        }
        if(ans.length() == maxLen) {
            return ;
        }
    }
}


void Block() {
    memset(vis, 0, sizeof(vis));
    int id = 0;
    for(int i=0; i<M; ++i) {
        for(int j=0; j<N; ++j) {
            if(!vis[i * N + j] && plan[i][j]!=-1) {
                Bfs(i, j, id++);
            }
        }
    }
    maxLen = -1;
    for(int i=0; i<id+1; ++i) {
        maxLen = maxLen > blockCount[i] ? maxLen : blockCount[i];
    }
    memset(vis, false, sizeof(vis));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> M >> N) {
        if(!M && !N)
            break;
        Init();
        Read();

        Block();

        MakeLink();
        
        Work();
        cout << ans << endl;
    }
    return 0;
}