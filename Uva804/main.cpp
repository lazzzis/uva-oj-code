#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 100 + 10;
int inSrcAm[MAXN][MAXN];
std::set<int> inSrc[MAXN];
std::vector<int> outDst[MAXN];
int tokens[MAXN];
int NP, NT;
int firings;
int Case = 0;

bool Init() {
    memset(inSrcAm, 0, sizeof(inSrcAm));
    // memset(tokens, 0, sizeof(tokens));
    for(int i=1; i<NT+1; i++) {
        inSrc[i].clear();
        outDst[i].clear();
    }
    return true;
}

void Transition(int t) { 
    // a transition, add tokens to one place or move tokens from one place or do nothing
    set<int> :: iterator it;
    for(it = inSrc[t].begin(); it!=inSrc[t].end(); it ++) {
        tokens[ *it ] -= inSrcAm[t][*it];
    }
    for(int i=0; i<(int)outDst[t].size(); i++) {
        tokens[outDst[t][i]] ++;
    }
}

bool CanBeEnable(int t) {
    set<int> :: iterator it;
    for(it = inSrc[t].begin(); it!=inSrc[t].end(); it ++) {
        if( tokens[*it] < inSrcAm[t][*it] ) {
            return false;
        }
    }
    return true;
}

int SeekForEnable() {
    for(int i=1; i<NT+1; i++) {
        if( CanBeEnable(i) ) {
            return i;
        }
    }
    return -1;
}

bool Read() {
    scanf("%d", &NP);
    if( NP == 0 ) {
        return false;
    }
    for(int i=1; i<NP+1; i++) {
        scanf("%d", &tokens[i]);
    }
    scanf("%d", &NT);
    for(int i=1; i<NT+1; i++) {
        int x;
        while(scanf("%d", &x)!=EOF && x) {
            if( x<0 ) {
                x = -x;
                inSrc[i].insert(x);
                inSrcAm[i][x] ++;
            } else {
                outDst[i].push_back(x);
            }
        }
    }
    scanf("%d", &firings);
    return true;
}

void Print(int step) {
    if( step == firings+1 ) {
        printf("Case %d: still live after %d transitions\n", ++ Case, firings);
    } else {
        printf("Case %d: dead after %d transitions\n", ++Case, step-1);
    }
    printf("Places with tokens:");
    for(int i=1; i<NP+1; i++) {
        if(tokens[i]){
            printf(" %d (%d)", i, tokens[i]);
        }
    }
    printf("\n\n");
}

int main() {
    while(Init() && Read()) {
        int i;
        for( i = 1; i<firings+1; i++ ) {
            int t = SeekForEnable();
            if( t == -1 ) {
                break;
            }
            Transition(t);
        }
        Print( i );
    }
    return 0;
}