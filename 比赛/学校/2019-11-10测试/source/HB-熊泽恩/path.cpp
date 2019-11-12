#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, cnt, root1, root2, ans = oo, sum, max_depth;
int first[N], dep[N], lg2[N] = {-1}, rt[N], f[N][20], dis[N];

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
	dep[x] = dep[p] + 1;
	dis[x] = dis[p] + weight;
	f[x][0] = p;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)	dfs(e[i].to, x, e[i].wt);
}

int lca(int u, int v) {
	if(dep[u] > dep[v])	std::swap(u, v);
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

int dist(int u, int v) {
	return dis[u] + dis[v] - 2 * dis[lca(u, v)];
}

int main() {
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)	lg2[i] = lg2[i >> 1] + 1;
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
		sum += w << 1;
	}
	
	for(rgi i = 1; i <= n; ++i)	rt[i] = read();
	
	dfs(1, 0, 0);	max_depth = -1;
	for(rgi i = 1; i <= n; ++i)
		if(dis[i] > max_depth) {
			root1 = i;
			max_depth = dis[i];
		}
	dfs(root1, 0, 0);	max_depth = -1;
	for(rgi i = 1; i <= n; ++i)
		if(dis[i] > max_depth) {
			root2 = i;
			max_depth = dis[i];
		}
	dfs(root2, 0, 0);
	
	for(rgi i = 1; i <= n; ++i)	if(rt[i])
		ans = std::min(ans, sum - std::max(dist(root1, i), dist(root2, i)));
	
	printf("%d", ans);
	
	return 0;
}
/*
5
1 2 1
1 3 1
3 4 3
3 5 4
1 1 1 0 0 

10
1 7 7273
1 9 5130
7 5 476
1 6 4908
5 3 703
1 2 7458
1 4 6528
1 10 2518
2 8 7466
0 0 0 0 1 0 1 1 0 0

*/
