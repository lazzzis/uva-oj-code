/*
    UvaOJ 12657
    Emerald
    Tue 19 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct Node{
    int left, right;
};

const int MAXN = 100000 + 50;
Node ball[MAXN];

// four commands
const int LEFT = 1;
const int RIGHT = 2;
const int SWAP = 3;
const int RESERVE = 4;

void Init( const int& N ) { // init, to make the list
    for( int i=1; i<=N+10; i++ ) {
        ball[ i-1 ].right = i;
        ball[ i ].left = i-1;
    }
}

void Out( int &x ) { // move the x outside
    ball[ ball[x].left ].right = ball[x].right;
    ball[ ball[x].right ].left = ball[x].left;
}

void PutLeft( int &x, int &y ) { // put x to the left if y
    if( ball[y].left == x ) {
        return ;
    }
    Out( x );
    ball[ x ].left = ball[ y ].left;
    ball[ x ].right = y;
    ball[ ball[y].left ].right = x;
    ball[ y ].left = x;
}

void PutRight( int& x, int& y ) { // put x to the right of y
    if( ball[y].right == x ) {
        return ;
    }
    Out(x);
    ball[x].left = y;
    ball[x].right = ball[y].right;
    ball[ ball[y].right ].left = x;
    ball[y].right = x;
}

long long GetOddPosSum( int& N ) { // the sum of elements in the odd position
    bool odd = true;
    long long sum = 0;
    int j = ball[0].right;
    for( int i=1; i<=N; i++ ) {
    // for( int i=1; i<=N; i++ ) {
        if( odd ) {
            sum += j;
        }
        j = ball[ j ].right;
        odd = !odd;
    }
    return sum;
}

int main() {
    int N, opAmount, caseCounter = 0; // the total elem, the total op, the counter of case
    while( scanf( "%d%d", &N, &opAmount )!=EOF ) {
        Init( N );
        bool reserve = false;
        int op;
        while( opAmount -- ) {
            scanf( "%d", &op ); // read the operation
            if( op == RESERVE ) {
                reserve = !reserve;
            } else {
                int x, y;
                scanf( "%d%d", &x, &y );
                if( op == SWAP ) {
                    // here is where the bug is
                    // the 'if' is neccessary
                    if( ball[ y ].right == x ) {
                        PutRight( y, x );
                        continue;
                    } else {
                        int l = ball[x].left; // the original left
                        PutLeft( x, y ); // move x first
                        PutRight( y, l ); // move y then
                        continue;
                    }
                }
                if( ( !reserve && op==LEFT ) || ( reserve && op==RIGHT ) ) {
                    PutLeft( x, y );
                } else {
                    PutRight( x, y );
                }
            }
        }
        long long oddSum = GetOddPosSum( N );
        printf( "Case %d: %lld\n", ++caseCounter, (reserve && (N&1)==0 ) ? (long long)(1+N)*N/2 - oddSum : oddSum );
    }
    return 0;
}