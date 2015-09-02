/*
	UvaOJ 699
	Emerald
	Sat 20 Jun
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

std::map<int, int> piles; // position , number

void BuildTree( int pos ) {
	int leaves;
	cin >> leaves;
	if( leaves!=-1 ) {
		if( !piles.count( pos ) ) {
			piles[pos] = leaves;
		} else {
			piles[pos] += leaves;
		}
		BuildTree( pos - 1 );
		BuildTree( pos + 1 );
	}
}

void PrintPile() {
	std::map<int, int>::iterator it = piles.begin();
	printf("%d", it->second );
	for( it ++; it != piles.end(); it ++ ) {
		printf(" %d", it->second );
	}
	printf("\n");
}

int main() {
	int root = 0;
	int counter = 0;
	while( cin >> root && root != -1 ) {
		piles.clear();
		piles[0] = root;
		BuildTree( -1 );
		BuildTree( 1 );
		printf("Case %d:\n", ++counter );
		PrintPile();
		printf("\n");
	}
	return 0;
}