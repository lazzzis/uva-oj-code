// #include <bits/stdc++.h>
// http://www.cppblog.com/y346491470/articles/155318.html
// http://blog.csdn.net/hackerwin7/article/details/16879931
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node{
    int value, vis;
    Node(){}
    Node(int v){value = v; vis = 0;}
    friend bool operator < (const Node& a, const Node& b) {
        return a.value > b.value;
    }
};
int N, maxLen, sum;
vector<Node> v;

void Read() {
    int tmp;
    sum = maxLen = 0;
    v.clear();
    for(int i=0; i<N; ++ i) {
        cin >> tmp;
        v.push_back(Node(tmp));
        sum += tmp;
        maxLen = maxLen > tmp ? maxLen : tmp;
    }
}

bool QuickJudge(int needLen) {
    size_t i, j;
    for(i=0; i<v.size(); i++) {
        if(!v[i].vis) {
            break;
        }
    }
    for(j=v.size()-1; j>=i; j--) {
        if(!v[j].vis) {
            break;
        }
    }
    return i<j && v[i].value!=needLen && v[i].value + v[j].value > needLen;
}

bool Dfs(int pos, int leftLen, int needLen, int counter) {
    leftLen -= v[pos].value;
    if(!leftLen) {
        counter --;
        if(!counter) {
            return true;
        }
        if(QuickJudge(needLen)) {
            return false;
        }
        leftLen = needLen;
        pos = 0;
    }
    for(size_t i=pos + 1; i<v.size() && v[i].value<=leftLen; ++ i) {
        if(!v[i].vis) {
            if(i && v[i].value == v[i-1].value && !v[i-1].vis) {
                continue;
            }
            v[i].vis = 1;
            if(Dfs(i, leftLen, needLen, counter)) {
                return true;
            } else if(leftLen == needLen) {
                v[i].vis = 0;
                return false;
            }
            v[i].vis = 0;
        }
    }
    return false;
}

int ans;
void Done() {
    // descend
    sort(v.begin(), v.end());
    for(int i=maxLen; i<sum ;++i) {
        if(sum % i == 0) {
            v[0].vis = 1;
            if(Dfs(0, i, i, sum / i)) {
                ans = i;
                return ;
            }
            v[0].vis = 0;
        }
    }
    ans = sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> N && N) {
        Read();
        Done();
        cout << ans << endl;
    }
    return 0;
}