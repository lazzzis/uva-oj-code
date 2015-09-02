/*
    Emerald
    UvaOJ 10562
    Sun 19 Jul 2015
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>

using namespace std;

const int MAXN = 200 + 50;
char charMatrix[MAXN][MAXN];
int line;

void BuildTree( int x, int y ) {
    printf("%c(", charMatrix[x][y]);
    if( x+1 < line && charMatrix[x+1][y] == '|' ) {
        while( y>=0 && charMatrix[x+2][y] == '-' ) { // seek for the leftest '-'
            y --;
        }
        y ++;
        
        while( charMatrix[x+3][y]!='\0' && charMatrix[x+2][y] == '-' ) {
            if( !isspace(charMatrix[x+3][y]) ) {
                BuildTree(x + 3, y);
            }
            y ++;
        }
    }
    printf(")");
}

int main() {
    int T;
    cin >> T;
    getchar();
    while( T -- ) {
        line = 0;
        while( true ) {
            gets( charMatrix[line] );
            if( charMatrix[line][0] == '#' ) {
                // input end
                break;
            }
            line ++;
        }
        printf("(");
        if( line ) {
            int length = strlen( charMatrix[0] );
            for( int i=0; i<length; i++ ) {
                if( charMatrix[0][i] != ' ' ) {
                    BuildTree( 0, i );
                    break;
                }
            }
        }
        printf(")\n");
    }
    return 0;
}