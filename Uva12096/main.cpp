#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

typedef set<int> Set;
map < Set, int > IDcache;
vector < Set > SetCache;
stack <int> st;

void Init() {
    IDcache.clear();
    SetCache.clear();
}

int GetId( Set x ) {
    if( IDcache.count( x ) ) { 
        return IDcache[ x ];
    }
    SetCache.push_back( x );
    return IDcache[ x ] = SetCache.size() - 1;
}

int main() {
    int T;
    cin >> T;
    while( T-- ) {
        Init();
        int N;
        cin >> N;
        string op;
        while( N-- ) {
            cin >> op;
            if( op=="PUSH" ) {
                st.push( GetId( Set() ) );
            } else if( op == "DUP" ) {
                st.push( st.top() );
            } else {
                Set x1 = SetCache[st.top()];
                st.pop();
                Set x2 = SetCache[st.top()];
                st.pop();
                Set x;
                if( op == "UNION" ) {
                    set_union( ALL(x1), ALL(x2), INS(x) ) ;
                } else if( op == "INTERSECT" ) {
                    set_intersection( ALL(x1), ALL(x2), INS(x) );
                } else if( op == "ADD" ) {
                    x = x2;
                    x.insert( GetId( x1 ) );
                }
                st.push( GetId(x) );
            }
            cout << SetCache[ st.top() ].size() << endl;
        }
        cout << "***" << endl;
    }
    return 0;
}
