/*
    UvaOJ 122
    Emerald
    Thu 21 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 512 + 8;
int counter = 0;
// int treeNode[ MAXN + 10 ];
map < int, int > treeNode; // map < position, value >
bool isOkay = true;

void Init() { // the initialization
    // memset( treeNode, -1, sizeof(treeNode) );
    treeNode.clear();
    counter = 0;
    isOkay = true;
}

void AddTreeNode( const string &s ) { // add a new node to the BT
    int value = 0;
    int i;
    for( i=1; i<s.length() && s[i]!=','; i ++ ) {
        value = value*10 + s[i] - '0';
    }
    int pos = 1;
    i ++;
    while( i<s.length() && s[i]!=')' ) {
        if( s[i ++] == 'L' ) {
            pos = pos * 2;
        } else {
            pos = pos * 2 + 1;
        }
    }
    if( treeNode.count( pos ) ) {
        isOkay = false;
        return ;
    }
    treeNode[ pos ] = value;
    counter ++;
    return ;
}

bool isComplete() { // according to the tree, is the tree complete ?
    if( !treeNode.count( 1 ) ) {
        return false;
    }
    queue <int> q; // queue <position>
    q.push( 1 );
    int linkAmount = 0;
    while( ! q.empty() ) {
        int t = q.front();
        q.pop();
        linkAmount ++;
        if( treeNode.count( t*2 ) ) {
            q.push( t*2 );
        }
        if( treeNode.count( t*2 + 1) ) {
            q.push( t*2+1 );
        }
    }
    return counter == linkAmount;
}

void PrintTree() { // print the tree as the problem requires
    printf( "%d", treeNode[1] );
    map < int, int > :: iterator it = treeNode.begin();
    for( it++; it!=treeNode.end(); it ++ ) {
        printf( " %d", it->second );
    }
    printf("\n");
}

int main() {
    string in;
    Init();
    while( cin >> in ) {
        if( in == "()" ) {
            if(  !isOkay ||  !isComplete() ) {
                printf("not complete\n");
            } else {
                PrintTree();
            }
            Init();
        } else {
            AddTreeNode( in );
        }
    }
    return 0;
}