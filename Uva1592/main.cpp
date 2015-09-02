/*
	UvaOJ 1592
	Emerald
	Fri 1 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>

using namespace std;

const int MAXN = 80 + 5;
const char OTHER_CHAR = 1;
int rows, cols;
map < string, int > words;
int table[ 10000 + 20 ][ 10 + 2 ];

struct Pair{
	int x, y; // used to compare
	Pair( int a1, int a2 ) {
		x = a1; y = a2;
	}
};

/*
	This defination is of great importance to the map
*/
bool operator < ( const Pair a, const Pair b ) {
	if( a.y==b.y ) return a.x < b.x;
	else return a.y < b.y;
}

int GetId( string &s, int &counter ) {
	if( words.count( s ) ) {
		return words[s];
	} else {
		words[ s ] = counter++;
		return words[s];
	}
}

void Read() { // read the data and make each string into a number
	int i, j;
	int counter = 0;
	
	/* this way to clear map is better */
	words.erase( words.begin(), words.end() );
	for( i=0; i<rows; i++ ) {
		string line;
		getline( cin, line );
		int length = line.length();
		for( j=0; j<length; j++ ) {
			/* transfer space to not space, aiming to conclude string more easily */
			if( line[j]==' ' ) {
				line[j] = OTHER_CHAR;
			} else if( line[j]==',' ) {
				line[j] = ' ';
			}
		}
		stringstream ss( line ); // transfer into stringstream
		for( j=0; j<cols; j++ ) {
			ss >> line;
			table[i][j] = GetId( line, counter );
		}
	}
}

bool IsPNF() {
	for( int i=0; i<cols; i++ ) {
		for( int j=i+1; j<cols; j++ ) {
			map< Pair, int > cmp;
			cmp.clear();
			for( int k =0; k<rows; k++) {
				Pair p ( table[k][i], table[k][j] );// first element, second element
				if( cmp.count( p ) ) {
					printf( "NO\n" );
					printf( "%d %d\n", cmp[p] + 1, k + 1 ); // first print rows
					printf( "%d %d\n", i + 1, j + 1 ); // then print cols
					return false;
				} else {
					cmp[ p ] = k;
				}
			}
		}
	}
	return true;
}

int main() {
//	cout << OTHER_CHAR << endl;
	while( scanf( "%d%d", &rows, &cols )!=EOF ) {
		getchar();
		Read();
		if( IsPNF() ) {
			printf( "YES\n" );
		}
	}
	return 0;
}