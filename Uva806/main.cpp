#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int MAXN = 64 + 5;
int graph[MAXN][MAXN];
int quad[MAXN][MAXN];
std::vector<int> tree;
int Length, Case = 0;
int dir[2][2] = {
    1, //0,0
    2, // 0,1
    3, // 1,1
    4 // 1,0
};
// double dir[4][2] = {};

void Init() {
    memset(graph, 0, sizeof(graph));
    tree.clear();
}

void ReadTree() {
    int x;
    while(cin >> x && x!=-1) {
        tree.push_back(x);
    }
}

void BuildTree(int value, int x, int y, int width ) {
    // printf("%d %d %d %d\n", value, x, y, width);
    if( value==0 ) {
        for(int i = x; i < x + width; i ++) {
            for(int j = y; j < y + width; j ++) {
                graph[i][j] = 1;
            }
        }
    } else {
        switch(value%5){
            case 1: BuildTree(value/5, x, y, width/2); // NW
                break;
            case 2: BuildTree(value/5, x, y+width/2, width/2); // NE
                break;
            case 3: BuildTree(value/5, x+width/2, y, width/2); // SW
                break;
            case 4: BuildTree(value/5, x+width/2, y+width/2, width/2); // SE
                break;
        }
    }
}

void PrintGraph() {
    if(Case) {
        printf("\n");
    }
    printf("Image %d\n", ++Case);
    for(int i=0; i<Length; ++i) {
        for(int j=0; j<Length; ++j) {
            printf("%c", graph[i][j] ? '*' : '.');
        }
        printf("\n");
    }
}

void ReadGraph() {
    char ch;
    getchar();
    for(int i=0; i<Length; ++i) {
        for(int j=0; j<Length; ++j) {
            scanf("%c", &ch);
            quad[i][j] = ch - '0';
        }
        getchar();
    }
}

int BuildQuad(int x, int y, int width, int mul) {
        printf("%d %d %d %d\n",x, y, width, mul );
        //printf("%d %d %d %d\n\n", t1, t2, t3, t4);
    if( width == 1 ) {
        return quad[x][y] ? 1 : -1;
    } else {
        int t1 = BuildQuad( x, y, width/2,  mul*5 + 1 ) * 1;
        int t2 = BuildQuad( x, y+width/2, width/2, mul*5 + 2 ) * 2;
        int t3 = BuildQuad( x+width/2, y, width/2, mul*5 + 3 ) * 3;
        int t4 = BuildQuad( x+width/2, y+width/2, width/2, mul*5 + 4 ) * 4;
        if( t1>0 && t2>0 && t3>0 && t4>0 ) {
            return 1;
        } else {
            if( t1 > 0 ) {
                tree.push_back(t1 + mul*5);
            }
            if( t2 > 0 ) {
                tree.push_back(t2 + mul*5);
            }
            if( t3 > 0 ) {
                tree.push_back(t3 + mul*5);
            }
            if( t4 > 0 ) {
                tree.push_back(t4 + mul*5);
            }
            return -1;
        }
    }
}

void PrintQuad() {
    sort(tree.begin(), tree.end());
    for( int i=0; i<(int)tree.size(); i++ ) {
        cout << tree[i] << endl;
    }
}

void Work() {
    Init();
    if( Length < 0 ) {
        Length = -Length;
        ReadTree();
        for(int i=0; i<(int)tree.size(); i++) {
            BuildTree(tree[i], 0, 0, Length);
        }
        PrintGraph();
    } else {
        ReadGraph();
        if(Length == 1) {
            if( quad[0][0] == 1 ) {
                tree.push_back(1);
            }
        } else {
            BuildQuad(0, 0, Length, 0);
        }
        PrintQuad();
    }
}

int main() {
    while(cin >> Length && Length) {
        Work();
    }
    return 0;
}