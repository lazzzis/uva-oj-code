#include <bits/stdc++.h>

using namespace std;

typedef int State[17];
// 0 : s 1~M:stone
struct Node{
    State st;
    int step;
};
typedef pair<int, int> Move;
const int MAXN = 2000000 + 50;
Node q[MAXN];
Move move[MAXN];
int movePath[MAXN];
vector<int> link[17];
int N, M, S, T;
State start;

const int hashSize = 1000003;
int head[hashSize], next[MAXN];
void init_loopup_table() {
    memset(head, 0, sizeof(head));
}
int getKey(State& s) {
    long long v = 0;
    for(int i=0; i<=M; ++i ) {
        v = v * 10 + s[i];
    }
    return v % hashSize;
}
bool IsHash(int rear) {
    int h = getKey(q[rear].st);
    int u = head[h];
    while(u) {
        if(memcmp(q[u].st, q[rear].st, sizeof(q[rear].st)) == 0) {
            return true;
        }
        u = next[u];
    }
    next[rear] = head[h];
    head[h] = rear;
    return false;
}

void Print(int rear) {
    vector<Move> v;
    while(rear) {
        v.push_back(move[rear]);
        rear = movePath[rear];
    }
    for(vector<Move>::iterator it = v.end() - 1; it>=v.begin(); -- it) {
        cout << it->first << " " << it->second << endl;
    }
}

void Bfs() {
    int front = 0, rear = 1;
    sort(start+1, start + M + 1);
    memcpy(&q[front].st, &start, sizeof(start));
    q[front].step = 0;
    IsHash(front);
    while(front < rear) {
        Node& t = q[front];
        if(t.st[0] == T) {
            cout << t.step << endl;
            Print(front);
            return ;
        }
        for(int i=0; i<=M; ++ i) {
            int nowNode = t.st[i];
            for(size_t k, j=0; j<link[nowNode].size(); ++ j) {
                int nextNode = link[nowNode][j];
                for(k=0; k<=M; ++ k) {
                    if(t.st[k] == nextNode) {
                        break;
                    }
                }
                if(k == M+1) {
                    Node &newS = q[rear];
                    memcpy(&newS, &t, sizeof(t));
                    newS.st[i] = nextNode;
                    newS.step = t.step + 1;
                    sort(newS.st+1, newS.st+M+1);
                    if(!IsHash(rear)) {
                        move[rear].first = t.st[i];
                        move[rear].second = nextNode;
                        movePath[rear] = front;
                        ++ rear;
                    }
                }
            }
        }
        ++ front;
    }
    cout << "-1" <<endl;
}

void Scan() {
    cin >> N >> M >> S >> T;
    start[0] = S;
    for(int i=1; i<=M; ++ i) {
        cin >> start[i];
    }
    int x, y;
    for(int i=1; i<N+1; ++ i) {
        link[i].clear();
    }
    for(int i=0; i<N-1; ++ i) {
        cin >> x >> y;
        link[x].push_back(y);
        link[y].push_back(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, Case = 0;
    cin >> T;
    while(T --) {
        Scan();
        init_loopup_table();
        cout << "Case " << (++Case) <<": ";
        Bfs();
    }
    return 0;
}