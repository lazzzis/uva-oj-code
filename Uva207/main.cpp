/*
	UvaOJ 207
	Emerald
	Sat 27 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int INF = 100000 + 50;

struct Team{
	int total;
	int mark[4];
	char name[40];
	bool amateur;
	bool operator < ( const team &t ) const {
		return (total < t.total) || ( total==t.total && strcmp( name, t.name ) );
	} 	
};

double totalPrize;
double rate[ 75 ];
Team team[ 140 + 20 ];

int main() {
	scanf( "%lf", &totalPrize );
	for( int i=0; i<70; i++ ) {
		scanf( "%lf", &rate[i] );
	}
	int i = 0;
	char tmp[10];
	while( scanf( "%20f", &team[i].name ) ) {
		team[i].amateur = ( team[i].name[ strlen(team[i].name)-1 ] == '*' )
		for( int j=0; j<4; j++ ) {
			scanf( "%s", tmp );
			if( strcmp( tmp, "DQ" ) == 0 ) {
				team[i].total = INF;
				break;
			} else {
				sscanf( tmp, "%d", &team[i].mark[j] );
			}
		}
	}
	return 0;
}