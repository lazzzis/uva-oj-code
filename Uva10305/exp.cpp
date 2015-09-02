/*
	UvaOJ 10305
	Emerald
	Sun 14 Jun 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 100 + 50;
int vis[ MAXN ];
bool link[MAXN][MAXN]; // link[i][j] i should be done before j
int topo[MAXN]; // record the order
int N, t;

void Init() {
	memset( link, false, sizeof(link) );
	memset( vis, 0, sizeof(vis) );
}

bool dfs( int u ) {
	vis[u] = -1;
	for( int v = 1; v <= N; v ++ ) {
		if( link[u][v] ) { // look for the latter
			if( vis[v]<0 ) {
				return false;
			} else if( !vis[v] && !dfs(v) ) {
				return false;
			}
		}
	}
	vis[u] = 1;
	topo[ --t ] = u;
	return true;
}

bool TopoSort() {
	t = N;
	for( int u=1; u<=N; u++ ) {
		if( !vis[u] && !dfs(u) ) {
			return false;
		}
	}
	return true;
}

int main() {
	int line;
	while( scanf( "%d%d", &N, &line )!=EOF ) {
		if ( N==0 && line==0 ) {
			break;
		}
		Init();
		while( line -- ) {
			int x, y;
			scanf( "%d%d", &x, &y );
			link[x][y] = true;
		}
		TopoSort();
		printf("%d", topo[0] );
		for (int i = 1; i < N; ++i) {
			printf(" %d", topo[i] );
		}
		printf("\n");
	}
	return 0;
}