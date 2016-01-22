/**
 * AC @ Sep 8th 2015
 * Run Time : 0.049s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10e5 + 50;
int N, D;
int l[MAXN], r[MAXN];
// l[i]; the nearest pos bigger than digits[i] on the left
// r[i]; the nearest pos bigger than digits[i] on the right
string digits;
std::vector<int> ans;

void init() {
    int hash[15]; // right
    for (int i = 0; i < 15; ++i) {
        hash[i] = MAXN;
    }
    for (int i = N-1; i >= 0; --i) {
        int tmp = MAXN;
        for (int j = digits[i]- '0' + 1; j < 10; ++j) {
            tmp = min(hash[j], tmp);
        }
        hash[digits[i]- '0'] = i;
        r[i] = tmp;
    }
    memset(hash, -1, sizeof(hash)); // left
    for (int i = 0; i < N; ++i) {
        int tmp = -1;
        for (int j = digits[i]-'0' + 1; j < 10; ++j) {
            tmp = max(hash[j], tmp);
        }
        hash[digits[i]- '0'] = i;
        l[i] = tmp;
    }
}

void find(int start, int d) {
    if (!d) {
        return ;
    }
    int i;
    for(i = start; i <= N - d; ++ i) {
        if (l[i] < start && r[i] > N-d) {
            break;
        }
    }
    ans.push_back(digits[i]-'0');
    find(i+1, d-1);
}

void work() {
    init();
    ans.clear();
    find(0, N-D);
    for (std::vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
        cout << *it;
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> N >> D && (N + D)) {
        cin >> digits;
        work();
    }
    return 0;
}