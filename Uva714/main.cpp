/**
 * AC @ Sep 5 th 2015
 * Run Time : 0.000s
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN = 500 + 50;
int value[MAXN];
int M, K;
LL sum, maxC;

void read() {
    cin >> M >> K;
    sum = maxC = 0;
    for (int i = 0; i < M; ++i) {
        cin >> value[i];
        sum += value[i];
        maxC = maxC > value[i] ? maxC : value[i];
    }
}

bool is_possile(int p) {
    int tmpValue = 0, group = 1;
    for (int i = M-1; i >= 0; --i) {
        if (tmpValue + value[i] > p || i+1 <= K - group) {
            tmpValue = value[i];
            group ++;
        } else {
            tmpValue += value[i];
        }
    }
    return group == K;
}

void print(int pos, int group, int p) {
    std::vector<int> v;
    int i;
    LL sum = 0;
    for (i = pos; sum + value[i] <= p && i+1>K-group; --i) {
        sum += value[i];
        v.push_back(value[i]);
    }
    if (group == K) { // the head
        for (int l = v.size()-1; l > 0; --l) {
            cout << v[l] << " ";
        }
        cout << v[0];
    } else {
        print(i, group+1, p);
        cout << " /";
        for (int l = v.size()-1; l >= 0; --l) {
            cout << " " << v[l];
        }
    }
}

void output(int p) {
    print(M-1, 1, p);
    cout << endl;
}

void work() {
    LL left = maxC, right = sum, mid;
    while (right > left) {
        mid = (right + left) >> 1;
        // cout << left << " " << right << " " << mid << endl;
        if (is_possile(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    // cout << right << endl;
    output(right);
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);        
    cin.tie(0);
    int T;
    cin >> T;
    while (T --) {
        read();
        work();
    }
    return 0;
}