/*
	UvaOJ 12166
	Emerald
	Mon 27 Jul 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <map>

using namespace std;

string expr;
int needChange;
map<long long, int> hashCount;

// build the binary tree
void BuildTree(string& s, int& start, int root, int layout) {
	long long tmp;
	if( s[start] != '[' ) {
		sscanf( &s[start], "%lld", &tmp );
		if( !hashCount.count( tmp<<layout ) ) {
			hashCount[tmp<<layout] = 1;
		} else {
			hashCount[tmp<<layout] ++;
		}
	} else {
		BuildTree(s, ++start, root*2, layout+1);
	}
	for(; s[start]!=','; start++) {
	}
	start ++;
	if( s[start] != '[' ) {
		sscanf( &s[start], "%lld", &tmp );
		if( !hashCount.count( tmp<<layout ) ) {
			hashCount[tmp<<layout] = 1;
		} else {
			hashCount[tmp<<layout] ++;
		}
	} else {
		BuildTree(s, ++start, root*2+1, layout+1);
	}
}

void Init() {
	hashCount.clear();
}

void Solve() {
	needChange = 0;
	// can't be wasted, if it's forgotten, the case '40' may be wrong
	if(expr[0] != '[') {
		return ;
	}
	int pos = 1;
	BuildTree( expr, pos, 1, 1 );
	map<long long, int> :: iterator it;
	int maxC = -1;
	int sum = 0;
	for( it = hashCount.begin(); it != hashCount.end(); it ++ ) {
		sum += it->second;
		maxC = maxC > it->second ? maxC : it->second;
	}
	needChange = sum - maxC;
}

void Print() {
	printf("%d\n", needChange);
}

void Read() {
	cin >> expr;
}

void Work() {
	Init();
	Read();
	Solve();
	Print();
}

int main() {
	int T;
	cin >> T;
	while(T --) {
		Work();
	}
	return 0;
}