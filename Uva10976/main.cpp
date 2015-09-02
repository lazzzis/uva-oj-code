/**
 * UvaOJ 10976
 * Emerald
 * Sat 4 Jul 2015
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int k, y;
    while( cin >> k ) {
        std::vector<int> v;
        for( y=k+1; y<2*k+1; y++ ) {
            if( k*y % (y-k) == 0 ) {
                v.push_back(y);
            }
        }
        std::vector<int> :: iterator it;
        cout << v.size() << endl;
        for( it=v.begin(); it!=v.end(); it ++ ) {
            printf("1/%d = 1/%d + 1/%d\n", k, k*(*it)/((*it)-k), *it );
        }
    }
    return 0;
}