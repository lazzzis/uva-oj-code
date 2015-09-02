/**
 * UvaOJ 11059
 * Emerald
 * Sat 4 Jul 2015
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 18 + 5;
long long table[MAXN][MAXN];

int main() {
    int N, counter = 0;
    while( cin >> N ) {
        long long tmp, ans = 0;
        for( int i=1; i<=N; i++ ) {
            scanf( "%lld", &tmp );
            for( int j=1; j<i; j++ ) {
                table[j][i] = table[j][i-1] * tmp;
                ans = ans > table[j][i] ? ans : table[j][i];
            }
            table[i][i] = tmp;
            ans = ans > table[i][i] ? ans : table[i][i];
        }
        printf("Case #%d: The maximum product is %lld.\n\n", ++counter, ans );
    }
    return 0;
}