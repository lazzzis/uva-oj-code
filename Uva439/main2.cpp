/*
	UvaOJ 139
	Emerald
	Sat 13 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

class Node{
public:
	int x, y;
	int step;
	Node() {}
	Node(int x, int y) {
		this->x = x;
		this->y = y;
		this->step = 0;
	}
};

const int MAXN = 8 + 5;
bool vis[ MAXN ][ MAXN ];
int dir[8][2] = { -2,-1,  -1,-2, 1,2, 2,1,
				-2,1, -1,2, 1,-2, 2,-1 };

bool isValid( Node& t ) {
	return t.x>=1 && t.x<=8 && t.y>=1 && t.y<=8 && !vis[ t.x ] [ t.y ];
}

int Bfs( int startX, int startY, int endX, int endY ) {
	memset( vis, false, sizeof( vis ) );
	queue <Node> q;
	Node t( startX, startY ), next;
	vis[ t.x ][ t.y ] = true;
	q.push( t );
	while( ! q.empty() ) {
		t = q.front();
		q.pop();
		if( t.x == endX && t.y == endY ) {
			return t.step;
		}
		for( int i=0; i<8; i++ ) {
			next.x = t.x + dir[i][0];
			next.y = t.y + dir[i][1];
			if( isValid( next ) ) {
				next.step = t.step + 1;
				vis[ next.x ][ next.y ] = true;
				q.push( next );
			}
		}
	}
	return -1;
}

int main() {
	string start, end;
	while( cin >> start >> end ) {
		cout << "To get from " << start << " to " << end << " takes "
		<< Bfs( start[0]-'a'+1, start[1]-'0', end[0]-'a'+1, end[1]-'0' )
		<< " knight moves." <<endl;
	}
	return 0;
}