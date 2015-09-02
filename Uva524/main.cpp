#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 16 + 5;
int ans[MAXN], vis[MAXN];
bool isPrime[MAXN*2];
int counter = 0, N;

void Print() {
    printf("%d", ans[1]);
    for(int i=2; i<N+1; i++) {
        printf(" %d", ans[i]);
    }
    printf("\n");
}

int IsPrime(int N) {
    int k = sqrt(N);
    for(int i=2; i<k+1; i++) {
        if(N % i == 0) {
            return 0;
        }
    }
    return 1;
}

void Dfs(int cur) {
    if(cur == N+1 && isPrime[ans[cur - 1] + ans[1] ]) {
        Print();
    } else {
        for(int i=2; i<N+1; i++) {
            if(!vis[i] && isPrime[i + ans[cur - 1]]) {
                ans[cur] = i;
                vis[i] = 1;
                Dfs(cur + 1);
                vis[i] = 0;
            }
        }
    }
}

int main() {
    for(int i=2 ; i<MAXN*2; i++) {
        isPrime[i] = IsPrime(i);
    }
    while(cin >> N) {
        if(counter) {
            printf("\n");
        }
        printf("Case %d:\n", ++counter);
        memset(vis, 0, sizeof(vis));
        ans[1] = 1;
        vis[1] = 1;
        Dfs(2);
    }
    return 0;
}