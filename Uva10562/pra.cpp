#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>

using namespace std;

const int MAXN = 20000 + 30;
char buf[MAXN][MAXN];
int line;

void read() {
    line = 0;
    while(true) {
        gets(buf[line]);
        line ++;
        if(strcmp(buf[line-1], "#") == 0) {
            break;
        }
    }
}

void dfs(int x, int y) {
    printf("%c(", buf[x][y]);
    if(x+1 < line-1 && buf[x+1][y] == '|') { // the line is a point easy to be worng
        while(y >= 0 && buf[x+2][y] == '-') {
            y --;
        }
        y ++;
        while( buf[x+3][y]!='\0' && buf[x+2][y]=='-' ) {
            if(buf[x+3][y]!=' ') {
                dfs(x+3, y);
            }
            y ++;
        }
    }
    printf(")");
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();
    while(T --) {
        read();
        printf("(");
        if(line > 1) {
            for(int i=0; buf[0][i]!='\0'; i ++) {
                if(buf[0][i]!=' ') {
                    dfs(0, i);
                    break;
                }
            }
        }
        printf(")\n");
    }
    return 0;
}