#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string Standard( string s ) {
    int i, length = s.length();
    for( i=0; i<length; i++ ) {
        s[i] = tolower( s[i] );
    }
    sort( s.begin(), s.end() );
    return s;
}

map < string, int > dict;
vector <string> words;

int main() {
    string s;
    while( cin >> s ) {
        if( s!="#" ) {
            string r = Standard( s );
            if( dict.count( r ) == 0 ) {
                dict[ r ] = 1;
            } else {
                dict[ r ] ++;
            }
            words.push_back( s );
        } else {
            sort( words.begin(), words.end() );
            int i, length = words.size();
            for( i=0; i<length; i++ ) {
                if( dict[ Standard(words[i]) ] == 1 ) {
                    cout << words[ i ] << endl;
                }
            }
            dict.clear();
            words.clear();
        }
    }
    return 0;
}
