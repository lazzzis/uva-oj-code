/*
	UvaOJ 12100
	Emerald
	Tue 5 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

struct Node{
	int value;
	int pos;
};

struct cmp{
	bool operator () ( const int a, const int b ) const {
		return a < b;
	}
}; // the cmp of the priority_queue will use

int main() {
	int T;
	cin >> T;
	while( T -- ) {
		int N, target;
		scanf( "%d%d", &N, &target );
		queue <Node> printQueue; // the queue 
		priority_queue < int, vector<int>, cmp > valueQueue;
		for( int i=0; i<N; i++ ) {
			int tmp;
			scanf( "%d", &tmp );
			Node t;
			t.value = tmp;
			t.pos = i;
			printQueue.push( t );
			valueQueue.push( tmp );
		}
		int counter = 0;
		while( true ) {
			Node t = printQueue.front();
			printQueue.pop();
			int needOrder = valueQueue.top();
			if( t.value == needOrder ) {
				counter ++; // the time ++
				valueQueue.pop();
				if( t.pos == target ) { // now, the target is printed
					break;
				}
			} else {
				printQueue.push( t ); // put it to the tail / rear
			}
		}
		printf( "%d\n", counter );
	}
	return 0;
}