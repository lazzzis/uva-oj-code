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

using namespace std;

const int NONE = -1; // the value should be noticed when the problem description is changed

class  Node {
public:
    Node *left, *right;
    int value;
    Node() {
        this->value = NONE;
        left = right = NULL;
    }
    Node( int v ) {
        this->value = v;
        left = right = NULL;
    }
    /* data */
};

Node *root; // the root of the tree
bool isOkay; // can this tree be built successfully

void Init() {
    root = new Node;
    isOkay = true;
}

void AddNode( int value, char* posStr ) { // add new Node
    int i = 0;
    Node *target = root;
    while( posStr[i]!=')' ) {
        if( posStr[i] == 'L' ) {
            if( target->left == NULL ) {
                target->left = new Node;
            }
            target = target->left; // go left
        } else if( posStr[i] == 'R' ){
            if( target->right == NULL ) {
                target->right = new Node;
            }
            target = target->right; // go right
        }
        i ++;
    }
    if( target->value != NONE ) {
        isOkay = false; // one node is given value more than once
    }
    target -> value = value;
}

bool IsComplete() {
    if( root -> value == NONE ) {
        return false;
    }
    queue <Node*> q;
    q.push( root );
    while( !q.empty() ) {
        Node* t= q.front();
        q.pop();
        if( t->value == NONE ) { // this node isn.t used
            return false;
        }
        if( t->left != NULL ) {
            q.push( t->left ); // go left
        }
        if( t->right != NULL ) {
            q.push( t->right ); // go right
        }
    }
    return true;
}

void PrintTree() { // print all the nodes
    printf( "%d", root->value );
    queue <Node *> q; // use queue to print
    if( root->left != NULL ) {
        q.push( root->left ); // go left
    }
    if( root->right != NULL ) {
        q.push( root->right ); // go right
    }
    delete root;
    while( !q.empty() ) {
        Node* t= q.front();
        printf( " %d", t->value );
        q.pop();
        if( t->left != NULL ) {
            q.push( t->left ); // go left
        }
        if( t->right != NULL ) {
            q.push( t->right ); // go right
        }
        delete t;
    }
    printf( "\n" );
}

int main() {
    char in[ 400 + 50 ];
    Init();
    while( scanf( "%s", in )!=EOF ) {
        if( strcmp( in, "()" ) == 0 ) {
            if( isOkay && IsComplete() ) {
                PrintTree();
            } else {
                printf( "not complete\n" );
            }
            Init();
        } else {
            int value;
            sscanf( in+1, "%d", &value );
            AddNode( value, strchr( in, ',' )+1 );
        }
    }
    return 0;
}