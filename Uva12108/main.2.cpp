#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;

struct Student {
    int await, sleep;
    int current;
};

vector<Student> v;
set<LL> states;
int N;

void init() {
    v.clear();
    states.clear();
}

LL state() {
    LL temp = 1, ans = 0;
    for_each(v.begin(), v.end(), [&temp, &ans](Student& s)  -> void {
        ans += (s.current - 1) * temp;
        temp *= 10;
    });
    return ans;
}

int sleep() {
    return count_if(v.begin(), v.end(), [](Student& s) {
        return s.current > s.await;
    });
}

int await() {
    return count_if(v.begin(), v.end(), [](Student& s) {
        return s.current <= s.await;
    });
}

LL work() {
    for (int i = 0; i < N; i ++) {
        Student s;
        cin >> s.await >> s.sleep >> s.current;
        v.push_back(s);
    }
    for (int _ = 1; _ < 1000; _ ++) {
        int slp = sleep(), awt = await();
        if (awt == N) {
            return _;
        }
        int s = state();
        if (states.count(s)) {
            return -1;
        }
        states.insert(s);
        for_each(v.begin(), v.end(), [slp, awt](Student& s) {
            if (s.current == s.await + s.sleep) {
                s.current = 1;
            } else if (s.current == s.await) {
                s.current = slp > awt ? s.current + 1 : 1;
            } else {
                s.current ++;
            }
        });
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 0;
    while (cin >> N && N) {
        init();
        cout << "Case " << (++ Case) << ": " << work() << endl;
    }
    return 0;
}
