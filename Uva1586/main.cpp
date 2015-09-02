#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>

using namespace std;

const int MAXN = 80 + 10;
char s[MAXN];

// c从此位置开始有几个连续的'O'
int getAmount( char **p ) { // 写 char *p 程序会出错
    int sum = 0;
    while( isdigit(**p) && (**p)!='\0' ) {
        sum = sum*10 + ( **p - '0' );
        (*p) ++;
    }
    return sum;
}

double getAtomWeight( char c ) {
    switch( c ) {
        case 'C' :
            return 12.01;
        case 'H':
            return 1.008;
        case 'O':
            return 16.00;
        case 'N':
            return 14.01;
    }
}

int main() {
    double counter;
    int T;
    cin >> T;
    while( T-- ) {
        cin >> s;
        char *p = s;
        counter = 0;
        char atom;
        while( *p!='\0' ) {
            if( isdigit( *p ) ) {
                counter = counter + getAtomWeight( atom ) *( getAmount( &p ) - 1 );
                // 此处不能再跟 p ++, 因为在上一函数里已经移动了 指针p
                // 可能此时 p 已指向'\0', 再加 p ++可能出错
//               cout << counter << endl;
            } else {
                atom = *p;
                counter = counter + getAtomWeight( atom );
                p ++;
            }
        }
        printf( "%.3lf\n", counter );
    }
    return 0;
}
