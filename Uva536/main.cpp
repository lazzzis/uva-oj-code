/*
	UvaOJ 536
	Emerald
	Sat 13 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

string preOrder, inOrder;
vector <char> postOrder;

void FindSub( int L1, int R1, int L2, int R2 ) {
	if( R1 < L1 ) {
		return ;
	}
	postOrder.push_back( preOrder[ L1 ] );
	int p = L2;
	while( inOrder[ p ] != preOrder[ L1 ] ) {
		p ++;
	}
	int cnt = p - L2;
	if( p!=R2 ) { // right subtree first
		FindSub( L1+cnt+1, R1, p+1, R2 );
	}
	if( p!=L2 ) {
		FindSub( L1+1, L1+cnt, L2, p-1 );
	}
}

int main() {
	while( cin >> preOrder >> inOrder ) {
		postOrder.clear();
		FindSub( 0, preOrder.size()-1, 0, inOrder.size()-1 );
		for( int i=postOrder.size()-1; i>=0; i -- ) {
			printf("%c", postOrder[i] );
		}
		printf("\n");
	}
	return 0;
}