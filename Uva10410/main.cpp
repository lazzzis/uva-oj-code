/*
    UvaOJ 10410
    Emerald
    Sun 26 Jul 2015
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1000 + 50;
int dfsOrder[MAXN], bfsOrder[MAXN];
int hashOrder[MAXN]; // the position of i in dfsOrder is hashOrder[i]. counting from i
std::vector<int> v[MAXN]; // the tree
int N;

void VecInitClear() {
    for( int i=1; i<N+1; i ++ ) {
        v[i].clear();
    }
}

void Read() {
    for(int i=1; i<N+1; i++) {
        scanf("%d", &bfsOrder[i]);
        hashOrder[ bfsOrder[i] ] = i;
    }
    for(int i=1; i<N+1; i++) {
        scanf("%d", &dfsOrder[i]);
    }
}

void Solve() {
    if(N == 1 || N == 0) {
        return ;
    }
    bool vis[MAXN] = {false};
    int nextPos = 2;
    queue<int> q;
    // record the position in dfsOrder, not the exact value
    q.push( 1 );
    vis[1] = true;
    while( !q.empty() ) {
        int t = q.front();
        q.pop();
        for( int i = t+1; i<N+1 && !vis[i] ; i++ ) {
            if( hashOrder[ dfsOrder[i] ] == nextPos ) {
                v[dfsOrder[t]].push_back(dfsOrder[i]);
                vis[i] = true;
                nextPos ++;
                q.push(i);
            }
        }
    }
}

void Print() {
    for(int i=1; i<N+1; i++) {
        printf("%d:", i);
        for(int j=0; j<(int)v[i].size(); j++) {
            printf(" %d", v[i][j]);
        }
        printf("\n");
    }
}

void Work() {
    VecInitClear();
    Read();
    Solve();
    Print();
}

int main() {
    while(cin >> N)
        Work();
    return 0;
}