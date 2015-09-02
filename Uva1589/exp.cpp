/*
    UvaOJ 1589
    Emerald
    18 Aug, 2015
*/
// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_X = 10, MAX_Y = 9;
struct Node{
    char type;
    int x, y;
};
int N, blackX, blackY;
Node chess[25];
bool vis[MAX_X+5][MAX_Y+5], piece[MAX_X+5][MAX_Y+5];
int horseDir[8][2] = {
    2, 1,  1, 2,
    -2, 1, -1, 2,
    2, -1, 1, -2,
    -2, -1, -1, -2
};
int fourDir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void Init() {
    memset(vis, false, sizeof(vis));
    memset(piece, false, sizeof(piece));
}

bool Inside(int x, int y) {
    return x>=1 && x<=10 && y>=1 && y<=9;
}

void Read() {
    for(int i=0; i<N; ++ i) {
        cin >> chess[i].type >> chess[i].x >> chess[i].y;
        chess[i].type = toupper(chess[i].type);
        piece[chess[i].x][chess[i].y] = true;
    }
}
// Move General
void MoveG(int x, int y) {
    for(x--; x>0 && !piece[x][y]; x--) {
        vis[x][y] = true;
    }
}

// Move Horse
void MoveH(int x, int y) {
    for(int i=0; i<8; ++ i) {
        int newX = x + horseDir[i][0],
            newY = y + horseDir[i][1];
        int legX = x + horseDir[i][0] / 2,
            legY = y + horseDir[i][1] / 2;
        if(Inside(newX, newY) && !piece[newX][newY] && !piece[legX][legY]) {
            vis[newX][newY] = true;
        }
    }
}

// Move Chariot
void MoveR(int x, int y) {
    for(int i=0; i<4; ++ i) {
        int newX = x + fourDir[i][0],
            newY = y + fourDir[i][1];
        while(Inside(newX, newY) && !piece[newX][newY]) {
            vis[newX][newY] = true;
            newX += fourDir[i][0];
            newY += fourDir[i][1];
        }
    }
}

// Move Cannon
void MoveC(int x, int y) {
    for(int i=0; i<4; ++ i) {
        int newX = x + fourDir[i][0],
            newY = y + fourDir[i][1];
        while(Inside(newX, newY) && !piece[newX][newY]) {
            newX += fourDir[i][0];
            newY += fourDir[i][1];
        }
        newX += fourDir[i][0];
        newY += fourDir[i][1];
        while(Inside(newX, newY) && !piece[newX][newY]) {
            vis[newX][newY] = true;
            newX += fourDir[i][0];
            newY += fourDir[i][1];
        }
    }
}

void Move(Node& c) {
    switch(c.type) {
        case 'G': MoveG(c.x, c.y); break;
        case 'H': MoveH(c.x, c.y); break;
        case 'R': MoveR(c.x, c.y); break;
        case 'C': MoveC(c.x, c.y); break;
    }
}

bool IsCheckmate(int x, int y) {
    for(int i=0; i<4; ++ i) {
        int newX = x + fourDir[i][0],
            newY = y + fourDir[i][1];
        if(newX >= 1 && newX <= 3 && newY >= 4 && newY <= 6 && !vis[newX][newY]) {
            return false;
        }
    }
    return true;
}

void Work() {
    Init();
    Read();
    for(int i=0; i<N; ++ i) {
        Move(chess[i]);
    }
    if(IsCheckmate(blackX, blackY)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> N >> blackX >> blackY) {
        if(!N && !blackX && !blackY) {
            break;
        }
        Work();
    }
    return 0;
}