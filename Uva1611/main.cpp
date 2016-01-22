/**
 * AC @ Sep 16th 2015
 * Run Time : 0.322s
 */
#include <bits/stdc++.h>

using namespace std;

typedef std::pair<int, int> Node;
vector<int> crane_vec;
vector< Node > ans;
int N;

int search(vector<int> &lst, int value) {
    for (vector<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        if (*it == value) {
            return it - lst.begin();
        }
    }
    return -1;
}

void read() {
    crane_vec.clear();
    ans.clear();
    // ensure that the first element is counted from 1
    ans.push_back(make_pair(0, 0));
    crane_vec.push_back(-1);

    cin >> N;
    int tmp;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        crane_vec.push_back(tmp);
    }
}

// swap from start to end as the problem tells
void swap(int start, int end) {
    ans.push_back(make_pair(start, end));
    int mid = (start + end) >> 1;
    for (int i = start; i <= mid; ++i) {
        int t = crane_vec[i];
        crane_vec[i] = crane_vec[mid  + 1 + i - start];
        crane_vec[mid  + 1 + i - start] = t;
    }
}

void done() {
    int target;
    while(N > 1) {
        if (crane_vec[N] != N) {
            target = search(crane_vec, N);
            // fr : the useless element(s) before N
            // bk : the useless element(s) between  N and the last element in crane_vec
            int fr = target - 1;
            int bk = N - target - 1;
            if (fr < bk) {
                // odd or even : the seap operation must need even elements
                swap(1, N & 1 ? N - 1 : N - 2);

                target = search(crane_vec, N);
                fr = target - 1;
                bk = N - 1 - target;
            }
            swap(N - 2 * bk - 1, N);
        }
        N --;
    }
}

void out() {
    cout << ans.size() - 1<< endl;
    for (vector< Node >::iterator it = ans.begin() + 1; it != ans.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

void work() {
    read();
    done();
    out();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T --) {
        work();
    }
    return 0;
}