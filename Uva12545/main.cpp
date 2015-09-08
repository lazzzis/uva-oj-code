/**
 * AC @ Sep 8th 2015
 * Run Time : 0.000s
 */
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    string s1, s2;
    int zero, one, qu0, qu1, ans;
    for (int loop = 1; loop < T + 1; ++loop) {
        cin >> s1 >> s2;
        zero = one = qu0 = qu1 = ans = 0;
        for (size_t i = 0; i < s1.length(); ++i) {
            if (s1[i] == '?' && s2[i] == '1') {
                ++ qu1;
            } else if (s1[i] == '?' && s2[i] == '0') {
                ++ qu0;
            } else if (s1[i] != s2[i] && s2[i]=='1') {
                ++ one;
            } else if (s1[i] != s2[i] && s2[i]=='0') {
                ++ zero;
            }
        }

        if (zero > one) {
            if (zero > one + qu1) {
                ans = -1;
            } else {
                ans = qu0 + qu1;
                ans += one;
                ans += min(qu1, zero - one);
            }
        } else if (zero == one) {
            ans = qu0 + qu1 + zero;
        } else if (zero < one) {
            ans = qu0 + qu1;
            ans += zero;
            ans += (one - zero);
        }
        cout << "Case " << loop << ": " << ans << endl;
    }
    return 0;
}