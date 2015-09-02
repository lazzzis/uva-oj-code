#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

int Binary(int depth, int nodes) {
    int order = 1;
    while( order < ( 1 << (depth-1) ) ) {
        if( nodes & 1 ) { // left
            order = order << 1;
            nodes = (nodes+1) >> 1;
        } else { // right
            order = (order << 1) + 1;
            nodes = nodes >> 1;
        }
    }
    return order;
}

int main() {
    int lines;
    int depth, nodes;
    while( cin >> lines ) {
        while( lines -- ) {
            scanf( "%d%d", &depth, &nodes );
            printf("%d\n", Binary( depth, nodes ) );
        }
        cin >> depth;
    }
    return 0;
}