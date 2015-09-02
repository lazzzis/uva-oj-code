/*
	UvaOJ 221
	Emerald
	Thu 25 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 20;

struct Building {
	double x, y, width, depth, height;
	int id;
	bool operator < ( const Building& rhs ) const {
		return x < rhs.x || ( x==rhs.x && y<rhs.y );
	}
} build[ MAXN ] ;

double x[MAXN*2+10]; // the x coordinates that will be used
int N;

bool IsCover( int order, double xCoor ) {
	return build[order].x <= xCoor && build[order].x + build[order].width >=xCoor;
}

bool IsVisible( int order, double xCoor ) {
	if( !IsCover( order, xCoor ) ) {
		return false;
	}
	// begin from zero !!!
	for( int i=0; i<N ; i++) {
		// the y coordinate and height can't be both equal; If that, i and xCoor are equal
		if( IsCover( i, xCoor ) && build[i].y < build[order].y && build[i].height >= build[order].height ) {
		// it's also right like this
		// if( i!=order && IsCover( i, xCoor ) && build[i].y <= build[order].y && build[i].height >= build[order].height ) {
			return false;
		}
	}
	return true;
}

int main() {
	int counter = 0;
	while( cin >> N && N!=0 ) {
		for (int i = 0; i < N; ++i) {
			scanf( "%lf%lf%lf%lf%lf", &build[i].x, &build[i].y, &build[i].width,
				&build[i].depth, &build[i].height );
			x[i*2] = build[i].x;
			x[i*2+1] = build[i].x+build[i].width;
			build[i].id = i + 1;
		}
		sort( build, build+N );
		sort( x, x+2*N );
		int m = unique( x, x+2*N ) -  x;
		// there're m kinds of x which is different from each other

		if( counter ) {
			printf("\n");
		}
		printf("For map #%d, the visible buildings are numbered as follows:\n", ++counter );
		printf("%d", build[0].id );
		for( int i=1; i<N; i++ ) {
			bool vis = false;
			for( int j=0; j<m-1; j++ ) {
				if( IsVisible( i, ( x[j] + x[j+1] ) / 2 ) ) {
					vis = true;
					break;
				}
			}
			if( vis ) {
				printf(" %d", build[i].id );
			}
		}
		printf("\n");
	}
	return 0;
}