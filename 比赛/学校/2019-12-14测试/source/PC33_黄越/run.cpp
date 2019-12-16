#pragma GCC optimize(2)
#pragma G++ optimize(2)
#pragma comment(linker, "/STACK:10240000,10240000")
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int read() {
	int x, c;
	while (!isdigit(c = getchar())); x = c - 48;
	while (isdigit(c = getchar())) x = x * 10 + c - 48;
	return x;
}

struct e {
	int u, v, w;
} v[300010];
struct edge {
	int v, w;
	edge(int a, int b): v(a), w(b) {}
};
vector<edge> V[100010];
int fa[100010][18], mx[100010][18], dep[100010];
bool operator<(e a, e b) { return a.w < b.w; }
int f[100010];
int _(int x) { return x == f[x] ? x : f[x] = _(f[x]); }
int lca(int x, int y) {
	//printf("lca(%d, %d): \n", x, y);
	int m = 0;
	if (dep[x] < dep[y]) swap(x, y);
	int del = dep[x] - dep[y];
	for (int i = 17; i >= 0; --i)
		if (del & (1 << i))
			m = max(m, mx[x][i]), x = fa[x][i];
	//printf("\tafter jump = %d %d %d\n", x, y, m);
	for (int i = 17; i >= 0; --i)
		if (fa[x][i] != fa[y][i])
			m = max(m, max(mx[x][i], mx[y][i])), x = fa[x][i], y = fa[y][i];
	//printf("\tres = %d %d\n", fa[x][0], m);
	return max(m, max(mx[x][0], mx[y][0]));
}

void dfs(int x, int fa = 0) {
	//printf("dfs(%d, %d)\n", x, fa);
	if (dep[x]) return;
	dep[x] = dep[fa] + 1;
	::fa[x][0] = fa;
	for (int i = 0; i < V[x].size(); ++i)
		if (V[x][i].v != fa)
			mx[V[x][i].v][0] = V[x][i].w, dfs(V[x][i].v, x);
}

int main() {
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 0; i < m; ++i)
		v[i].u = read(),
		v[i].v = read(),
		v[i].w = read();
	sort(v, v + m);
	for (int i = 1; i <= n; ++i)
		f[i] = i;
	for (int i = 0; i < m; ++i)
		if (_(v[i].u) != _(v[i].v)) {
			f[_(v[i].u)] = _(v[i].v);
			V[v[i].u].push_back(edge(v[i].v, v[i].w));
			V[v[i].v].push_back(edge(v[i].u, v[i].w));
		}
	dfs(1);
	for (int i = 1; i <= 17; ++i)
		for (int j = 1; j <= n; ++j)
			fa[j][i] = fa[fa[j][i - 1]][i - 1],
			mx[j][i] = max(mx[j][i - 1], mx[fa[j][i - 1]][i - 1]);
			//printf("(%d, %d) ", fa[j][i], mx[j][i]);
	for (int t = read(); t--; printf("%d\n", lca(read(), read())));
}

/*
8 7
2 1 1
2 5 6
5 7 3
3 4 5
4 8 4
3 6 7
2 3 2
3
7 4
1 3
4 2
*/
