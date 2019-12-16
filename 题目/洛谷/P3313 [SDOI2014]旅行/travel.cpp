#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 1e5 + 10;
const int K = 1e4 + 10;

int n, m, cnt, idx, totNode;
int first[N], rev[N], W[N], C[N], root[K];

struct edge {
	int to, _next;
} e[M << 1];

struct node {
	int dep, fa, siz, dfn, ch, top;
} T[N];

struct segNode {
	int lc, rc, sum, val;
} t[N * 40];

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
		T[x].siz += T[y].siz;
		if(T[y].siz > T[T[x].ch].siz) T[x].ch = y;
	}
}

void dfs2(int x, int g) {
	T[x].top = g;
	T[x].dfn = ++idx; rev[idx] = x;
	if(T[x].ch) dfs2(T[x].ch, g);
	for(rgi i = first[x], y= e[i].to; ~i; i = e[i]._next, y = e[i].to)
		if(y != T[x].fa && y != T[x].ch) dfs2(y, y);
}

void Pushup(int p) {
	t[p].sum = t[t[p].lc].sum + t[t[p].rc].sum;
	t[p].val = std::max(t[t[p].lc].val, t[t[p].rc].val);
}

void Modify(int &p, int L, int R, int x, int w) {
	if(!p) p = ++totNode;
	if(L == R) {
		t[p].sum += w;
		t[p].val += w;
		return;
	}
	int mid = L + R >> 1;
	if(x <= mid) Modify(t[p].lc, L, mid, x, w);
	else Modify(t[p].rc, mid + 1, R, x, w);
	Pushup(p);
}

void Remove(int p, int L, int R, int x) {
	if(L == R) {
		t[p].sum = t[p].val = 0;
		return;
	}
	int mid = L + R >> 1;
	if(x <= mid) Remove(t[p].lc, L, mid, x);
	else Remove(t[p].rc, mid + 1, R, x);
	Pushup(p);
}

int Query_Max(int p, int L, int R, int l, int r) {
	if(l <= L && R <= r) return t[p].val;
	int mid = L + R >> 1, res = -oo;
	if(l <= mid) res = std::max(res, Query_Max(t[p].lc, L, mid, l, r));
	if(mid < r) res = std::max(res, Query_Max(t[p].rc, mid + 1, R, l, r));
	return res;
}

int Query_Sum(int p, int L, int R, int l, int r) {
	if(l <= L && R <= r) return t[p].sum;
	int mid = L + R >> 1, res = 0;
	if(l <= mid) res += Query_Sum(t[p].lc, L, mid, l, r);
	if(mid < r) res += Query_Sum(t[p].rc, mid + 1, R, l, r);
	return res;
}

void CC(int x, int c) {
	Remove(root[C[x]], 1, n, T[x].dfn);
	Modify(root[c], 1, n, T[x].dfn, W[x]);
	C[x] = c;
}

void CW(int x, int w) {
	int c = C[x];
	Remove(root[C[x]], 1, n, T[x].dfn);
	Modify(root[C[x]], 1, n, T[x].dfn, w);
	W[x] = w;
}

int QM(int u, int v, int c) {
	int res = -oo;
	while(T[u].top != T[v].top) {
		if(T[T[u].top].dep < T[T[v].top].dep) std::swap(u, v);
		res = std::max(res, Query_Max(root[c], 1, n, T[T[u].top].dfn, T[u].dfn));
		u = T[T[u].top].fa;
	}
	if(T[u].dfn > T[v].dfn) std::swap(u, v);
	res = std::max(res, Query_Max(root[c], 1, n, T[u].dfn, T[v].dfn));
	return res;
}

int QS(int u, int v, int c) {
	int res = 0;
	while(T[u].top != T[v].top) {
		if(T[T[u].top].dep < T[T[v].top].dep) std::swap(u, v);
		res += Query_Sum(root[c], 1, n, T[T[u].top].dfn, T[u].dfn);
		u = T[T[u].top].fa;
	}
	if(T[u].dfn > T[v].dfn) std::swap(u, v);
	res += Query_Sum(root[c], 1, n, T[u].dfn, T[v].dfn);
	return res;
}

int main() {
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)	W[i] = read(), C[i] = read();
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	} dfs1(1, 0), dfs2(1, 1);
	for(rgi i = 1; i <= n; ++i)	Modify(root[C[i]], 1, n, T[i].dfn, W[i]);
	for(rgi i = 1; i <= m; ++i) {
		char cmd[5]; int x, y;
		scanf("%s %d %d", cmd, &x, &y);
		switch(cmd[1]) {
			case 'C':
				CC(x, y);
				break;
			case 'W':
				CW(x, y);
				break;
			case 'S':
				printf("%d\n", QS(x, y, C[y]));
				break;
			case 'M':
				printf("%d\n", QM(x, y, C[y]));
				break;
		}
	}
	return 0;
}
/*
5 6
3 1
2 3
1 2
3 3
5 1
1 2
1 3
3 4
3 5
QS 1 5
CC 3 1
QS 1 5
CW 3 3
QS 1 5
QM 2 4

*/
