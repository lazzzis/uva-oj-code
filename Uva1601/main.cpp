#include <bits/stdc++.h>

using namespace std;

const int MAXN = 16 + 5;
char plan[MAXN][MAXN];
int W, H, N;
vector<int> link[MAXN*MAXN];
bool vis[MAXN*MAXN][MAXN*MAXN][MAXN*MAXN];
int dir[4][2] = {0,1, 0,-1, 1,0, -1,0};

struct State{
    int ghostPos[5], step;
};

State finalState, firstState;

// more than one ghost occupy a same position
// p is the prev state, whether two ghots in s exchange with their position
bool isCollisionOrExChange(State& s, State& p) {
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if(i!=j && s.ghostPos[i] == s.ghostPos[j]) {
                return true;
            }
            if(i!=j && s.ghostPos[i] == p.ghostPos[j] && s.ghostPos[j] == p.ghostPos[i]) {
                return true;
            }
        }
    }
    return false;
}

void Read() {
    for(int i=0; i<H; ++i) {
        cin.get();
        for(int j=0; j<W; ++j) {
            plan[i][j] = cin.get();
        }
    }
}

int GetVisValue(int x, int y) {
    return x * W + y;
}

void SetVis(State& t, bool flag) {
    int i, a[3]; // the positon of each ghost
    for(i=0; i<N; ++i) {
        a[i] = t.ghostPos[i];
    }
    // the number of ghosts may be less than 3
    for(; i<3; ++i) {
        a[i] = 0;
    }
    vis[a[0]][a[1]][a[2]] = flag;
}

bool IsVis(State& t) {
    int i, a[3]; // the positon of each ghost
    for(i=0; i<N; ++i) {
        a[i] = t.ghostPos[i];
    }
    // the number of ghosts may be less than 3
    for(; i<3; ++i) {
        a[i] = 0;
    }
    return vis[a[0]][a[1]][a[2]];
}

bool IsFinal(State& t) {
    for(int i=0; i<N; ++i) {
        if(finalState.ghostPos[i] != t.ghostPos[i]) {
            return false;
        }
    }
    return true;
}

// the ghost numbered g move
void NextState(State& s, int g, queue<State>& q, State& former) {
    for(size_t i=0; i<link[former.ghostPos[g]].size(); ++ i) {
        s.ghostPos[g] = link[former.ghostPos[g]][i];
        if(g == N-1 && !IsVis(s) && !isCollisionOrExChange(s, former)) {
            SetVis(s, true);
            q.push(s);
        } else if (g < N-1) {
            NextState(s, g+1, q, former);
        }
    }
}

// output the point of all ghosts
void Test(State& t) {
    for(int i=0; i<N; ++i) {
        cout << t.ghostPos[i] / W << " " << t.ghostPos[i] % W << endl;
    }
    cout << t.step << endl;
    cout << endl;
}

int Bfs() {
    memset(vis, false, sizeof(vis));
    queue<State> q;
    firstState.step = 0;
    q.push(firstState);
    SetVis(firstState, true);
    while(!q.empty()) {
        State t = q.front();
        q.pop();
        // Test(t);
        if(IsFinal(t)) {
            return t.step;
        }
        State newS;
        newS.step = t.step + 1;
        NextState(newS, 0, q, t);
    }
    return -1;
}

// Make a Graph
void MakeLink() {
    for(int i=0; i<H; ++ i) {
        for(int j=0; j<W; ++ j) {
            if(plan[i][j] != '#') {
                // the position means unmoving
                link[GetVisValue(i, j)].clear();
                link[GetVisValue(i, j)].push_back(GetVisValue(i, j));
                for(int k=0; k<4; ++k) { // four directions
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if(x>=0 && x<H && y>=0 && y<W && plan[x][y]!='#') {
                        link[GetVisValue(i, j)].push_back(GetVisValue(x, y));
                    }
                }
            }
            if (isupper(plan[i][j])) {
                finalState.ghostPos[plan[i][j]-'A'] = GetVisValue(i, j);
            } else if (islower(plan[i][j])) {
                firstState.ghostPos[plan[i][j]-'a'] = GetVisValue(i, j);
            }
        }
    }
}

void Work() {
    Read();
    MakeLink();
    cout << Bfs() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> W >> H >> N) {
        if(!W && !H && !N) {
            break;
        }
        Work();
    }
    return 0;
}