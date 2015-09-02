/*
	UvaOJ 712
	Emerald
	Sat 13 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// such as x1, x3, x2 -> the vector will be pushed back with 1 3 2;
std::vector<int> varOrder;
// the values of the leaf nodes from the leftmost to the rightmost
string funResult;

void Init() {
	varOrder.clear();
}

void String2VarOder( string& str ) {
	for( int i=0; i<str.length(); i++ ) {
		if( !isdigit( str[i] ) ) {
			str[i] = ' ';
		}
	}
	stringstream ss( str );
	int value;
	ss >> value;
	varOrder.push_back( value );
}

int TreeResult( string& varValues ) {
	int pos = 1;
	int leafAmount = ( int )pow( 2, varValues.size() );
	for( int i=0; i<varOrder.size(); i++ ) {
		if( varValues[ varOrder[ i ] - 1/* the first var */ ] == '1' ) {
			pos = pos * 2 + 1; // go right
		} else {
			pos *= 2; // go left
		}
	}
	return funResult[ pos - leafAmount ] - '0';
}

int main() {
	int depth;
	int counter = 0;
	while( cin >> depth && depth!=0 ) {
		Init();
		for( int i=0; i<depth; i++ ) {
			string in;
			cin >> in;
			String2VarOder( in );
		}
		cin >> funResult;

		printf("S-Tree #%d:\n", ++counter );

		int query;
		scanf( "%d", &query );
		string varValues;
		for( int i=0; i<query; i++ ) {
			cin >> varValues; // read the values from x[1] to x[depth]
			printf("%d", TreeResult( varValues ) );
		}
		printf("\n\n");
	}
	return 0;
}