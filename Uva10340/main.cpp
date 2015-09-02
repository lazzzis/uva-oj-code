/*
    UvaOJ10340
    Emerald
    Sun 19 Apr, 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    string first, sec;
    int len1, len2;
    int i, j;
    while( cin >> first >> sec ) {
        len1 = first.length();
        len2 = sec.length();
        i = j = 0;
        while( i<len1 && j<len2 ) {
            if( first[i]==sec[j] ) {
                i ++;
            }
            j ++;
        }
        if( i==len1 ) {
            printf( "Yes\n" );
        } else {
            printf( "No\n" );
        }
    }
    return 0;
}
