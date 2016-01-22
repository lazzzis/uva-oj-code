/**
Run Time : 0.073s
AC @ Oct 24th 2015
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 50;

int T, N;
vector<int> empl[MAXN];

bool read() {
    if (! (cin >> N >> T) || !(N + T)) {
        return false;
    }
    for (int i = 0; i < N + 1; ++ i) {
        empl[i].clear();
    }
    int t;
    for (int i = 1; i < N + 1; ++ i) {
        cin >> t;
        empl[t].push_back(i);
    }
    return true;
}

int search(int id) {
    if(empl[id].size() == 0) {
        return 1;
    }
    vector<int> v;
    for (int i = 0; i < (int) empl[id].size(); ++ i) {
        v.push_back(search(empl[id][i]));
    }
    sort(v.begin(), v.end());
    int limit = (int) ceil(T / 100.0 * (int)empl[id].size());
    int sum = 0;
    for (int i = 0; i < limit; ++ i) {
        sum += v[i];
    }
    return sum;
}

void work() {
    cout << search(0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(read()) {
        work();
    }
    return 0;
}