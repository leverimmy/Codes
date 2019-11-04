#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define il inline

using namespace std;

const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, cnt;
int first[N], lg2[N] = {-1}, dep[N] = {-1}, p[N], f[N][20];

struct edge {
	int to, _next;
} e[M << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

int Find(int x) {
	return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int a, int b) {
	int pa = Find(a), pb = Find(b);
	if(pa != pb)
		p[pa] = pb;
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
	if(dep[u] > dep[v])	swap(u, v);
	int tmp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(tmp & (1 << i))
			v = f[v][i];
	if(u == v)	return u;
	for(rgi i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}

void Modify(int u, int v) {
	Union(u, v);
}

int Query(int u) {
	int res = 0;
	for(; u != 1; u = Find(f[u][0]))	res++;
	return res;
}

int main() {
//	freopen("meg.in", "r", stdin);
//	freopen("meg.out", "w", stdout);
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)	lg2[i] = lg2[i >> 1] + 1, p[i] = i;
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	dfs(1, 0);
	m = read();
	for(rgi i = 1; i <= n + m - 1; ++i) {
		char op[5]; scanf("%s", op);
		if(op[0] == 'A') {
			int u = read(), v = read(), LCA;
			u = Find(u), v = Find(v), LCA = Find(lca(u, v));
			Modify(u, LCA);
			Modify(v, LCA);
		}
		else if(op[0] == 'W') {
			int u = Find(read());
			printf("%d\n", Query(u));
		}
	}
	return 0;
}
/*
5
1 2
1 3
1 4
4 5
4
W 5
A 1 4
W 5
A 4 5
W 5
W 2
A 1 2
A 1 3

9
1 2
1 3
2 4
2 5
4 6
3 7
3 8
3 9
0
A 2 4
W 6
A 1 2
W 5

*/
