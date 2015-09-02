#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;

struct cmp {
    bool operator () ( const LL a, const LL b ) const { // 返回true代表a的优先级小
            return a > b;
    }
};

int para[3] = { 2, 3, 5 };

int main() {

    priority_queue < LL, vector<LL>, cmp > pq;
    set<LL> s;
    pq.push(1);
    s.insert(1);
    for( int i=0; i<1500-1; i++ ) {
        LL x = pq.top();
        pq.pop();
        for( int j=0; j<3; j++ ) {
            if( !s.count( para[j]*x ) ) {
                pq.push( para[j]*x );
                s.insert( para[j]*x );
            }
        }
    }
    cout << "The 1500'th ugly number is " << pq.top() << "." << endl;
    
    return 0;
}
