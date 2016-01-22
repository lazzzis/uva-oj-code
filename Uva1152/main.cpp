/**
 * AC @ Sep 2nd 2015
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 4000 + 50;
const int hashsize = 999983; // 149993 -> 2.528s  299993 -> 2.205s  999983 -> 2.658
const int OFFSET = 1 << 30;

struct Node{
    int value;
    LL cnt;
    Node(int v, LL c){
        value = v;
        cnt = c;
    }
    Node(){}
};

int lst[MAXN][5], N;
std::vector<Node> table[hashsize];

void init() {
    for(int i=0; i<hashsize; ++ i) {
        table[i].clear();
    }
}

void read() {
    cin >> N;
    for(int i=0; i<N; ++ i) {
        for(int j=0; j<4; ++ j) {
            cin >> lst[i][j];
        }
    }
}

void insert(int sum) {
    int value = sum % hashsize;
    for (std::vector<Node>::iterator it = table[value].begin(); it != table[value].end(); ++it) {
        if (it->value==sum) {
            ++ it->cnt;
            return ;
        }
    }
    table[value].push_back(Node(sum, 1));
}

LL find(int sum) {
    int value = sum % hashsize;
    for (std::vector<Node>::iterator it = table[value].begin(); it != table[value].end(); ++it) {
        if(it->value == sum) {
            return it->cnt;
        }
    }
    return 0;
}

void work() {
    init();
    int sum;
    for(int i=0; i<N; ++ i) {
        for(int j=0; j<N; j++) {
            sum = lst[i][0] + lst[j][1];
            insert(sum + OFFSET);
        }
    }
    long long ans = 0;
    for(int i=0; i<N; ++ i) {
        for(int j=0; j<N; j++) {
            sum = lst[i][2] + lst[j][3];
            ans = ans + find(-sum + OFFSET);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) {
        read();
        work();
        if(T) {
            cout << endl;
        }
    }
    return 0;
}