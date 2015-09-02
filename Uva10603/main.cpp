#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

struct Node{
    int vol[3], dist;
    bool operator < (const Node& rhs) const {
        return dist > rhs.dist;
    }
};

const int MAXN = 200 + 50;
int vis[MAXN][MAXN], // vis[a][b], if a and b are known, c is known too
    ans[MAXN], // the ans[d] -> the min amount of d liters
    cap[3]; // the capicity of cap[i]

void UpdateAns(Node& s) {
    for(int i=0; i<3; i++) {
        if(ans[s.vol[i]] == -1 || ans[s.vol[i]] > s.dist ) {
            ans[s.vol[i]] = s.dist;
        }
    }

}

void Bfs(int a, int b, int c, int d) {
    memset(vis, 0, sizeof(vis));
    memset(ans, -1, sizeof(ans));

    cap[0] = a;
    cap[1] = b;
    cap[2] = c;

    priority_queue<Node> p;
    Node start;
    start.vol[0] = 0;
    start.vol[1] = 0;
    start.vol[2] = c;
    start.dist = 0;
    UpdateAns(start);

    p.push(start);
    vis[0][0] = 1;
    while(!p.empty()) {
        Node t = p.top();
        p.pop();
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                // i to j
                if(i != j) {
                    if(t.vol[i] == d) { // the direct ans
                        return ;
                    }
                    int amount = min(cap[j], t.vol[i]+t.vol[j]) - t.vol[j];
                    Node next;
                    memcpy(&next, &t, sizeof(next)); // copy
                    next.vol[i] -= amount;
                    next.vol[j] += amount;
                    next.dist += amount;
                    UpdateAns(next);
                    // 0 and 1 rather than i and j
                    if(!vis[next.vol[0]][next.vol[1]]) {
                        vis[next.vol[0]][next.vol[1]] = 1;
                        p.push(next);
                    }
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    int a, b, c, d;
    while(T --) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        Bfs(a, b, c, d);
        for(int i=d; i>=0; i--) {
            if(ans[i] >= 0) { 
            // >= rather than >, because maybe you can get ans in the input
            // for example : 2 3 4 4
                printf("%d %d\n", ans[i], i);
                break;
            }
        }
    }
    return 0;
}