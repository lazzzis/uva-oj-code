/*
    UvaOJ 1589
    Emerald
    20 Apr, 2015
*/
/*Wrong Answer*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 14;
bool piece[MAXN][MAXN]; // is here a piece
bool vis[MAXN][MAXN]; // the position that black general whill be attack
const int MAX_X = 10;
const int MAX_Y = 9;

typedef struct Node{
    char type;
    int x, y;
}Node;
Node chess[MAXN];

bool inGrid(int x, int y) {
    return x>=1 && x<=3 && y>=4 && y<=6;
}

void Init() {
    memset( piece, false, sizeof(piece) );
    memset( vis, false, sizeof(vis) );
}
// General
void moveG( int x, int y ) {
    int i;
    for( i=x-1; i>=1 && !piece[i][y]; i-- ) {
        if(inGrid(i, y)) {
            vis[i][y] = true;
        }
    }
}
// Chariot
void moveR( int x, int y ) {
    int i;
    for( i=x-1; i>=1 && !piece[i][y]; i-- ) { // up
        if(inGrid(i, y)) vis[i][y] = true;
    }
    for( i=x+1; i<=MAX_X && !piece[i][y]; i++ ) { // down
        if(inGrid(i, y)) vis[i][y] = true;
    }
    for( i=y+1; i<=MAX_Y && !piece[x][i]; i++ ) { // right
        if(inGrid(x, i)) vis[x][i] = true;
    }
    for( i=y-1; i>=1 && !piece[x][i]; i-- ) { // left
        if(inGrid(x, i)) vis[x][i] = true;
    }
}
// Horse
void moveH( int x, int y ) {
    if( x-2>=1 && y-1>=1 && !piece[x-1][y] ) { 
        if(inGrid(x-2, y-1)) vis[x-2][y-1] = true;
    } // up
    if( x-2>=1 && y+1<=MAX_Y && !piece[x-1][y] ) {
        if(inGrid(x-2, y+1)) vis[x-2][y+1] = true;
    }
    
    if( x+2<=MAX_X && y-1>=1 && !piece[x+1][y] ) {
        if(inGrid(x+2, y-1)) vis[x+2][y-1] = true;
    } // down
    if( x+2<=MAX_X && y+1<=MAX_Y && !piece[x+1][y] ) {
        if(inGrid(x+2, y+1)) vis[x+2][y+1] = true;
    }
    
    if( x+1<=MAX_X && y+2<=MAX_Y && !piece[x][y+1] ) {
        if(inGrid(x+1, y+2)) vis[x+1][y+2] = true;
    } // right
    if( x-1>=1 && y+2<=MAX_Y && !piece[x][y+1] ) {
        if(inGrid(x-1, y+2)) vis[x-1][y+2] = true;
    }
    
    if( x+1<=MAX_X && y-2>=1 && !piece[x][y-1] ) {
        if(inGrid(x+1, y-2)) vis[x+1][y-2] = true;
    } // left
    if( x-1>=1 && y-2>=1 && !piece[x][y-1] ) {
        if(inGrid(x-1, y-2)) vis[x-1][y-2] = true;
    }
}
// Cannon
void moveC( int x, int y ) {
    int i = x - 1;
    while( i>=1 && !piece[i][y] ) {
        i --;
    }
    i --;
    while( i>=1 && !piece[i][y] ) {
        if(inGrid(i, y)) vis[i][y] = true;
        i --;
    }
    // -------------- down
    i =  x + 1;
    while( i<=MAX_X && !piece[i][y] ) {
        i ++;
    }
    i ++;
    while( i<=MAX_X && !piece[i][y] ) {
        if(inGrid(i, y)) vis[i][y] = true;
        i ++;
    }
    // -------------- left
    i = y - 1;
    while( i>=1 && !piece[x][i] ) {
        i --;
    }
    i --;
    while( i>=1 && !piece[x][i] ) {
        if(inGrid(x, i)) vis[x][i] = true;
        i --;
    }
    
    // -------------- right
    i = y + 1;
    while( i<=MAX_Y && !piece[x][i] ) {
        i ++;
    }
    i ++;
    while( i<=MAX_Y && !piece[x][i] ) {
        if(inGrid(x, i)) vis[x][i] = true;
        i ++;
    }
}

void move( Node c ) {
    if( c.type=='G' ) {
        moveG( c.x, c.y );
    } else if( c.type=='R' ) {
        moveR( c.x, c.y );
    } else if( c.type=='H' ) {
        moveH( c.x, c.y );
    } else if( c.type == 'C' ) {
        moveC( c.x, c.y );
    }
}

bool judge( int x, int y ) {
    if( x-1 >=1 && !vis[ x-1 ][y] ) {
        return true;
    }
    if( x+1 <=3 && !vis[ x+1 ][y] ) {
        return true;
    }
    if( y-1 >=4 && !vis[x][ y-1 ] ) {
        return true;
    }
    if( y+1 <= 6 && !vis[x][y+1]  ) {
        return true;
    }
    return false;
}

void Print( ) {
    int i, j;
    for( i=1; i<=MAX_X; i++ ) {
        for( j=1; j<=MAX_Y; j++ ) {
            printf( "%3d", vis[i][j] );
        }
        printf( "\n" );
    }
    printf( "\n" );
}

int main() {
    int N, gx, gy;
    while( scanf( "%d%d%d", &N, &gx, &gy ) != EOF ) {
        if( N==0 && N==gx && gx==gy ) {
            break;
        }
        int i;
        Init();
        for( i=0; i<N; i++ ) {
            cin >> chess[i].type >> chess[i].x >> chess[i].y;
            piece[ chess[i].x ][ chess[i].y ] = true;
        }
        for( i=0; i<N; i++ ) {
            move( chess[i] );
           // Print( );
        }
        if( judge( gx, gy ) ) {
            printf( "NO\n" );
        } else {
            printf( "YES\n" );
        }
    }
    return 0;
}
