/**
 * AC @ Sep 7th 2015
 * Run Time : 0.023s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10e5 + 50;
int len[MAXN];
int N, LENGTH;

void read() {
    cin >> N >> LENGTH;
    for (int i = 0; i < N; ++i) {
        cin >> len[i];
    }
}

void work() {
    read();
    sort(len, len + N);
    int head = 0, tail = N - 1;
    int counter = 0;
    while (head < tail) {
        if (len[head] + len[tail] <= LENGTH) {
            ++ head;
            -- tail;
        } else {
            -- tail;
        }
        ++ counter;
    }
    if (head == tail) {
        ++ counter;
    }
    cout << counter << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T --) {
        work();
        if (T) {
            cout << endl;
        }
    }
    return 0;
}