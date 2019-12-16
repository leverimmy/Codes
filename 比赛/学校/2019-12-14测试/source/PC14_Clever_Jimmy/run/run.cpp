#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 5e5 + 10;
const int M = 5e5 + 10;

int n, m, q, cnt;
int first[N], dep[N], fa[N], lg2[N] = {-1}, f[N][20], w[N][20];

struct edge {
	int to, _next, wt;
} e[M << 1];

struct EDGE {
	int u, v, w;
	bool operator < (const struct EDGE &rhs) const {
		return w < rhs.w;
	}
} E[M]; 

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int Find(int x) {
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

void Union(int a, int b) {
	int pa = Find(a), pb = Find(b);
	if(pa != pb) fa[pa] = pb;
}

bool Check(int a, int b) {
	return Find(a) == Find(b);
}

void Add_Edge(int u, int v, int w) {
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int p, int weight) {
	dep[x] = dep[p] + 1;
	f[x][0] = p; w[x][0] = weight;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i) {
		f[x][i] = f[f[x][i - 1]][i - 1];
		w[x][i] = std::max(w[x][i - 1], w[f[x][i - 1]][i - 1]); 
	}
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(y != p)
		dfs(y, x, e[i].wt);
}

int lca(int u, int v) {
	int res = 0;
	if(dep[u] > dep[v]) std::swap(u, v);
	int tmp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(tmp & (1 << i)) {
			res = std::max(res, w[v][i]);
			v = f[v][i];
		}
	if(u == v) return res;
	for(rgi i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i]) {
			res = std::max(res, w[u][i]);
			res = std::max(res, w[v][i]);
			u = f[u][i];
			v = f[v][i];
		}
	res = std::max(res, w[u][0]);
	res = std::max(res, w[v][0]);
	return res; 
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	memset(w, 0, sizeof(w));
	for(rgi i = 1; i <= n; ++i) {
		lg2[i] = lg2[i >> 1] + 1;
		fa[i] = i;
	}
	for(rgi i = 1; i <= m; ++i) {
		E[i].u = read(), E[i].v = read(), E[i].w = read();
	} std::sort(E + 1, E + m + 1);
	for(rgi i = 1, tot = 0; i <= m && tot <= n - 1; ++i) {
		int cur_u = E[i].u, cur_v = E[i].v, cur_w = E[i].w;
		if(Check(cur_u, cur_v)) continue;
		Union(cur_u, cur_v);
		Add_Edge(cur_u, cur_v, cur_w);
		Add_Edge(cur_v, cur_u, cur_w);
		tot++;
	} dfs(1, 0, 0);
	q = read();
	for(rgi i = 1; i <= q; ++i) {
		int u = read(), v = read();
		printf("%d\n", lca(u, v));
	}
	return 0;
}

