/**
 * the target is ascended
 */
#include <bits/stdc++.h>

using namespace std;

std::vector<int> v, target;

bool read() {
    string line;
    if(getline(cin, line)) {
        stringstream ss(line);
        v.clear();
        int tmp;
        while(ss >> tmp) {
            v.push_back(tmp);
        }
        return true;
    }
    return false;
}

int find_max_pos(int end) {
    int maxN = v[0], pos = 0;
    for(int i=0; i<end; ++ i) {
        if(maxN < v[i]) {
            maxN = v[i];
            pos = i;
        }
    }
    return pos;
}

bool cmp() {
    for(size_t i=0; i<v.size(); ++ i) {
        if(v[i] != target[i]) {
            return false;
        }
    }
    return true;
}

void swap_elem(int end) {
    for(int i=0; i<ceil(end/2); ++i) {
        int t = v[i];
        v[i] = v[end - 1 - i];
        v[end - 1 - i] = t;
    }
}

void solve(int end) {
    if(cmp()) {
        return ;
    }
    int pos = find_max_pos(end);
    if(pos != 0) {
        cout << (v.size() - pos) << " ";
        swap_elem(pos + 1);
    }
    cout << v.size() - (end - 1) << " ";
    swap_elem(end);
    solve(end - 1);
}

void work() {
    for(size_t i=0; i<v.size()-1; ++ i) {
        cout << v[i] << " ";
    }
    cout << v.back() << endl;
    target.clear();
    target = v;
    sort(target.begin(), target.end());
    solve((int)v.size());
    cout << "0" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(read())
        work();
    return 0;
}