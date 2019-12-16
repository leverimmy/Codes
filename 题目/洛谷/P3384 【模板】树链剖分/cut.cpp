#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, root, mod, cnt, idx;
int first[N], W[N], rev[N];

struct node {
	int dep, fa, siz, ch, dfn, top;
	node() {ch = 0;}
} T[N];

struct edge {
	int to, _next;
} e[M << 1];

struct segNode {
	int lc, rc, dat, add;
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
	T[x].fa = p;
	T[x].siz = 1;
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(y != p) {
		dfs1(y, x);
		if(T[y].siz > T[T[x].ch].siz)
			T[x].ch = y;
		T[x].siz += T[y].siz;
	}
}

void dfs2(int x, int g) {
	T[x].top = g;
	T[x].dfn = ++idx;
	rev[idx] = x;
	if(T[x].ch)  dfs2(T[x].ch, g);
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to)
		if(y != T[x].fa && y != T[x].ch) dfs2(y, y);
}

void Pushup(int p) {
	t[p].dat = t[p << 1].dat + t[p << 1 | 1].dat;
}

void Build(int p, int l, int r) {
	t[p].lc = l, t[p].rc = r;
	if(l == r) {
		t[p].dat = W[rev[l]];
		return;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid), Build(p << 1 | 1, mid + 1, r);
	Pushup(p);
}

void Pushdown(int p) {
	if(t[p].add != 0) {
		t[p << 1].add += t[p].add, t[p << 1].dat += (t[p << 1].rc - t[p << 1].lc + 1) * t[p].add;
		t[p << 1 | 1].add += t[p].add, t[p << 1 | 1].dat += (t[p << 1 | 1].rc - t[p << 1 | 1].lc + 1) * t[p].add;
		t[p << 1].add %= mod, t[p << 1].dat %= mod;
		t[p << 1 | 1].add %= mod, t[p << 1 | 1].dat %= mod;
		t[p].add = 0;
	}
}

void Modify(int p, int l, int r, ll val) {
	if(l <= t[p].lc && t[p].rc <= r) {
		t[p].add += val, t[p].add %= mod;
		t[p].dat += (t[p].rc - t[p].lc + 1) * val, t[p].dat %= mod;
		return;
	} Pushdown(p);
	int mid = t[p].lc + t[p].rc >> 1;
	if(l <= mid) Modify(p << 1, l, r, val);
	if(mid < r) Modify(p << 1 | 1, l, r, val);
	Pushup(p);
}

ll Query(int p, int l, int r) {
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].dat;
	Pushdown(p);
	int mid = t[p].lc + t[p].rc >> 1; ll res = 0;
	if(l <= mid) res += Query(p << 1, l, r), res %= mod;
	if(mid < r) res += Query(p << 1 | 1, l, r), res %= mod;
	return res;
}

void Add_Line(int u, int v, int w) {
	while(T[u].top != T[v].top) {
		if(T[T[u].top].dep < T[T[v].top].dep) std::swap(u, v);
		Modify(1, T[T[u].top].dfn, T[u].dfn, w);
		u = T[T[u].top].fa;
	}
	if(T[u].dep > T[v].dep) std::swap(u, v);
	Modify(1, T[u].dfn, T[v].dfn, w);
}

ll Query_Line(int u, int v) {
	ll res = 0;
	while(T[u].top != T[v].top) {
		if(T[T[u].top].dep < T[T[v].top].dep) std::swap(u, v);
		res += Query(1, T[T[u].top].dfn, T[u].dfn), res %= mod;
		u = T[T[u].top].fa;
	}
	if(T[u].dep > T[v].dep) std::swap(u, v);
	res += Query(1, T[u].dfn, T[v].dfn), res %= mod;
	return res;
}

void Add_Sub(int x, int w) {
	Modify(1, T[x].dfn, T[x].dfn + T[x].siz - 1, w);
}

ll Query_Sub(int x) {
	return Query(1, T[x].dfn, T[x].dfn + T[x].siz - 1);
}

int main() {
//	freopen("cut.in", "r", stdin);
//	freopen("cut.out", "w", stdout);
	n = read(), m = read(), root = read(), mod = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i) W[i] = read();
	for(rgi i = 1; i <= n - 1; ++i) {
		int x = read(), y = read();
		Add_Edge(x, y);
		Add_Edge(y, x);
	} dfs1(root, 0), dfs2(root, root), Build(1, 1, n);
	for(rgi i = 1; i <= m; ++i) {
		int opt = read(), x, y, z;
		switch(opt) {
			case 1:
				x = read(), y = read(), z = read();
				Add_Line(x, y, z);
				break;
			case 2:
				x = read(), y = read();
				printf("%lld\n", Query_Line(x, y));
				break;
			case 3:
				x = read(), y = read();
				Add_Sub(x, y);
				break;
			case 4:
				x = read();
				printf("%lld\n", Query_Sub(x));
				break;
		}
	}
	return 0;
}
/*
8 10 2 448348
458 718 447 857 633 264 238 944 
1 2
2 3
3 4
6 2
1 5
5 7
8 6
3 7 611
4 6
3 1 267
3 2 111
1 6 3 153
3 7 673
4 8
2 6 1
4 7
3 4 228

*/
