#include <bits/stdc++.h>

using namespace std;

int Find(string &line, int len) {
    size_t i, j;
    if((size_t) len > line.length()/2) {
        return false;
    }
    for(i=len; i<=line.length()-len; i += len ) {
        for(j = i; j < i + len; ++ j) {
            if(line[j - i] != line[j]) {
                break;
            }
        }
        if(j != i + len) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) {
        string line;
        cin >> line;
        size_t i;
        bool found = false;
        for(i=1; i<line.length(); ++ i) {
            if(line[i] == line[0] && line.length() % i == 0 && Find(line, i)) {
                found = true;
                cout << i << endl;
                break;
            }
        }
        if(!found) {
            cout << line.length() << endl;
        }
        if(T) {
            cout << endl;
        }
    }
    return 0;
}