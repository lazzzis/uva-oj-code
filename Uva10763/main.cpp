/*
	UvaOJ 10763
	Emerald
	Thu 7 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>

using namespace std;

struct Pair{
	int from, to;
	Pair( int f, int t ) {
		from = f;
		to = t;
	}
};

bool operator < ( const Pair p1, const Pair p2 ) {
	if( p1.from != p2.from ) {
		return p1.from < p2.from ;
	} else {
		return p1.to < p2.to ;
	}
}

void Swap( int& a, int& b ) { // swap a and b in order to make a bigger than b
	if( a > b ) {
		int t = a;
		a = b;
		b = t;
	}
	return ;
}

int main() {
	int N;
	while( cin>>N && N ) {
		set< Pair > sp; // the sp contains the pairs
		int f, t; // from and to;
		for( int i=0; i<N; i++ ) {
			scanf( "%d%d", &f, &t );
			Swap( f, t );
			Pair p ( f, t );
			if( sp.count( p ) ) {
				sp.erase( p );
			} else {
				sp.insert( p );
			}
		}
		if( !sp.size() ) {
			printf( "YES\n" ); // all students can be exchanged abroad
		} else {
			printf( "NO\n" );
		}
	}
	return 0;
}