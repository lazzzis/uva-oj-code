/*
	UvaOJ 221
	Emerald
	Fri 26 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Building{
	double x, y, width, depth, height;
	int id;
	bool operator < ( const Building &rhs ) const {
		return ( x < rhs.x ) || ( x==rhs.x && y < rhs.y );
	}
};

const int MAXN = 100 + 10;
Building build[ MAXN ];
double x[MAXN*2];
int N;

bool IsCover( int id, double x ) {
	return build[id].x <= x && build[id].x+build[id].width >= x;
}

bool IsVisible( int id, double x ) {
	if( !IsCover( id, x ) ) {
		return false;
	}
	for( int i=0; i<N; i++ ) {
		// y and height can't be both equal
		if( IsCover( i, x )  && build[i].y < build[id].y && build[i].height >= build[id].height ) {
			return false;
		}
	}
	return true;
}

int main() {
	int counter = 0;
	while( cin >> N && N ) {
		for( int i=0; i<N; i++ ) {
			scanf( "%lf%lf%lf%lf%lf", &build[i].x, &build[i].y, &build[i].width, &build[i].depth, &build[i].height );
			x[ i*2 ] = build[i].x;
			x[i*2+1] = build[i].x + build[i].width;
			build[i].id = i + 1;
		}
		sort( build, build + N );
		sort( x, x+2*N );
		int M = unique( x, x+2*N ) - x;

		if( counter ) {
			printf("\n");
		}
		printf("For map #%d, the visible buildings are numbered as follows:\n", ++counter );
		printf("%d", build[0].id );
		for( int i=1; i<N; i++ ) {
			for( int j=0; j<M-1; j++ ) {
				if( IsVisible( i, ( x[j]+x[j+1] )/2 ) ) {
					printf(" %d", build[i].id );
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}