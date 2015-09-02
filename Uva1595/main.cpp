/*
	UvaOJ 1595
	Emerald
	Mon 4 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

int main() {
	int T;
	cin >> T;
	while( T -- ) {
		int N;
		cin >> N;
		map < int,int > yToXsum; // key : the value of y, value : the total value of x in y axis
		map < int,int > yTimes; // key : the value of y, value : the times that y appears
		map < int, int >::iterator it;
		int x, y;
		while( N -- ) {
			scanf( "%d%d", &x, &y );
			if( yToXsum.count( y ) ) {
				yToXsum[y] += x;
			} else {
				yToXsum[y] = x;
			}
			if( yTimes.count( y ) ) {
				yTimes[ y ] ++;
			} else {
				yTimes[ y ] = 1;
			}
		}
		double ave; // the average of the x
		it = yTimes.begin();
		ave = 1.0 * yToXsum [ it->first ] / it->second;
		for( it ++; it!=yTimes.end(); it ++ ) {
			if( ave != 1.0 * yToXsum [ it->first ] / it->second ) {
				break;
			}
		}
		if( it == yTimes.end() ) {
			printf( "YES\n" );
		} else {
			printf( "NO\n" );
		}
	}
	return 0;
}