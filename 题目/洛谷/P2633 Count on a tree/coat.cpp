#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 5e6 + 10;
const int M = 5e6 + 10;

int n, m, cnt, cntNode, totNum, last;
int first[N], dep[N], lg2[N] = {-1}, f[N][20];
int a[N], root[N], num[N << 1], to[N];

struct edge {
	int to, _next;
} e[M << 1];

struct segNode {
	int lc, rc, dat;
} t[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Build(int &p, int l, int r) {
	if(!p) p = ++cntNode;
	if(l == r) return;
	int mid = l + r >> 1;
	Build(t[p].lc, l, mid);
	Build(t[p].rc, mid + 1, r);
}

void Insert(int &p, int pre, int val, int L, int R) {
	p = ++cntNode;
	t[p].lc = t[pre].lc, t[p].rc = t[pre].rc, t[p].dat = t[pre].dat + 1;
	if(L == R) return;
	int mid = L + R >> 1;
	if(val <= mid)
		Insert(t[p].lc, t[pre].lc, val, L, mid);
	else
		Insert(t[p].rc, t[pre].rc, val, mid + 1, R);
}

int Query(int U, int V, int p, int fa, int val, int L, int R) {
	if(L == R) return L;
	int mid = L + R >> 1;
	int delta = t[t[U].lc].dat + t[t[V].lc].dat - t[t[p].lc].dat - t[t[fa].lc].dat;
	if(val <= delta)
		return Query(t[U].lc, t[V].lc, t[p].lc, t[fa].lc, val, L, mid);
	else
		return Query(t[U].rc, t[V].rc, t[p].rc, t[fa].rc, val - delta, mid + 1, R);
}

void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int p) {
	Insert(root[x], root[p], a[x], 1, n);
	dep[x] = dep[p] + 1;
	f[x][0] = p;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p) dfs(e[i].to, x);
}

int lca(int u, int v) {
	if(dep[u] > dep[v]) std::swap(u, v);
	int tmp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(tmp & (1 << i)) v = f[v][i];
	if(u == v) return u;
	for(rgi i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}

int main() {
	n = read(), m = read();
	Build(root[0], 1, n);
	for(rgi i = 1; i <= n; ++i) lg2[i] = lg2[i >> 1] + 1;
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i) {
		a[i] = read();
		num[++totNum] = a[i];
	}
	
	std::sort(num + 1, num + totNum + 1);
	totNum = std::unique(num + 1, num + totNum + 1) - (num + 1);
	for(rgi i = 1; i <= n; ++i) {
		int pos = std::lower_bound(num + 1, num + totNum + 1, a[i]) - (num + 1) + 1;
		to[pos] = a[i];
		a[i] = pos;
	}
		
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	dfs(1, 0);
	for(rgi i = 1; i <= m; ++i) {
		int u = read() ^ last, v = read(), k = read();
		int LCA = lca(u, v);
		int ans = to[Query(root[u], root[v], root[LCA], root[f[LCA][0]], k, 1, n)];
		printf("%d\n", ans);
		last = ans;
	}
	return 0;
}
/*
8 5
105 2 9 3 8 5 7 7
1 2
1 3
1 4
3 5
3 6
3 7
4 8
2 5 1
0 5 2
10 5 3
11 5 4
110 8 2

*/
