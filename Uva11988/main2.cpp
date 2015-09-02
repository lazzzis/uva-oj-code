/*
	UvaOJ 11988
	Emerald
	Sat 13 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 100000 + 50;
char text[ MAXN ];
int next[ MAXN ];
const char HOME = '[';
const char END = ']';

void Init() {
	next[0] = -1;
}

void Output() {
	for( int i = next[0]; i!=-1; i = next[i] ) {
		printf("%c", text[ i ] );
	}
	printf("\n");
}

int main() {
	while( scanf( "%s", text+1 ) != EOF ) {
		Init();
		int length = strlen( text+1 );
		int cur = 0, endCur = 0;
		for( int i=1; i<length+1; i ++ ) {
			if( text[i] == HOME ) {
				cur = 0;
			} else if( text[i] == END ) {
				cur = endCur;
			} else {
				next[i] = next[ cur ];
				next[ cur ] = i;
				if( cur == endCur ) {
					endCur = i;
				}
				cur = i;
			}
		}
		Output();
	}
	return 0;
}