#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

struct Student {
    int await, sleep;
    int current;
};

vector<Student> v;
int N;

void init() {
    v.clear();
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
