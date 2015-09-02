/*#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <string>
#include <sstream>

using namespace std;

struct Node{
    int value;
    friend bool operator < ( Node a, Node b ) {
        return a.value < b.value;
    }
};

set <Node> s;

int main() {
    Node n[3];
    n[0].value = 3;
    n[1].value = 1;
    n[2].value = 5;
    
    s.insert( n[0] );
    s.insert( n[1] );
    s.insert( n[2] );
    set<Node>::iterator it = s.begin();
    while( it!=s.end() ) {
        printf( "%d\n", it->value );
        it ++;
    }
    return 0;
}*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <set>
#include <string>
#include <sstream>

using namespace std;

set < string > dict;

int main() {
    string s, buf;
    while( cin >> s ) {
        int length = s.length();
        for( int i=0; i<length; i++ ) {
            if( isalpha( s[i] ) ) {
                s[i] = tolower( s[i] );
            } else {
                s[i] = ' ';
            }
        }
        stringstream ss( s );
        while( ss >> buf ) {
            dict.insert( buf );
        }
    }
    for( set<string>::iterator it = dict.begin(); it!=dict.end(); it ++ ) {
        cout << *it << endl;
    }
    return 0;
}
