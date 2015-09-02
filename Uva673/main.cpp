/*
    UvaOJ 673
    Emerald
    Mon 1 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>

using namespace std;

bool IsValid( string &str ) {
    stack <char> st;
    int length = str.length();
    for( int i=0; i < length; i ++ ) {
        if( str[i] == '(' || str[i] == '[' ) {
            st.push( str[i] );
        } else if( st.empty() ) {
            return false;
        } else {
            if( ( str[i]==')' && st.top() == '(' ) || ( str[i]==']' && st.top() == '[' ) ) {
                st.pop();
                continue;
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    int T;
    while(cin >> T) {
        cin.get();
        while( T -- ) {
            string str;
            getline( cin, str );
            printf("%s\n", IsValid( str ) ? "Yes" : "No" );
        }
    }
    return 0;
}