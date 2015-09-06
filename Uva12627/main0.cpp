/**
 * AC @ Sep 6th 2015
 * Run Time : 0.003s
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL A, B, K;

LL under(int k, int line) {
    // cout << k << " " << line << endl;
    if (line == 0) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    if (line < (1 << (k-1))) {
        return under(k-1, line);
    } else {
        return 2 * under(k-1,  line - (1 << (k-1))) + pow(3, k - 1);
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, Case = 0;
    cin >> T;
    while (T --) {
        cin >> K >> A >> B;    
        cout << "Case " << (++ Case) <<": " << 
            under(K, (1 << K) - A + 1) - under(K, (1 << K) - B) << endl;
    }
    return 0;
}