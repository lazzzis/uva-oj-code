#include <bits/stdc++.h>

using namespace std;

const int MAXN = (1 << 15) + 50;
bool vis[MAXN][15+2];
struct Node{
    int robot, ob, step;
};
typedef pair<int, int> Move; // from first to second
Node q[MAXN*17]; // queue
Move move[MAXN*17];
int movePath[MAXN*17]; // the step before rear is movePath[rear]
vector <int> link[17]; // link table
int n, m, s, target;
int start;

void Read() {
    cin >> n >> m >> s >> target;
    start = 0;
    s --;
    target --;
    int tmp;
    for(int i=0; i<m; ++i) {
        cin >> tmp;
        start = start | (1 << (tmp - 1)); // add ob at position tmp-1
    }
    for(int i=0; i<n; ++ i) {
        link[i].clear();
    }
    int x, y;
    for(int i=0; i<n-1; ++i) {
        cin >> x >> y;
        link[x-1].push_back(y-1);
        link[y-1].push_back(x-1);
    }
}

// print path
void Print(int rear) {
    vector<Move> v;
    while(rear) {
        v.push_back(move[rear]);
        rear = movePath[rear];
    }
    vector<Move>::iterator it;
    for(it = v.end()-1; it>=v.begin(); it--) {
        // +1 !!!
        cout << it->first + 1 << " " << it->second + 1 << endl;
    }
}

void Bfs() {
    int front = 0, rear = 1;
    q[front].ob = start;
    q[front].robot = s;
    q[front].step = 0;
    memset(vis, false, sizeof(vis));
    vis[q[front].ob][q[front].robot] = true;
    while(front < rear) {
        Node& t = q[front];
        if(t.robot == target) {
            cout << t.step << endl;
            Print(front);
            return ;
        }
        for(int i=0; i<n; ++i) { // move i
            if((t.ob & (1 << i)) || i == t.robot) { 
            // there is an ob or a robot at the position
                for(size_t j=0; j<link[i].size(); ++ j) {
                    int nextNode = link[i][j];
                    if(nextNode == t.robot || ((1<<nextNode) & t.ob)!=0 ) {
                        // there exists an ob or a robot at the next position
                        continue;
                    }
                    Node next = t;
                    if(i == t.robot) {
                        next.robot = nextNode;
                    } else {
                        // move from i to nextNode
                        next.ob = next.ob - (1 << i);
                        next.ob = next.ob + (1 << nextNode);
                    }
                    next.step = t.step + 1;
                    if(!vis[next.ob][next.robot]) {
                        vis[next.ob][next.robot] = true;
                        move[rear].first = i; // from
                        move[rear].second = nextNode; // next
                        movePath[rear] = front; // the former step
                        q[rear ++] = next; // push into the queue
                    }
                }
            }
        }
        ++ front;
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, Case = 0;
    cin >> T;
    while(T --) {
        Read();
        cout << "Case " << (++Case) << ": ";
        Bfs();
    }
    return 0;
}