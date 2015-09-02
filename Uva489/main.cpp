/*
    UvaOJ 489
    Emerald
    Sun 19 Apr, 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 26 + 5;
bool vis[MAXN];

const int LOSE = 7;

int main() {
    int N;
    string ans, guess;
    int i, len;
    int kinds;
    while( scanf( "%d", &N )!=EOF && N!=-1 ) {
        cin >> ans >> guess;
        memset( vis, false, sizeof(vis) );
        len = ans.length();
        kinds = 0;
        for( i=0; i<len; i++ ) {
            if( !vis[ ans[i]-'a' ] ) {
                vis[ ans[i]-'a' ] = true;
                kinds ++;
            }
        }
        int right, wrong;
        right = wrong = 0;
        len = guess.length();
        for( i=0; i<len && wrong < LOSE && right < kinds; i++ ) {
            if( vis[ guess[i]-'a' ] ) {
                right ++;
                vis[ guess[i]-'a' ] = false;
            } else {
                wrong ++;
            }
        }
        printf( "Round %d\n", N );
        if( right>=kinds ) {
            printf( "You win.\n" );
        } else if( wrong >= LOSE ) {
            printf( "You lose.\n" );
        } else {
            printf( "You chickened out.\n" );
        }
    }
    return 0;
}
