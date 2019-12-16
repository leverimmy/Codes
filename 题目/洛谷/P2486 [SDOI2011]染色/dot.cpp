#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, cnt, idx;
int first[N], rev[N], color[N];

struct edge {
	int to, _next;
} e[M << 1];

struct node {
	int dfn, dep, fa, top, siz, ch;
} T[N];

struct segNode {
	int lc, rc, L, R, add, dat;
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
	T[x].dfn = ++idx;
	rev[idx] = x;
	if(T[x].ch) dfs2(T[x].ch, g);
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to)
		if(y != T[x].fa && y != T[x].ch) dfs2(y, y);
}

void Pushup(int p) {
	t[p].L = t[p << 1].L, t[p].R = t[p << 1 | 1].R;
	t[p].dat = t[p << 1].dat + t[p << 1 | 1].dat;
	if(t[p << 1].R == t[p << 1 | 1].L) t[p].dat--;
}

void Build(int p, int l, int r) {
	t[p].lc = l, t[p].rc = r;
	if(l == r) {
		t[p].L = t[p].R = color[rev[l]];
		t[p].dat = 1;
		return;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	Pushup(p);
}

void Pushdown(int p) {
	if(t[p].add) {
		int C = t[p].add;
		t[p << 1].add = t[p << 1].L = t[p << 1].R = C;
		t[p << 1 | 1].add = t[p << 1 | 1].L = t[p << 1 | 1].R = C;
		t[p << 1].dat = t[p << 1 | 1].dat = 1;
		t[p].add = 0;
	}
}

void Modify(int p, int l, int r, int w) {
	if(l <= t[p].lc && t[p].rc <= r) {
		t[p].L = t[p].R = t[p].add = w;
		t[p].dat = 1;
		return;
	}
	Pushdown(p);
	int mid = t[p].lc + t[p].rc >> 1;
	if(l <= mid) Modify(p << 1, l, r, w);
	if(mid < r) Modify(p << 1 | 1, l, r, w);
	Pushup(p);
}

int Query(int p, int l, int r) {
	if(l <= t[p].lc && t[p].rc <= r) return t[p].dat;
	Pushdown(p);
	int mid = t[p].lc + t[p].rc >> 1, res = 0;
	if(l <= mid) res += Query(p << 1, l, r);
	if(mid < r) res += Query(p << 1 | 1, l, r);
	if(l <= mid && mid < r && t[p << 1].R == t[p << 1 | 1].L) res--;
	return res;
}

int Get(int p, int x) {
	if(t[p].lc == t[p].rc) return t[p].L;
	Pushdown(p);
	int mid = t[p].lc + t[p].rc >> 1;
	if(x <= mid) return Get(p << 1, x);
	else return Get(p << 1 | 1, x);
}

void Paint(int u, int v, int w) {
	while(T[u].top != T[v].top) {
		if(T[T[u].top].dep < T[T[v].top].dep) std::swap(u, v);
		Modify(1, T[T[u].top].dfn, T[u].dfn, w);
		u = T[T[u].top].fa;
	}
	if(T[u].dep > T[v].dep) std::swap(u, v);
	Modify(1, T[u].dfn, T[v].dfn, w);
}

int Check(int u, int v) {
	int res = 0;
	while(T[u].top != T[v].top) {
		if(T[T[u].top].dep < T[T[v].top].dep) std::swap(u, v);
		res += Query(1, T[T[u].top].dfn, T[u].dfn);
		int LC = Get(1, T[T[T[u].top].fa].dfn);
		int RC = Get(1, T[T[u].top].dfn);
		if(LC == RC) res--;
		u = T[T[u].top].fa;
	}
	if(T[u].dep > T[v].dep) std::swap(u, v);
	res += Query(1, T[u].dfn, T[v].dfn);
	return res;
}

int main() {
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i) color[i] = read();
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	} dfs1(1, 0), dfs2(1, 1), Build(1, 1, n);
	for(rgi i = 1; i <= m; ++i) {
		char cmd[5]; int a, b, c;
		scanf("%s", cmd);
		switch(cmd[0]) {
			case 'C':
				a = read(), b = read(), c = read();
				Paint(a, b, c);
				break;
			case 'Q':
				a = read(), b = read();
				printf("%d\n", Check(a, b));
				break;
		}
	}
	return 0;
}

