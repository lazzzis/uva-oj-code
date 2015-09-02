/*
	UvaOJ 10935
	Emerald
	Sat 2 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

queue <int> q;

void Init( int N ) {
	while( !q.empty() ) {
		q.pop();
	}
	for( int i=1; i<N+1; i++ ) {
		q.push( i );
	}
}

void Throw( ) {
	printf( "Discarded cards: %d", q.front() );
	q.pop();
	q.push( q.front() );
	q.pop();
	while( q.size() >= 2 ) {
		printf( ", %d", q.front() );
		q.pop();
		q.push( q.front() );
		q.pop();
	}
	printf( "\n" );
	printf( "Remaining card: %d\n", q.front() );
}

int main() {
	int N;
	while( cin >> N && N ) {
		Init( N );
		if( N==1 ) {
			printf( "Discarded cards:\n" );
			printf( "Remaining card: 1\n" );
		} else {
			Throw();
		}
	}
	return 0;
}