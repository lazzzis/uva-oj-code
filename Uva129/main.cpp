#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN_LEN = 80 + 5;
char ans[MAXN_LEN];
int N, Chars;
bool flag;

void Print(int cur) { // cur is the last pos to be printed
    printf("%c", ans[0]);
    for(int i=1; i<=cur; ++i) {
        printf("%c", ans[i]);
        if(i % 4 == 3 && i % 63 && i!=cur) {
            printf(" ");
        }
        if(i % 63 == 0) {
            printf("\n");
        }
    }
    if(!cur || cur % 63 != 0) {
        printf("\n");
    }
    printf("%d\n", cur+1);
}

bool IsHard(int cur) {
    for(int j, i=1; i*2<=cur+1; ++i) {
        int pos = cur - i;
        for(j = 0; j<i ; ++j) {
            if( ans[pos-j] != ans[cur-j] ) {
                break;
            }
        }
        if( i == j ) {
            return false;
        }
    }
    return true;
}

int type;
void Dfs(int cur) {
    for(int i=0; i<Chars; ++i) {
        ans[cur] = i+'A';
        if(!flag && IsHard(cur) ) {
            type ++;
            if( type == N ) {
                Print(cur);
                flag = true;
                return ;
            }
            Dfs(cur+1);
        }
    }
}

int main() {
    while(cin >> N >> Chars) {
        if(N == 0 && Chars == 0) {
            break;
        }
        flag = false;
        type = 0;
        Dfs(0);
    }
    return 0;
}