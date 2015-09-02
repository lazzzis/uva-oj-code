#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200 + 10;
int plan[MAXN][MAXN];
int counter[MAXN];
char apl[] = "ADJKSW";
int H, W;

void Read() {
    memset(plan, 0, sizeof(plan));
    char c;
    int pos;
    for(int i=1; i<=H; i++) {
        pos = 1;
        for(int j=1; j<=W; j++) {
            cin >> c;
            if(isalpha(c)) {
                c = c - 'a' + 10;
            } else {
                c = c - '0';
            }
            // Transfer to binary
            pos += 3;
            for(int k=0; k<4; k++) {
                plan[i][pos --] = c % 2;
                c /= 2;
            }
            pos +=5;
        }
    }
    W *= 4;
}

bool Inside(int x, int y) {
    return x>=0 && x<=H+1 && y>=0 && y<=W+1;
}

int cnt;
void DfsWhite(int x, int y) {
    if(!Inside(x, y) || plan[x][y]!=0) {
        return ;
    }
    plan[x][y] = -1;
    DfsWhite(x, y+1);
    DfsWhite(x, y-1);
    DfsWhite(x+1, y);
    DfsWhite(x-1, y);
}

void DfsBlack(int x, int y) {
    if(!Inside(x, y) || plan[x][y] == -1) return ;
    if(plan[x][y] == 0) {
        ++ cnt;
        DfsWhite(x, y);
        return ;
    }
    plan[x][y] = -1;
    DfsBlack(x, y+1);
    DfsBlack(x, y-1);
    DfsBlack(x+1, y);
    DfsBlack(x-1, y);
}

int Case = 0;
void Work() {
    Read();
    DfsWhite(0, 0); // the white blocks outside the hieroglyphs
    memset(counter, 0, sizeof(counter));
    for(int i=1; i<=H; i++) {
        for(int j=1; j<=W; j++) {
            if(plan[i][j] == 1) {
                cnt = 0;
                DfsBlack(i, j);
                switch(cnt) {
                    case 0: counter['W'] ++; break;
                    case 1: counter['A'] ++; break;
                    case 2: counter['K'] ++; break;
                    case 3: counter['J'] ++; break;
                    case 4: counter['S'] ++; break;
                    case 5: counter['D'] ++; break;
                }
            }
        }
    }
    cout << "Case " << (++Case) << ": ";
    for(int i=0; i<6; i++) {
        for(int j=0; j<counter[apl[i]]; ++j) {
            cout << apl[i];
        }
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> H >> W && (H + W)) {
        Work();
    }
    return 0;
}