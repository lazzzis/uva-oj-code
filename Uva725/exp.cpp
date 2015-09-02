#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

bool isOkay(int A, int B) {
    int vis[10] = {0};
    for(int i=0; i<5; i++) {
        vis[A%10] ++;
        vis[B%10] ++;
        A /= 10;
        B /= 10;
    }
    for(int i=0; i<10; i++) {
        if( vis[i] != 1 ) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    int Case = 0;
    while(cin >> N && N) {
        if(Case) {
            printf("\n");
        }
        Case ++;
        bool flag = false;
        for(int i=10000 / N >= 1234 ? 10000 / N : 1234; i < ceil(100000 / N); i++) {
            if( isOkay( i*N, i ) ) {
                flag = true;
                printf("%.5d / %.5d = %d\n", i*N, i, N);
            }
        }
        if( !flag ) {
            printf("There are no solutions for %d.\n", N);
        }
    }
    return 0;
}