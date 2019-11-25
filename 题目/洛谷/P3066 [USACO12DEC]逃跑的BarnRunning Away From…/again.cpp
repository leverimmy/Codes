#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 2e5 + 10;
const int M = 2e5 + 10;

int n, cnt, tot, cntNode, cntDfn;
int first[N], dfn[N], out[N], root[N];

ll L, dep[N], num[N], a[N];

struct edge {
	int to, _next;
	ll wt;
} e[M << 1];

struct segNode {
	int lc, rc;
	ll dat;
} t[N * 40];

void Add_Edge(int u, int v, ll w) {
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void Build(int &p, int l, int r) {
	if(!p) p = ++cntNode;
	if(l == r) return;
	int mid = l + r >> 1;
	Build(t[p].lc, l, mid);
	Build(t[p].rc, mid + 1, r);
}

void Insert(int &p, int pre, ll val, int l, int r) {
	p = ++cntNode;
	t[p].lc = t[pre].lc, t[p].rc = t[pre].rc, t[p].dat = t[pre].dat + 1;
	if(l == r) return;
	int mid = l + r >> 1;
	if(val <= mid) Insert(t[p].lc, t[pre].lc, val, l, mid);
	else	Insert(t[p].rc, t[pre].rc, val, mid + 1, r);
}

ll Query(int p, int pre, ll val, int l, int r) {
	if(r < val) return t[p].dat - t[pre].dat;
	if(l >= val) return 0;
	int mid = l + r >> 1;
	if(val <= mid) return Query(t[p].lc, t[pre].lc, val, l, mid);
	else	return Query(t[p].rc, t[pre].rc, val, mid + 1, r) + t[t[p].lc].dat - t[t[pre].lc].dat;
}

void dfs(int x, int p, ll w) {
	dfn[x] = ++cntDfn;
	dep[x] = dep[p] + w;
	a[++tot] = dep[x];
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p) dfs(e[i].to, x, e[i].wt);
	out[x] = cntDfn;
}

int main() {
//	freopen("testdata.in", "r", stdin);
	scanf("%d %lld", &n, &L);
	memset(first, -1, sizeof(first));
	Build(root[0], 1, n);
	for(rgi i = 2; i <= n; ++i) {
		int v; ll w;
		scanf("%d %lld", &v, &w);
		Add_Edge(i, v, w);
		Add_Edge(v, i, w);
	} dfs(1, 0, 0);
	
	for(rgi i = 1; i <= n; ++i) num[i] = dep[i];
	std::sort(num + 1, num + tot + 1);
	tot = std::unique(num + 1, num + tot + 1) - (num + 1);
	for(rgi i = 1; i <= n; ++i) {
		int pos = std::lower_bound(num + 1, num + tot + 1, a[i]) - (num + 1) + 1;
		Insert(root[i], root[i - 1], pos, 1, tot);
	}
	num[tot + 1] = oo;
	
	for(rgi i = 1; i <= n; ++i) {
		int pos = std::upper_bound(num + 1, num + tot + 2, a[dfn[i]] + L) - (num + 1) + 1;
		printf("%lld\n", Query(root[out[i]], root[dfn[i] - 1], pos, 1, tot));
	}
	return 0;
}
/*
4 5
1 4
2 3
1 5

*/
