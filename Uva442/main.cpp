/*
	UvaOJ 442
	Emerald
	Mon 18 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <string>
#include <map>
#include <stack>

using namespace std;

class Matrix{
public:
	int rows;
	int cols;
	Matrix() {}
	Matrix( int r, int c ) {
		this->rows = r;
		this->cols = c;
	}
};

/*
	Matrix:
			cols
		-------------
	rows|
		|
		|
*/

map < char, Matrix > matrixes;

/*
	No error:
		left.cols = rows;
*/

bool isError( Matrix& left, Matrix& right ) { // Are these two matrixes can multiplied ?
	return left.cols != right.rows;
}

/*
	Multiply:
		eg. A : rows = 50, cols = 10
			B : rows = 10, cols = 20
		A * B -> C : rows = 50, cols = 20			
*/

int MatMul( Matrix& left, Matrix& right ) { // mutiply these tow  matrix and change the right
	int ans = left.cols * left.rows * right.cols;
	right.rows = left.rows;
	return ans;
}

int Cal( string &exp ) { // according to the expression, get the ans
	string :: iterator it;
	int counter = 0;
	stack < Matrix > st;
	for( it = exp.begin(); it!=exp.end(); it ++ ) {
		if( *it == ')' ) {
			Matrix right = st.top();
			st.pop();
			Matrix left = st.top();
			st.pop();
			if( isError( left, right ) ) {
				return -1;
			}
			counter += MatMul( left, right );
			st.push( right );
		} else if( isalpha( *it ) ) {
			st.push( matrixes[ *it ] );
		}
	}
	return counter;
}

int main() {
	int N;
	while( cin >> N ) {
		char matrixAlpha;
		int rows, cols;
		matrixes.clear();
		for( int i=0; i<N; i++ ) {
			cin >> matrixAlpha >> rows >>cols;
			matrixes[ matrixAlpha ] = Matrix( rows, cols );
		}
		string exp;
		while( cin >> exp ) {
			int ans = Cal( exp );
			if( ans == -1 ) {
				printf( "error\n" );
			} else {
				printf( "%d\n", ans );
			}
		}
	}
	return 0;
}