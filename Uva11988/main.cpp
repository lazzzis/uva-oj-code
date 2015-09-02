/*
	Uva11988
	Emerald
	Mon 18 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

const int MAXN = 100000 + 50;
int next[MAXN];
char text[MAXN];

int main() {
	while( cin >> ( text+1 ) ) {
		int length = strlen( text + 1 );
		next[0] = 0;
		int cur = 0, last = cur;
		for( i=1; i<length+1; i++ ) {
			if( text[i] == '[' ) {
				cur = 0;
			} else if( text[i] == ']' ) {
				cur = last;
			} else {
				next[i] = next[ cur ];
				next[ cur ] = i;
				if( cur == last ) {
					last = i;
				}
				cur = i;
			}
		}
		for( int i=next[0]; i!=0; i = next[i] ) {
			printf("%c", text[i] );
		}
		printf( "\n" );
	}
	return 0;
}