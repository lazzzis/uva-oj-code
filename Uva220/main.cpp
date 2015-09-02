#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 8;
char chess[ MAXN+5 ][ MAXN+5 ];
char opColor; // 现在要摆的棋子的颜色
char oppoColor[300]; // 相反的颜色

int CountColor( char color ) { // 数某个颜色的棋子的数量
    int sum = 0;
    int i, j;
    for( i=1; i<=MAXN; i++ ) {
        for( j=1; j<=MAXN; j++ ) {
            sum = sum + (chess[i][j] == color) ;
        }
    }
    return sum;
}


bool CanPlaced( int x, int y, int dirx, int diry ) { // // 从从某个方向开始，dirx, diry的值用于控制方向
    int i, j;
    bool findOppoColor = false;
    for( i=x+dirx, j=y+diry; i>=1 && i<=MAXN && j>=1 && j<=MAXN ; i+=dirx, j+=diry ) {
        if( chess[i][j] == '-' ) {
            return false;
        } else if( chess[i][j] == oppoColor[ opColor ] ) {
            findOppoColor = true;
        } else if( chess[i][j] == opColor ) {
            if( findOppoColor ) {
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
    
}

bool CanPlaced( int x, int y ) { // eight directions
    return CanPlaced( x, y, -1,0 ) || CanPlaced( x, y, 1,0 ) || CanPlaced( x, y, 0, 1 ) || CanPlaced( x, y, 0, -1 ) || CanPlaced( x, y, 1, 1 ) || CanPlaced( x, y, -1, 1 ) || CanPlaced( x, y, 1, -1 ) || CanPlaced( x, y, -1, -1 ); // 有一个方向能放就行
}

void List() { // 列出所有能摆放棋子的位置
    int i, j;
    bool first = true;
    for( i=1; i<=MAXN; i++ ) {
        for( j=1; j<=MAXN; j++ ) {
            if( chess[i][j]=='-' && CanPlaced( i, j ) ) {
                if( first ) {
                    first = false;
                    printf( "(%d,%d)", i, j );
                }else {
                    printf( " (%d,%d)", i, j );
                }
            }
        }
    }
    if( first == true ) {
        printf( "No legal move.\n" );
    } else {
        printf( "\n" );
    }
}

bool Change( int x, int y, int dirx, int diry ) { // 从从某个方向开始，dirx, diry的值用于控制方向
    int i, j;
    bool flag = false;
    for( i=x+dirx, j=y+diry; i>=1 && i<=MAXN && j>=1 && j<=MAXN ; i+=dirx, j+=diry ) {
        if( chess[i][j] == '-' ) {
            return false;
        } else if( chess[i][j] == opColor ) {
            flag = true;
            break;
        }
    }
    if( flag == false ) { // no find opColor
        return false;
    }
    flag = false;
    for( i=x+dirx, j=y+diry; i>=1 && i<=MAXN && j>=1 && j<=MAXN ; i+=dirx, j+=diry ) {
        if( chess[i][j] == oppoColor[ opColor ] ) {
            chess[i][j] = opColor;
            flag = true;
        } else if( chess[i][j] == opColor ) {
            break;
        }
    }
    return flag;
}

bool Move( int x, int y ) {
    chess[ x ][ y ] = opColor;
    Change( x, y, -1,0 );
    Change( x, y, 1,0 );
    Change( x, y, 0, 1 );
    Change( x, y, 0, -1 );
    Change( x, y, 1, 1 );
    Change( x, y, -1, 1 );
    Change( x, y, 1, -1 );
    Change( x, y, -1, -1 ); // 从各个方向试图进行更改
    /*
       Change( x, y, -1,0 ) || Change( x, y, 1,0 ) || 
       Change( x, y, 0, 1 ) || Change( x, y, 0, -1 ) || Change( x, y, 1, 1 ) 
       || Change( x, y, -1, 1 ) || Change( x, y, 1, -1 ) || Change( x, y, -1, -1 );
       原先这样写的，但改成上面这样子就对了
       原因是：如果用"或"，那么如果第一个方向对了，后面几个函数就不会执行，而后面几个函数可能有几个是符合题意可以翻棋子的，所以
       改用"或"是很糟糕的做法
    */
    printf( "Black -%3d White -%3d\n", CountColor( 'B' ), CountColor( 'W' ) );
    return true;
}

void PrintChess() { // 打印棋盘
    int i;
    for( i=1; i<=MAXN; i++ ) {
        printf( "%s\n", chess[i]+1 );
    }
}

int main() {
    int T;
    cin >> T;
    int i, j;
    oppoColor[ 'B' ] = 'W';
    oppoColor[ 'W' ] = 'B';
    while( T-- ) {
        for( i=1; i<=MAXN; i++ ) {
            scanf( "%s", chess[i]+1 );
        }
        char s[5];
        cin >> opColor;
        while( true ) {
            cin >> s;
            if( s[0] == 'L' ) {
                List(); // 列出所有能摆放棋子的位置
            } else if( s[0] == 'M' ) {
                if( CanPlaced( s[1]-'0', s[2]-'0' ) ) { // 这里能否放棋子
                    Move( s[1]-'0', s[2]-'0' );
                } else {
                    opColor = oppoColor[ opColor ]; // 如果不能，由另外一名选手摆放（题目中已阐明当前无法放时，另一名选手必定能放）
                    Move( s[1]-'0', s[2]-'0' );
                }
                opColor = oppoColor[ opColor ];
            } else if( s[0] == 'Q' ) {
                PrintChess(); // 打印棋盘
                break;
            }
        }
        if( T ) {
            printf( "\n" );
        }
    }
    return 0;
}
