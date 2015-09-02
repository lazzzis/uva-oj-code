#include <bits/stdc++.h>

using namespace std;

void Swap(long long& a, long long& b) {
    long long t = a;
    a = b;
    b = t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, S1, V1, S2, V2;
    int T, Case = 0;
    cin >> T;
    while(T --) {
        cin >> N >> S1 >> V1 >> S2 >> V2;
        long long value = 0, maxVal = 0;
        if(S2 * V1 < S1 * V2) {
            Swap(S1, S2);
            Swap(V1, V2);
        }
        for(long long i=0; i<S1 && N - i * S2 >=0; i ++) {
            value = i * V2 + ((N - i * S2) / S1) * V1;
            maxVal = maxVal > value ? maxVal : value;
        }
        cout << "Case #" << (++ Case) <<": " << maxVal << endl;
    }
    return 0;
}