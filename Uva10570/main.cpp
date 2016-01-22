#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500 + 50;
int N, order[MAXN];
int loop_id[MAXN], loops, loop_contain[MAXN];

void read() {
    for (int i = 0; i < N; ++i) {
        cin >> order[i];
    }
}


void right_pos_num(int right_ord, int start, int step, int id) {
        for (int i = 0; i < N; ++i) {
        if (right_ord == N + 1) {
            right_ord = 1;
        } else if(right_ord == 0) {
            right_ord = N;
        }
        if (order[(start + i) % N] == right_ord) {
            loop_id[(start + i) % N] = id;
        }
        right_ord += step;
    }
}

int done(int step) {
    loops = 0;
    memset(loop_id, -1, sizeof(loop_id));
    for (int i = 0; i < N; ++i) {
        if (loop_id[i] == -1) {
            right_pos_num(order[i], i, step, loops ++);
        }
    }
    memset(loop_contain, 0, sizeof(loop_contain));
    for (int i = 0; i < N; ++i) {
        ++ loop_contain[loop_id[i]];
    }
    if (loops == 1) {
        return 0;
    }
    int maxC = loop_contain[0];
    for (int i = 0; i < loops; ++i) {
        maxC = max(maxC, loop_contain[i]);
    }
    return loops - 1;
}

void work() {
    read();
    int ans = done(1);
    if (!ans) {
        cout << 0 << endl;
    } else {
        cout << min(ans, done(-1)) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> N && N) {
        work();
    }
    return 0;
}
/*
8
1 2 4 3 5 6 8 7
8
1 5 2 6 3 7 4 8
*/