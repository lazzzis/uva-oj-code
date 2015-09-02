#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <string>

using namespace std;

const int MAXN = 10000 + 50;
int lch[MAXN], rch[MAXN];
int inOrder[MAXN], postOrder[MAXN];
int N; // the numbers of all the nodes

bool readList(int *order) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    N = 0;
    int x;
    while(ss >> x) {
        order[N ++] = x;
    }
    return N > 0;
}

int buildTree(int L1, int R1, int L2, int R2) {
    if(L1 > R1) {
        return 0;
    }
    int root = postOrder[R2];
    int p = L1;
    while(inOrder[p] != root) {
        p ++;
    }
    int cnt = p - L1; // the numbers of left child tree
    lch[root] = buildTree(L1, p-1, L2, L2+cnt-1); // left
    rch[root] = buildTree(p+1, R1, L2+cnt, R2-1); // right
    return root;
}

int best, bestSum;
void dfs(int u, int sum) {
    sum += u;
    if(!lch[u] && !rch[u]) { // leaf
        if(bestSum > sum) {
            bestSum = sum;
            best = u;
        } else if(bestSum == sum && best > u) {
            best = u;
        }
    }
    if(lch[u]) {
        dfs(lch[u], sum);
    }
    if(rch[u]) {
        dfs(rch[u], sum);
    }
}

int main() {
    while(readList(inOrder)) {
        readList(postOrder);
        buildTree(0, N-1, 0, N-1);
        bestSum = best = 1 << 20;
        dfs(postOrder[N-1], 0);
        cout << best << endl;
    }
    return 0;
}