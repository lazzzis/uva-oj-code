/**
 * AC @ Sep 18th 2015
 * Run Time : 0.073s
 */
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20000 + 50;
int ord[MAXN];
std::vector<int> score[MAXN];
// count from 1
int N;

void read() {
    double x, y ,z;
    for (int i = 1; i <= N; ++i) {
        cin >> x >> y >> z;
        // the operations about precision is surprisingly vital,
        // especially the round function
        int a = (int)round(x * 100);
        int b = (int)round(y * 100);
        int c = (int)round(z * 100);
        // initialize the score[i] at the same time
        score[i] = {0, a, b, c, a + b, a + c, b + c, a + b + c};
        sort(score[i].begin(), score[i].end());
    }
    for (int i = 1; i <= N; ++i) {
        cin >> ord[i];
    }
}

int find(int id, int value, int former_id) {
    for (int i = (int)score[id].size() - 1; i >= 0; -- i) {
        if (value == score[id][i] && id > former_id) {
            return value;
        } else if (value > score[id][i]) {
            return score[id][i];
        }
    }
    return -1;
}

int done() {
    int guess = score[ord[1]][ score[ord[1]].size() - 1 ];
    for (int i = 2; i <= N; ++i) {
        guess = find(ord[i], guess, ord[i - 1]);
        if (guess == -1) {
            return -1;
        }
    }
    return guess;
}

int Case = 0;
void work() {
    read();
    int ans = done();
    cout << "Case " << (++Case) << ": ";
    if (ans == -1) {
        cout << "No solution" << endl;
    } else {
        cout << fixed << setprecision(2) << (ans / 100.0) << endl;
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> N && N) {
        work();
    }
    return 0;
}