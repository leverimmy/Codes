#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

using namespace std;

const int N = 3e5 + 10;
const int M = 3e5 + 10;

int n, cnt;
int first[N], dep[N], lg2[N] = {-1}, f[N][20], w[N], a[N];

struct edge {
	int to, _next;
} e[M << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs1(int x, int p) {
	dep[x] = dep[p] + 1;
	f[x][0] = p;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)	dfs1(e[i].to, x);
}

int lca(int u, int v) {
	if(dep[u] > dep[v])	swap(u, v);
	int tmp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(tmp & (1 << i))	v = f[v][i];
	if(u == v)	return u;
	for(rgi i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}

void dfs2(int x, int p) {
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p) {
			dfs2(e[i].to, x);
			w[x] += w[e[i].to];
		}
}

int main() {
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)	lg2[i] = lg2[i >> 1] + 1;
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	dfs1(1, 0);
	for(rgi i = 1; i <= n - 1; ++i) {
		int LCA = lca(a[i], a[i + 1]);
		w[a[i]]++;
		w[a[i + 1]]++;
		w[LCA]--;
		w[f[LCA][0]]--;
	}
	dfs2(1, 0);
	for(rgi i = 2; i <= n; ++i)	w[a[i]]--;
	for(rgi i = 1; i <= n; ++i)	printf("%d\n", w[i]);
	return 0;
}
/*
5
1 4 5 3 2
1 2
2 4
2 3
4 5

*/
