/*
    UvaOJ 297
    Emerald
    Sat 25 Jul 2015
 */
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 32 + 5;
bool isBlack[MAXN][MAXN];
int cnt;

void paint(string &color, int &pos, int x, int y, int width) {
    if( color[pos] == 'p' ) {
        paint(color, ++ pos, x, y + width / 2, width / 2 ); // 1
        paint(color, ++ pos, x, y, width / 2 ); // 2
        paint(color, ++ pos, x + width / 2, y, width / 2 ); // 3
        paint(color, ++ pos, x + width / 2, y + width / 2, width / 2 ); // 4
    } else if( color[pos] == 'f' ) {
        for(int i = x; i < x + width; i ++) {
            for(int j = y; j < y + width; j ++) {
                if( isBlack[i][j] == false ) {
                    isBlack[i][j] = true;
                    cnt ++;
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while(T --) {
        memset(isBlack, false, sizeof(isBlack));
        cnt = 0;
        string in;
        cin >> in;
        int pos = 0;
        paint(in, pos, 0, 0, 32);
        cin >> in;
        pos = 0;
        paint(in, pos, 0, 0, 32);
        printf("There are %d black pixels.\n", cnt);
    }
    return 0;
}