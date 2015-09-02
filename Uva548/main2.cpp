/*
	UvaOJ 548
	Emerald
	Tue 9 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 100000 * 2 + 1;
const int INF = 100000000;
const int EMPTY = -1;
int leftNode[ MAXN ], rightNode[ MAXN ];
// the order of the left subtree of i is leftNode[i],
// the order of the right subtree of i is rightNode[i],
std::vector<int> inOrder, postOrder;
int minValue, minNodeOrder;

// the init part:
// clear the vectors
// clear the arrays
// max the minValue
void Init() {
	inOrder.clear();
	postOrder.clear();
	memset( leftNode, -1, sizeof( leftNode ) );
	memset( rightNode, -1, sizeof( rightNode ) );
	minValue = minNodeOrder = INF;
}

/*
	with stringstream, s will be splitted to integers
*/
void String2vector( string& s, vector <int>& v ) {
	int temp;
	stringstream ss( s );
	while( ss >> temp ) {
		v.push_back( temp );
	}
}

void TestVector( vector <int>& v ) {
	vector<int> :: iterator it;
	for( it=v.begin(); it!=v.end(); it++ ) {
		printf( "%3d\n", *it );
	}
}

/*
	the last order of the postOrder is the root of a subtree
*/
int CreateTree( int L1, int R1, int L2, int R2 ) {
	if( R1 < L1 ) {
		return EMPTY;
	}
	int root = postOrder[ R2 ];
	int p = L1;
	while( inOrder[ p ] != root ) {
		p ++;
	}
	int cnt = p - L1;
	leftNode[ root ] = CreateTree( L1, p-1, L2, L2+cnt-1 );
	rightNode[ root ] = CreateTree( p+1, R1, L2+cnt, R2-1 );
	return root;
}

void Dfs( int root, int sum ) {
	if( leftNode[root] == EMPTY && rightNode[root] == EMPTY ) {
		if( sum + root < minValue ) {
			minValue = sum + root;
			minNodeOrder = root;
		} else if( sum+root == minValue && root < minNodeOrder ) {
			minNodeOrder = root;
		}
		return ;
	}
	if( leftNode[root] != EMPTY ) {
		Dfs( leftNode[ root ], sum + root );
	}
	if( rightNode[root] != EMPTY ) {
		Dfs( rightNode[ root ], sum + root );
	}
}

int main() {
	// freopen( "1.txt", "r", stdin );
	string line;
	while( getline( cin, line ) ) {
		Init();
		String2vector( line, inOrder );
		getline( cin, line );
		String2vector( line, postOrder );
		CreateTree( 0, inOrder.size()-1, 0, postOrder.size()-1 );
		Dfs( postOrder[ postOrder.size()-1 ], 0 );
		printf("%d\n", minNodeOrder );
		//cin.get(); this is useless
	}
	return 0;
}