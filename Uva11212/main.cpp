#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10 + 5;
const int MAXSIZE = 4000000 + 20;

int N, ans = 0, maxD;
int text[MAXSIZE][MAXN];
int rear;

void Test(int pos) {
    for(int i = 1; i < N + 1; ++ i) {
        cout << text[pos][i] << " ";
    }
    cout << endl;
}

set<long long> hashSet;
bool Hash(int pos) {
    long long value = 0;
    for(int i = 1; i < N + 1; ++ i) {
        value = value * 10 + text[pos][i];
    }
    if(hashSet.count(value)) {
        return true;
    } else {
        hashSet.insert(value);
        return false;
    }
}

void Init() {
    rear = 0;
    ans = 0;
    hashSet.clear();
}

void Move(int i, int j, int k, int rear, int pos) {
    int r = 1;
    if( k < i) {
        for(int loop = 1; loop <= k; ++ loop) {
            text[rear][r++] = text[pos][loop];
        }
        for(int loop = i; loop <= j; ++ loop) {
            text[rear][r++] = text[pos][loop];
        }
        for(int loop = k+1; loop < i; ++ loop) {
            text[rear][r++] = text[pos][loop];
        }
        for(int loop = j+1; loop < N + 1; ++ loop) {
            text[rear][r++] = text[pos][loop];
        }
    } else {
        for(int loop = 1; loop < i; ++ loop) {
            text[rear][r++] = text[pos][loop];
        }
        for(int loop = j+1; loop <= k; ++ loop) {
            text[rear][r++] = text[pos][loop];
        }
        for(int loop = i; loop <= j; ++ loop) {
            text[rear][r++] = text[pos][loop];
        }
        for(int loop = k+1; loop < N + 1; ++ loop) {
            text[rear][r++] = text[pos][loop];
        }
    }
}

int CalChoas(int pos) {
    int c = 0;
    for(int i=1; i<N; i++) {
        c = c + (text[pos][i] != (text[pos][i+1]-1));
    }
    return c;
}

void Dfs(int depth, int pos, int choas) {
   // cout << depth << " " << pos << " " << choas << endl;
    if(choas == 0) {
        if(ans) {
            ans = ans < depth ? ans : depth;
        } else {
            ans = depth;
        }
        return ;
    }
    // b : i ~ j
    // insert point : k
    for(int i = 1; i<N+1; i++) {
        for(int j = i; j < N + 1; ++ j) {
            for(int k = 0; k < N + 1; ++ k) {
                if(k >= i-1 && k <=j) {
                    continue;
                }
                Move(i ,j, k, rear, pos);
                int c = CalChoas(rear);
                if( 3 * (depth+1) + c <= 3 * maxD && !Hash(rear)) {
                    // cout << c << " " << depth << endl;
                    // Test(rear);
                    rear ++;
                    Dfs(depth + 1, rear - 1, c);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int Counter = 0;
    while(cin >> N && N) {
        Init();
        for(int i = 1; i < 1 + N; ++ i) {
            cin >> text[rear][i];
        }
        int choas = CalChoas(rear);
        rear ++;
        maxD = 0;
        if(choas) {
            for(maxD = 1; ; ++ maxD) {
                Init();
                rear ++;
                Dfs(0, 0, choas);
                if(ans) {
                    break;
                }
            }
        }
        cout << "Case " << (++Counter) << ": " << maxD << endl;
    }
    return 0;
}