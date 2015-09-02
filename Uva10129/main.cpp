/*
	UvaOJ 10129
	Emerald
	Tue 23 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>

using namespace std;

const int MAXN = 256 + 5;
int inDegree[MAXN], outDegree[MAXN];
bool link[MAXN][MAXN];
bool vis[MAXN];

void Init() {
	memset( inDegree, 0, sizeof(inDegree) );
	memset( outDegree, 0, sizeof(outDegree) );
	memset( link, false, sizeof(link) );
	memset( vis, false, sizeof(vis) );
}

int total = 0;
void Con( char ch ) {
	vis[ch] = true;
	for( int i='a'; i<'z'+1; i++ ) {
		if( link[ch][i] && !vis[i] ) {
			Con( i );
		}
	}
}

int VisNum() {
	int counter = 0;
	for( int i='a'; i<'z'+1; i++ ) {
		if( vis[i] ) {
			counter ++;
		}
	}
	return counter;
}

bool isEuler() {
	int in = 0, out = 0;
	for( int i='a'; i<'z'+1; i++ ) {
		if( inDegree[i] == outDegree[i]+1 ) {
			in ++;
		} else if ( inDegree[i]+1 == outDegree[i] ) {
			out ++;
		} else if( inDegree[i] == outDegree[i] ) {
			continue;
		} else {
			return false;
		}
	}
	return in == out && ( in==0 || in==1 );
}

int main() {
	int T;
	cin >> T;
	while( T -- ) {
		int N;
		string s;
		set <char> dict;
		Init();
		cin >> N;
		for( int i=0; i<N; i++ ) {
			cin >> s;
			link[s[0]][ s[ s.length()-1 ] ] = link[s[ s.length()-1 ]][ s[0] ] = true;
			dict.insert( s[0] );
			dict.insert( s[ s.length()-1 ] );
			outDegree[ s[ s.length()-1 ] ] ++;
			inDegree[ s[0] ] ++;
		}
		Con( s[0] );
		if( VisNum() == dict.size() && isEuler() ) {
			printf("Ordering is possible.\n" );
		} else {
			printf("The door cannot be opened.\n");
		}
	}
	return 0;
}