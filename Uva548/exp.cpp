/*
    UvaOJ 548
    Emerald
    Thu 23 Jul 2015
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

const int MAXN = 10000 + 50;
int inOrder[MAXN], postOrder[MAXN], lch[MAXN], rch[MAXN];
int N;

bool ReadList(int *array) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    N = 0;
    int x;
    while(ss >> x) {
        array[N ++] = x;
    }
    return N > 0;
}

int build(int L1, int R1, int L2, int R2) {
    if(L1 > R1){
        return 0;
    }
    int root = postOrder[R2];
    int p = L1;
    while (inOrder[p] != root) {
        p ++;
    }
    int cnt = p - L1;
    lch[root] = build(L1, p-1, L2, L2+cnt-1);
    rch[root] = build(p+1, R1, L2+cnt, R2-1);
    return root;
}

int best, bestSum;
void dfs(int u, int sum) {
    sum += u;
    if(!lch[u] && !rch[u]) {
        if (sum < bestSum) {
            bestSum = sum;
            best = u;
        } else if (sum == bestSum && u < best) {
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
    while(ReadList(inOrder)){
        ReadList(postOrder);
        build(0, N-1, 0, N-1);
        bestSum = 100000000 + 10;
        dfs(postOrder[N-1], 0);
        cout << best << endl;
    }
    return 0;
}