#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 3e4 + 10;
const int M = 3e4 + 10;

int n, m, cnt, idx;
int first[N], W[N], rev[N];

struct edge {
	int to, _next;
} e[M << 1];

struct node {
	int dep, fa, top, dfn, siz, ch;
	node() {ch = 0;}
} T[N];

struct segNode {
	int lc, rc, sum, val;
	segNode() {sum = 0, val = -oo;}
} t[N << 2];

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

void dfs1(int x, int p) {
	T[x].dep = T[p].dep + 1;
	T[x].siz = 1;
	T[x].fa = p;
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(y != p) {
		dfs1(y, x);
		T[x].siz += T[y].siz;
		if(T[y].siz > T[T[x].ch].siz) T[x].ch = y;
	}
}

void dfs2(int x, int g) {
	T[x].top = g;
	T[x].dfn = ++idx, rev[idx] = x;
	if(T[x].ch) dfs2(T[x].ch, g);
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to)
		if(y != T[x].fa && y != T[x].ch) dfs2(y, y);
}

void Pushup(int p) {
	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
	t[p].val = std::max(t[p << 1].val, t[p << 1 | 1].val);
}

void Build(int p, int l, int r) {
	t[p].lc = l, t[p].rc = r;
	if(l == r) {
		t[p].sum = t[p].val = W[rev[l]];
		return;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid), Build(p << 1 | 1, mid + 1, r);
	Pushup(p);
}

void Modify(int p, int x, int w) {
	if(t[p].lc == t[p].rc) {
		t[p].sum = t[p].val = w;
		return;
	}
	int mid = t[p].lc + t[p].rc >> 1;
	if(x <= mid) Modify(p << 1, x, w);
	else Modify(p << 1 | 1, x, w);
	Pushup(p);
}

int Query_Sum(int p, int l, int r) {
	if(l <= t[p].lc && t[p].rc <= r) return t[p].sum;
	int mid = t[p].lc + t[p].rc >> 1, res = 0;
	if(l <= mid) res += Query_Sum(p << 1, l, r);
	if(mid < r) res += Query_Sum(p << 1 | 1, l, r);
	return res;
}

int Query_Max(int p, int l, int r) {
	if(l <= t[p].lc && t[p].rc <= r) return t[p].val;
	int mid = t[p].lc + t[p].rc >> 1, res = -oo;
	if(l <= mid) res = std::max(res, Query_Max(p << 1, l, r));
	if(mid < r) res = std::max(res, Query_Max(p << 1 | 1, l, r));
	return res;
}

int QMAX(int u, int v) {
	int res = -oo;
	while(T[u].top != T[v].top) {
		if(T[T[u].top].dep < T[T[v].top].dep) std::swap(u, v);
		res = std::max(res, Query_Max(1, T[T[u].top].dfn, T[u].dfn));
		u = T[T[u].top].fa;
	}
	if(T[u].dep > T[v].dep) std::swap(u, v);
	res = std::max(res, Query_Max(1, T[u].dfn, T[v].dfn));
	return res;
}

int QSUM(int u, int v) {
	int res = 0;
	while(T[u].top != T[v].top) {
		if(T[T[u].top].dep < T[T[v].top].dep) std::swap(u, v);
		res += Query_Sum(1, T[T[u].top].dfn, T[u].dfn);
		u = T[T[u].top].fa;
	}
	if(T[u].dep > T[v].dep) std::swap(u, v);
	res += Query_Sum(1, T[u].dfn, T[v].dfn);
	return res;
}

int main() {
//	freopen("calc.in", "r", stdin);
//	freopen("calc.out", "w", stdout);
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	for(rgi i = 1; i <= n; ++i) W[i] = read();
	dfs1(1, 0), dfs2(1, 1), Build(1, 1, n);
	m = read();
	for(rgi i = 1; i <= m; ++i) {
		char cmd[10]; int u, v;
		scanf("%s %d %d", cmd, &u, &v);
		switch(cmd[1]) {
			case 'H':
				Modify(1, T[u].dfn, v);
				break;
			case 'M':
				printf("%d\n", QMAX(u, v));
				break;
			case 'S':
				printf("%d\n", QSUM(u, v));
				break;
		}
	}
	return 0;
}
 
