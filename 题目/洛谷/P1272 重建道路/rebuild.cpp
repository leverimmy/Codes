#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 150 + 10;

int n, m, cnt, ans = oo;
int first[N], deg[N], f[N][N];

struct edge {
	int to, _next;
} e[N << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int p) {
	f[x][1] = deg[x];
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(y != p) {
		dfs(y, x);
		for(rgi j = m; j >= 1; --j) for(rgi k = 1; k <= j - 1; ++k)
			f[x][j] = std::min(f[x][j], f[x][k] + f[y][j - k] - 2);
	}
}

int main() {
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	memset(f, 0x3f, sizeof(f));
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		deg[u]++, deg[v]++;
		Add_Edge(u, v);
		Add_Edge(v, u);
	} dfs(1, 0);
	for(rgi i = 1; i <= n; ++i) ans = std::min(ans, f[i][m]);
	printf("%d", ans);
	return 0;
}

