/*
	UvaOJ 1593
	Emerald
	Sat 2 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int MAXN = 2000 + 10;
vector <string> lineWords[MAXN];
int colMax[ MAXN ]; // the max length of each column

void Print( string &s, char extra, int M ) { // print the word and space
	cout << s;
	int length = s.length();
	for( int i=0; i < M-length; i++ ) {
		printf( "%c", extra );
	}
}

int main() {
	int rows = 0; // line number
	int cols = 0;
	string line;
//	freopen( "1.txt", "r", stdin );
	memset( colMax, -1, sizeof( colMax ) );
	while( getline( cin, line ) ) {
		stringstream ss( line );
		cols = 0;
		while( ss >> line ) {
			lineWords[ rows ].push_back( line );
			int length = line.length();
			colMax[ cols ] = colMax[ cols ] > length ? colMax[ cols ] : length;
			cols ++;
		}
		rows ++;
	}
	int i, j;
	for( i=0; i<rows; i++ ) {
		int size = lineWords[i].size();
		for( j=0; j<size-1; j++ ) {
			Print( lineWords[i][j], ' ', colMax[ j ]+1 );
		}
		Print( lineWords[i][j], ' ', lineWords[i][j].length() );
		printf( "\n" );
	}
	return 0;
}