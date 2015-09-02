#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 18 + 5;
int s[MAXN];

int main() {
    int N, Case = 0;
    while(cin >> N) {
        long long ans = 0;
        for(int i=0; i<N; i++) {
            scanf("%d", &s[i]);
            long long product = 1;
            for(int j=i; j>=0; j--) { // j is the start, and i is the end
                product *= s[j];
                ans = product > ans ? product : ans;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", ++ Case, ans);
    }
    return 0;
}