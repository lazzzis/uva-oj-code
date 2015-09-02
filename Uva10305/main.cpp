/*
	Emerald
	UvaOJ 10305
	Sun 14 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100 + 50;
int outDeg[ MAXN ];
vector <int> linkList[ MAXN ];
int N, M;

void Init( int& N ) {
	for( int i=1; i<N+1; i++ ) {
		linkList[i].clear();
		/*inDeg[i] = */outDeg[i] = 0;
	}
}

void Read( int& M ) {
	int former, latter; // former <- latter
	for( int i=0; i<M; i++ ) {
		scanf( "%d%d", &former, &latter );
		// inDeg[ former ] ++;
		outDeg[ latter ] ++;
		linkList[ former ].push_back( latter );
	}
}

void TopoSort( std::vector<int> &v ) {
	queue<int> q;
	for( int i=1; i<=N; i++ ) {
		if( outDeg[ i ] == 0 ) {
			q.push( i );
		}
	}
	while( !q.empty() ) {
		int t = q.front();
		q.pop();
		v.push_back( t );
		for( int i=0; i < linkList[t].size(); i ++ ) {
			outDeg[ linkList[t][i] ] --;
			if( outDeg[ linkList[t][i] ] == 0 ) {
				q.push( linkList[t][i] );
			}
		}
	}
}

void Print( std::vector<int> &v ) {
	printf("%d", v[0] );
	for( int i=1; i<v.size(); i++ ) {
		printf(" %d", v[i] );
	}
	printf("\n");
}

int main() {
	while( cin >> N >> M ) {
		if( N == M && N == 0 ) {
			break;
		}
		Init( N );
		Read( M );
		std::vector<int> ans;
		TopoSort( ans );
		Print( ans );
	}
	return 0;
}