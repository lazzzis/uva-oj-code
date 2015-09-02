/*
    UvaOJ 127
    Emerald
    Fri 31 Jul 2015
 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

struct Pile{
    std::vector<string> v;
    int left, right;
};

const int MAXN = 52 + 5;
Pile pile[MAXN];

bool Read() {
    string card;
    pile[0].right = 1;
    pile[53].left = 52;
    for(int i=1; i<52 + 1; i++) {
        cin >> card;
        if(card=="#") {
            return false;
        }
        pile[i].left = i - 1;
        pile[i].right = i + 1;
        pile[i].v.clear();
        pile[i].v.push_back(card);
    }
    return true;
}

int Back(int start, int step) {
    while(start > 0 && step) {
        start = pile[start].left;
        step --;
    }
    return start > 0 ? start : -1;
}

bool Match(string &a, string &b) {
    return (a[0] == b[0]) || (a[1] == b[1]);
}

void Put(int former, int pos) {
    pile[former].v.push_back( pile[pos].v.back() );
    pile[pos].v.erase( pile[pos].v.end()-1 );
    if(pile[pos].v.size() == 0) {
        pile[ pile[pos].left ].right = pile[pos].right;
        pile[ pile[pos].right ].left = pile[pos].left;
    }
}

void Move() {
    int pos = 1;
    while(pos!=53) {
        int former = Back(pos, 3);
        if(former != -1 && Match( pile[former].v.back(), pile[pos].v.back() ) ) {
            Put( former, pos );
            pos = former;
            continue;   
        }
        former = Back(pos, 1);
        if(former != -1 && Match( pile[former].v.back(), pile[pos].v.back() ) ) {
            Put( former, pos );
            pos = former;
            continue;
        }
        pos = pile[pos].right;
    }
}

void Print() {
    int pos = 0;
    std::vector<int> result;
    while(pile[pos].right!=53) {
        pos = pile[pos].right;
        result.push_back( pile[pos].v.size() );
    }
    printf("%d pile%s remaining:", (int)result.size(), result.size() > 1 ? "s":"");
    for(int i=0; i<(int)result.size(); i ++) {
        printf(" %d", result[i]);
    }
    printf("\n");
}

int main() {
    while( Read() ){
        Move();
        Print();
    }
    return 0;
}