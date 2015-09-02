#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 80 + 10;
char s[MAXN];

// c从此位置开始有几个连续的'O'
int getSubScore( char **p ) { // 写 char *p 程序会出错
    int counter = 0;
    int i = 0;
    while( **p=='O' && **p!='\0' ) {
        i ++;
        counter += i;
        (*p) ++;
    }
    return counter;
}

int main() {
    int counter;
    int T;
    cin >> T;
    while( T-- ) {
        cin >> s;
        char *p = s;
        counter = 0;
        while( *p!='\0' ) {
            if( *p == 'O' ) {
                counter += getSubScore( &p );
                // 此处不能再跟 p ++, 因为在上一函数里已经移动了 指针p
                // 可能此时 p 已指向'\0', 再加 p ++可能出错
            } else {
                p ++;
            }
        }
        cout << counter << endl;
    }
    return 0;
}
