/*
    UvaOJ 839
    Emerald
    Thu 28 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool isEqual; // means the status is equal

int Moblie() {

    int leftWeight, leftDis, rightWeight, rightDis;
    scanf( "%d%d%d%d", &leftWeight, &leftDis, &rightWeight, &rightDis );
    leftWeight = leftWeight == 0 ? Moblie() : leftWeight;
    rightWeight = rightWeight == 0 ? Moblie() : rightWeight;
    if( leftWeight * leftDis != rightWeight * rightDis ) {
        isEqual = false;
    }
    return leftWeight + rightWeight;
} // return the totalWeight

int main() {
    int T;
    cin >> T;
    while( T -- ) {
        isEqual = true;
        Moblie();
        printf("%s\n", isEqual ? "YES" : "NO" );
        if( T != 0 ) {
            printf("\n");
        }
    }
    return 0;
}