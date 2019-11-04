#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 210;
const int INF = 0x3f3f3f3f;
int _w;

int n, m, a[4][N][N], p[4], ans = INF, g[N][N];

void fill() {
	int k = p[0];
	for( int i = 0; i < n; ++i )
		for( int j = 0; j < n; ++j )
			g[i][j] = a[k][i][j];
	k = p[1];
	for( int i = 0; i < n; ++i )
		for( int j = 0; j < n; ++j )
			g[i+n][j] = a[k][i][j];
	k = p[2];
	for( int i = 0; i < n; ++i )
		for( int j = 0; j < n; ++j )
			g[i][j+n] = a[k][i][j];
	k = p[3];
	for( int i = 0; i < n; ++i )
		for( int j = 0; j < n; ++j )
			g[i+n][j+n] = a[k][i][j];
}

void check() {
	int now = 0, tmp = 0;
	for( int i = 0; i < m; ++i )
		for( int j = 0; j < m; ++j ) {
			int t = (i+j) & 1;
			if( g[i][j] != t ) ++now;
			else ++tmp;
		}
	ans = min( ans, now );
	ans = min( ans, tmp );
}

int main() {
	freopen("biscuit.in","r",stdin);
	freopen("biscuit.out","w",stdout);	
	_w = scanf( "%d", &n );
	m = n*2;
	for( int k = 0; k < 4; ++k )
		for( int i = 0; i < n; ++i )
			for( int j = 0; j < n; ++j ) {
				char ch;
				_w = scanf( " %c", &ch );
				a[k][i][j] = ch - '0';
			}
	for( int i = 0; i < 4; ++i ) p[i] = i;
	do {
		fill(), check();
	} while( next_permutation(p, p+4) );
	printf( "%d\n", ans );
	return 0;
}
