// #include <bits/stdc++.h>

// using namespace std;

// typedef long long LL;

// const int MAXN = 800000 + 50;
// struct Job {
//     int day, due, end_day;
// };
// Job jobs[MAXN];
// int dp[MAXN], N;

// void read() {
//     cin >> N;
//     for (int i = 0; i < N; ++i) {
//         cin >> jobs[i].day >> jobs[i].due;
//     }
// }

// void work() {
//     memset(dp, 0, sizeof(dp));
//     for (int i = 0; i < N; ++i) {
//         int max_job = 0;
//         int min_day = 0;
//         for (int j = 0; j < i; ++j) {
//             if(jobs[j].end_day + jobs[i].day > jobs[i].due) {
//                 continue;
//             }
//             if (max_job < dp[j]) {
//                 max_job = dp[j];
//                 min_day = jobs[j].end_day;
//             } else if (max_job == dp[j]) {
//                 min_day = min(jobs[j].end_day, min_day);
//             }
//         }
//         dp[i] = max_job + 1;
//         jobs[i].end_day = min_day + jobs[i].day;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int T;
//     cin >> T;
//     while (T --) {
//         read();
//         work();
//         int ans = 1;
//         for (int i = 0; i < N; ++i) {
//             // cout << i << " : " << dp[i] << " : " << jobs[i].end_day << endl;
//             ans = max(ans, dp[i]);
//         }
//         cout << ans << endl;
//         if (T) {
//             cout << endl;
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct Job {
    int day, due, line; // line = due - day
    friend bool operator < (const Job& a, const Job& b) {
        return a.line < b.line;
    }
};

const int MAXN = 800000 + 50;
Job jobs[MAXN];
int N;

void read() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> jobs[i].day >> jobs[i].due;
        jobs[i].line = jobs[i].due - jobs[i].day;
    }
}

int ans;
void work() {
    sort(jobs, jobs + N);
    ans = 0;
    int end_line = jobs[N - 1].due;
    for (int i = N - 1; i >= 0; --i) {
        if (jobs[i].due >= end_line && end_line - jobs[i].day >= 0) {
            end_line = end_line - jobs[i].day;
            ++ ans;
        }
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T --) {
        read();
        work();
        cout << ans << endl;
        if (T) {
            cout << endl;
        }
    }
    return 0;
}