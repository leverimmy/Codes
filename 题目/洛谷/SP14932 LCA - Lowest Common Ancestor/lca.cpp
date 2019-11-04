#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 5e5 + 10;
const int M = 5e5 + 10;

int T, n, q, root, cnt;
int first[N], lg2[N] = {-1}, f[N][20], dep[N];

struct edge{
	int to, _next;
} e[M << 1];

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
	dep[x] = dep[p] + 1;
	f[x][0] = p;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)	dfs(e[i].to, x);
}

int lca(int u, int v) {
	if(dep[u] < dep[v])	std::swap(u, v);
	int tmp = dep[u] - dep[v];
	for(rgi i = 0; i <= lg2[dep[u]]; ++i)
		if((1 << i) & tmp)	u = f[u][i];
	if(u == v)	return u;
	for(rgi i = lg2[dep[u]]; i >= 0; --i)
		if(f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}

int main() {
	T = read();
	for(rgi i = 1; i <= N; ++i)	lg2[i] = lg2[i >> 1] + 1;
	for(rgi kase = 1; kase <= T; ++kase) {
		cnt = 0;
		memset(first, -1, sizeof(first));
		printf("Case %d:\n", kase);
		n = read();
		for(rgi i = 1; i <= n; ++i) {
			int k = read();
			for(rgi j = 1; j <= k; ++j) {
				int u = read();
				Add_Edge(i, u);
				Add_Edge(u, i);
			}
		}
		dfs(1, 0);
		q = read();
		for(rgi i = 1; i <= q; ++i) {
			int u = read(), v = read();
			printf("%d\n", lca(u, v));
		}
	}
	return 0;
}

