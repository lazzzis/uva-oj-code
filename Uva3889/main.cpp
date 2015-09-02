/*
	UvaOJ 3889
	Emerald
	Fri 26 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <map>
#include <set>

using namespace std;

typedef char ArrayName;
typedef int ArrayLength;
struct ArrayNode{
	ArrayName name;
	int index;
	ArrayNode(){}
	ArrayNode( ArrayName n, int i ){
		name = n;
		index = i;
	}
	bool operator < ( const ArrayNode& n ) const {
		return ( name < n.name ) || ( name==n.name && index<n.index );
	}
};
std::map<ArrayName, ArrayLength> arrayLength;
std::map<ArrayNode, int> value; // int -> value

void Defination( string str ) {
	int length;
	sscanf( &str[2], "%d", &length );
	arrayLength[ str[0] ] = length;
}

int GetIndex( string &str, int start ) {
	if( isdigit( str[start] ) ) {
		int v;
		sscanf( &str[start], "%d", &v );
		return v;
	}
	ArrayName name = str[ start ];
	int index = GetIndex( str, start+2 );
	if( index==-1 || index >= arrayLength[ name ] || !value.count( ArrayNode( name, index ) ) ) {
		return -1;
	}
	return value[ ArrayNode( name, index ) ];
}

int main() {
	string in;
	arrayLength.clear();
	value.clear();
	bool vis = true;
	int pos = 0, lineCounter = 0;
	while( cin >> in ) {
		if( in=="." ) {
			if( vis==true ) {
				continue; // avoid continus dot such as ".\n.\n"
			}
			cout << pos << endl;
			arrayLength.clear();
			value.clear();
			pos = 0;
			lineCounter = 0;
			vis = true;
		} else {
			vis = false;
			if( pos ) {
				continue;
			}
			lineCounter ++;
			int equalSignPos = in.find_first_of( '=' );
			if( equalSignPos == string::npos ) { // means defination like a[2]
				Defination( in );
			} else {
				int leftIndex = GetIndex( in, 2 );
				int rightValue = GetIndex( in, equalSignPos+1 );
				if( leftIndex == -1 || rightValue== -1 // not valid inside so that can't get the index
					|| leftIndex>=arrayLength[ in[0] ] /* out of index*/ ) {
					pos = lineCounter;
					continue;
				}
				value[ ArrayNode( in[0], leftIndex ) ] = rightValue;
			}
		}
	}
	return 0;
}