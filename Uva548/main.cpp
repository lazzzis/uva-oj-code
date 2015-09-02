/*
    UvaOJ
    Emerald
    Sat 23 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

struct Node{
    int value;
    Node *left, *right;
    Node() {
        left = right = NULL;
    }
};

const int MAXN = 10000 + 50;
int inOrder[ MAXN ], postOrder[ MAXN ]; // the order of inOrder and postOrder
int totalNodes; // the number of total nodes
int maxValue, theMInPathValueLeaf;

void Init() {
    maxValue = theMInPathValueLeaf = 1024*1024;
}

void CreateNode( Node *t, int inStart, int inEnd, int &rootPos ) { // the root of the subtree
    t->value = postOrder[ rootPos ];
    if( inStart + 1 >= inEnd ) {
        return ;
    }
    int i;
    for( i=inStart; i<inEnd; i++ ) {
        if( inOrder[ i ] == postOrder[ rootPos ] ) {
            break;
        }
    }
    // the right
    if( inEnd - (i+1) >= 1 ) {
        t->right = new Node;
        CreateNode( t->right, i+1, inEnd, --rootPos );
    }
    // the left
    if( i - inStart >= 1 ) {
        t->left = new Node;
        CreateNode( t->left, inStart, i, --rootPos );
    }
}

// use postOrder to test the tree
void TestTra( Node *t ) {
    if( t->left!=NULL ) {
        TestTra( t->left );
    }
    if( t->right!=NULL ) {
        TestTra( t->right );
    }
    printf( "%4d", t->value );
}

void MinPathValue( Node *t, int sum ) { // the MinPathValue of this subtree
    if( t->right==NULL && t->left == NULL ) { // this is a leaf
        if( sum + t->value < maxValue ) {
            maxValue = sum + t->value;
            theMInPathValueLeaf = t->value;
        } else if( sum + t->value == maxValue && t->value < theMInPathValueLeaf ) {
            t->value = theMInPathValueLeaf;
        }
    }
    if( t->left!=NULL ) {
        MinPathValue( t->left, sum+t->value );
    }
    if( t->right!=NULL ) {
        MinPathValue( t->right, sum+t->value );
    }
}    

int main() {
    string line;
    while( getline( cin, line ) ) {

        Init(); // the initialization

        // read
        stringstream ss( line );
        totalNodes = 0;
        while( ss >> inOrder[ totalNodes ] ) {
            totalNodes ++;
        }
        for( int i=0; i<totalNodes; i++ ) {
            scanf( "%d", &postOrder[ i ] );
        }

        // build the tree
        Node *head = new Node;
        int rootPos = totalNodes-1;
        CreateNode( head, 0, totalNodes, rootPos );

        //TestTra( head );
        MinPathValue( head, 0 );
        printf( "%d\n", theMInPathValueLeaf );
        cin.get(); // eat the '\n'
    }
    return 0;
}