/*
	UvaLive 4723
	Emerald
	Fri 8 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

bool allZero( vector<int> &v ) {
	vector <int>::iterator it;
	for( it=v.begin(); it!=v.end(); it ++ ) {
		if( *it ) {
			return false;
		}
	}
	return true;
}

int main() {
	int T;
	int tmp;
	cin >> T;
	while( T -- ) {
		int N;
		scanf( "%d", &N );
		vector <int> first;
		for( int i=0; i<N; i++ ) {
			scanf( "%d", &tmp );
			first.push_back( tmp );
		}
		set < vector<int> > subq;
		subq.insert( first );
		do{
			vector <int> v;
			for( int i=0; i<N-1; i++ ) {
				v.push_back( abs( first[i] - first[i+1] ) );
			}
			v.push_back( abs( first[N-1] - first[0] ) );
			if( allZero( v ) ) {
				printf( "ZERO\n" );
				break;
			} else if( subq.count( v ) ) {
				printf( "LOOP\n" );
				break;
			}
			subq.insert( v );
			first = v;
		}while( true );
	}
	return 0;
}