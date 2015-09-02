/*
	UvaOJ 839
	Emerald
	Sat 13 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool isEqual;

void Init() {
	isEqual = true;
}

int MobileWeight() {
	int weiL, disL, weiR, disR;
	scanf( "%d%d%d%d", &weiL, &disL, &weiR, &disR );
	if( weiL == 0 ) {
		weiL = MobileWeight();
	}
	if( weiR == 0 ) {
		weiR = MobileWeight();
	}
	if( weiL*disL != weiR*disR ) {
		isEqual = false;
	}
	return weiL + weiR;
}

int main() {
	int T;
	cin >> T;
	while( T -- ) {
		Init();
		MobileWeight();
		printf("%s\n", isEqual ? "YES" : "NO" );
		if( T ) {
			printf("\n");
		}
	}
	return 0;
}