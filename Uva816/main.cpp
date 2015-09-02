/*
	UvaOJ 816
	Emerald
	Sun 14 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

// directions
const char *dirs = "NESW";
const char *turns = "FLR";

int DirId( char c ) {
	return strchr( dirs, c ) - dirs;
}

int TurnId( char c ) {
	return strchr( turns, c ) - turns;
}

// grids
const int MAXN = 9 + 5;
int dis[MAXN][MAXN][MAXN]; // dis[ row ][ col ][ dir ]
int dirTurn[ 4 ][ 2 ] = { -1,0, 0,1, 1,0, 0,-1 }; // W, N, E, S
bool hasEdge[ MAXN ][ MAXN ][ MAXN ][ MAXN ];

class Node{
public:
	int row, col, dir;
	Node(){}
	Node( int row, int col, int dir ) {
		this->row = row;
		this->col = col;
		this->dir = dir;
	}
};
// path
Node path[ MAXN ][ MAXN ][ MAXN ]; 
	// Node( r, c ,dir ) comes from path[r][c][dir]

Node Walk( const Node& u, int turn ) { // get the node after turning
	int dir = u.dir;
	if( turn == 1 ) {
		dir = ( dir + 3 ) % 4;
	}
	if( turn == 2 ) {
		dir = ( dir + 1 ) % 4;
	}
	return Node( u.row + dirTurn[ dir ][ 0 ], u.col + dirTurn[ dir ][ 1 ], dir );
}

Node Walk( int x, int y, int dir ) { // get the node after turning
	return Node( x + dirTurn[ dir ][ 0 ], y + dirTurn[ dir ][ 1 ], dir );
}

void Read() {
	memset( hasEdge, false, sizeof( hasEdge ) );
	int x, y;
	while( cin >> x && x != 0 ) {
		cin >> y;
		string dirStr;
		while( cin >> dirStr && dirStr!="*" ) {
			for( int i=1; i<dirStr.length(); i++ ) {
				hasEdge[ x ][ y ][ DirId( dirStr[0] ) ][ TurnId( dirStr[i] ) ] = true;
			}
		}
	}
}

bool Inside( int row, int col ) {
	return row<=9 && row>=1 && col<=9 && col>=1;
}

void Print( Node u, int startX, int startY, int startDir ) {
	std::vector<Node> v;
	while( true ) {
		v.push_back( u );
		if( dis[u.row][u.col][u.dir] == 0 ) {
			break;
		}
		u = path[ u.row ][ u.col ][ u.dir ];
	}
	v.push_back( Node( startX, startY, startDir ) );

	int cnt = 0;
	for( int i = v.size()-1; i>=0; i -- ) {
		if( cnt % 10 == 0 ) {
			printf( " " );
		}
		printf(" (%d,%d)", v[i].row, v[i].col );
		if( ++cnt % 10 == 0 ) {
			printf("\n");
		}
	}
	if( v.size() % 10 != 0 ) {
		printf("\n");
	}
}

void Bfs( int startX, int startY, int startDir, int goalX, int goalY ) {
	queue< Node > q;
	memset( dis, -1, sizeof( dis ) );
	Node t = Walk( startX, startY, startDir );
	dis[ t.row ][ t.col ][ t.dir ] = 0;
	q.push( t );
	while( !q.empty() ) {
		t = q.front();
		q.pop();
		if( t.row == goalX && t.col == goalY ) {
			Print( t, startX, startY, startDir );
			return ;
		}
		for( int i=0; i<3; i++ ) {
			Node v = Walk( t, i );
			if( hasEdge[t.row][t.col][t.dir][i] && Inside( v.row, v.col ) && dis[v.row][v.col][v.dir]<0 ) {
				dis[v.row][v.col][v.dir] = dis[t.row][t.col][t.dir] + 1;
				path[ v.row ][ v.col ][ v.dir ] = t;
				q.push( v );
			}
		}
	}
	printf( "  No Solution Possible\n" );
}

void Init() {
}

int main() {
	string mazeName;
	while( cin >> mazeName && mazeName!="END" ) {
		printf("%s\n", mazeName.c_str() );
		int startX, startY;
		char startDir;
		int goalX, goalY;
		cin >> startX >> startY >> startDir >> goalX >> goalY;
		Read();
		Bfs( startX, startY, DirId( startDir ), goalX, goalY );
	}
	return 0;
}