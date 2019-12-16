#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 100 + 10;

int n, q, cnt;
int first[N], l[N], r[N], W[N], f[N][N];

struct edge {
	int to, _next, wt;
} e[N << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w) {
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int p, int weight) {
	int FLAG = 1; W[x] = weight;
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(y != p) {
		if(FLAG) l[x] = y, FLAG = 0;
		else	 r[x] = y;
		dfs(y, x, e[i].wt);
	}
}

int F(int i, int j) {
	if(!j) return 0;
	if(!l[i] && !r[i]) return W[i];
	if(f[i][j]) return f[i][j];
	for(rgi k = 0; k <= j - 1; ++k)
		f[i][j] = std::max(f[i][j], F(l[i], k) + F(r[i], j - k - 1) + W[i]);
	return f[i][j];
}

int main() {
	n = read(), q = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	} dfs(1, 0, 0);
	printf("%d", F(1, q + 1));
	return 0;
}
/*
5 2
1 3 1
1 4 10
2 3 20
3 5 20

*/
