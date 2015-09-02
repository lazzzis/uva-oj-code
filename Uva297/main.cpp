/*
    UvaOJ 297
    Emerald
    Sat 30 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

const int MAXN = 32 + 5;
int image[MAXN][MAXN], counter;

void Init() {
    memset( image, 0, sizeof(image) );
    counter = 0;
}

void Draw( string& str, int& strPos, int row, int col, int width ) {
    char ch = str[ strPos ++ ];
    if( ch == 'p' ) { // parent node
        Draw( str, strPos, row, col+width/2, width/2 );
        Draw( str, strPos, row, col, width/2 );
        Draw( str, strPos, row+width/2, col, width/2 );
        Draw( str, strPos, row+width/2, col+width/2, width/2 );
    } else if( ch == 'f' ) {
        for( int i=row; i<row+width; i++ ) {
            for( int j=col; j<col+width; j++ ) {
                if( image[i][j] == 0 ) {
                    image[i][j] = 1;
                    counter ++;
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while( T -- ) {
        Init();
        string str1, str2;
        cin >> str1 >> str2;
        int strPos = 0;
        Draw( str1, strPos, 0, 0, 32 );
        strPos = 0;
        Draw( str2, strPos, 0, 0, 32 );
        printf("There are %d black pixels.\n", counter );
    }
    return 0;
}