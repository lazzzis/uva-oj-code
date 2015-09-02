/*
    UvaOJ 12504
    Emerald
    Sat 27 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <map>
#include <sstream>
#include <string>

using namespace std;

string Standard( string str ) {
    for( int i=0; i<str.length(); i++ ) {
        if( !isalpha( str[i] ) && !isdigit( str[i] ) ) {
            str[i] = ' ';
        }
    }
    return str;
}

void WriteMap( string& dict, std::map<string, string>& m ) {
    dict = Standard( dict );
    stringstream ss( dict );
    string tmp, tmp2;
    while( ss >> tmp ) {
        ss >> tmp2;
        m[ tmp ] = tmp2;
    }
}

bool CompareDict( std::map<string, string>& oldMap, std::map<string, string>& newMap, char op ) {
    std::map<string, string>::iterator it;
    bool isChanged = false;
    for( it=newMap.begin(); it!=newMap.end(); it ++ ) {
        if( !oldMap.count( it->first ) ) {
            if( !isChanged ) {
                printf("%c%s", op, it->first.c_str() );
                isChanged = true;
            } else {
                printf(",%s", it->first.c_str());
            }
        }
    }
    if( isChanged ) {
        printf("\n");
    }
    return isChanged;
}

bool Update( std::map<string, string>& oldMap, std::map<string, string>& newMap ) {
    bool isChanged = false;
    std::map<string, string>::iterator it;
    for( it=oldMap.begin(); it!=oldMap.end(); it ++ ) {
        if( newMap.count( it->first ) && newMap[it->first]!=oldMap[it->first] ) { // defferent items
            if( !isChanged ) {
                printf("*%s", it->first.c_str() );
                isChanged = true;
            } else {
                printf(",%s", it->first.c_str());
            }
        }
    }
    if( isChanged ) {
        printf("\n");
    }
    return isChanged;
}

int main() {
    int T;
    cin >> T;
    cin.get();
    while( T -- ) {
        std::map<string, string> oldMap, newMap;
        string oldDict;
        getline( cin, oldDict );
        WriteMap( oldDict, oldMap );
        string newDict;
        getline( cin, newDict );
        WriteMap( newDict, newMap );
        bool isChanged = CompareDict( oldMap, newMap, '+' ); // new add
        isChanged = CompareDict( newMap, oldMap, '-' ) || isChanged ; // old del
        isChanged = Update( oldMap, newMap ) || isChanged;
        if( !isChanged ) {
            printf("No changes\n");
        }
        printf("\n"); // blank line
    }
    return 0;
}