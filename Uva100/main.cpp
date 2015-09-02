/**
	Author : Emerald
	Date : 30.Mar 2015
	Methods : 递归
*/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int GetTime( int n ) {
	if( n==1 ) {
		return 1;
	}
	int c1; // the times
	if( n & 1 ) { // odd
		c1 = GetTime( 3*n+1 ) + 1;
	} else { // even
		c1 = GetTime( n >> 1 ) + 1;
	}
	return c1;
}

int main() {
	int N, M; // the two input nums
	while( scanf( "%d%d", &N, &M )!=EOF ) {
		int lessOne = N < M ? N : M;
		int maxC = -1; // record the max Time
		for( int i=lessOne; i<=N+M-lessOne; i++ ) {
			int tmp = GetTime( i ); // the temp var to record the value of GetTime
			if( maxC < tmp ) {
				maxC = tmp;
			}
		}
		printf( "%d %d %d\n", N, M, maxC );
	}
	return 0;
}
