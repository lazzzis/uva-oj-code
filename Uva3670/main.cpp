/*
	UvaOJ 3670
	Emerald
	Sat 20 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

struct Node {
	int x, y;
	int step, conStep;
};

const int MAXN = 20 + 5;
int maze[MAXN][MAXN];
int vis[MAXN][MAXN][MAXN*MAXN];
int dir[4][2] = { 0,1, 0,-1, 1,0, -1,0 };
int M, N, K;

bool isInside( Node &t ) {
	return t.x >= 1 && t.x <= M && t.y>=1 && t.y<=N;
}

int Bfs() {
	memset( vis, -1, sizeof(vis) );
	queue<Node> q;
	Node t, next;
	t.x = 1; t.y = 1;
	t.step = 0; t.conStep = 0;
	q.push( t );
	while( !q.empty() ) {
		t = q.front();
		q.pop();
		if( t.x == M && t.y == N ) {
			return t.step;
		}
		for( int i=0; i<4; i++ ) {
			for( int j=0; j<4; j++ ) {
				next.x = t.x + dir[i][0];
				next.y = t.y + dir[i][1];
				next.step = t.step + 1;
				next.conStep = maze[next.x][next.y] ? t.conStep + maze[next.x][next.y] : 0;
				if( isInside( next ) ) {
					if( next.conStep <= K && 
						(vis[next.x][next.y][next.conStep]==-1 || next.step < vis[next.x][next.y][next.conStep] ) ) {
						vis[next.x][next.y][next.conStep] = next.step;
						q.push(next);
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	while( T -- ) {
		cin >> M >> N >> K;
		for( int i=1; i<=M; i++ ) {
			for( int j=1; j<=N; j++ ) {
				scanf( "%d", &maze[i][j] );
			}
		}
		printf("%d\n", Bfs() );
	}
	return 0;
}