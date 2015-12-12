#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> pr_int;

int N;
vector<LL> v;
const int MAXN = 100000 + 50;
int left_min[MAXN], right_min[MAXN];

void read() {
    v.clear();
    for (int i = 0; i < N; ++ i) {
        LL t;
        cin >> t;
        v.push_back(t);
    }
}

void work() {
    stack<pr_int> st;

    // left
    st.push(make_pair(-1, -10e7));
    for (int i = 0; i < N; ++ i) {
        while (st.top().second >= v[i]) {
            st.pop();
        }
        left_min[i] = st.top().first;
        st.push(make_pair(i, v[i]));
    }
   
    // right
    while(!st.empty()) {
        st.pop();
    }
    st.push(make_pair(N, -10e7));
    for (int i = N - 1; i >= 0; -- i) {
        while (st.top().second >= v[i]) {
            st.pop();
        }
        right_min[i] = st.top().first;
        st.push(make_pair(i, v[i]));
    }
    
    vector<LL> sum;
    sum.push_back(v[0]);
    for (int i = 1; i < N; ++ i) {
        sum.push_back(v[i] + sum[i - 1]);
    }
    int lr, rr;
    LL ans = 0;
    for (int i = 0; i < N; ++ i) {
        //cout << left_min[i] << " " << right_min[i] << endl;
        LL sumL = left_min[i] == -1 ? 0 : sum[left_min[i]];
        if ( (sum[right_min[i] - 1] - sumL) * v[i] > ans ) {
            ans = (sum[right_min[i] - 1] - sumL) * v[i];
            lr = left_min[i] + 1 + 1;
            rr = right_min[i];
        } else if ((sum[right_min[i] - 1] - sumL) * v[i] == ans && right_min[i] - left_min[i] < rr - lr + 2 ) {
            lr = left_min[i] + 2;
            rr = right_min[i];
        }
    }
    if (ans == 0) {
        cout << "0\n1 1" << endl;
    } else {
        cout << ans << endl << lr << " " << rr << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int K = 0;
    while(cin >> N) {
        if (K) {
            cout << endl;
        }
        K = 1;
        read();
        work();
    }
    return 0;
}
