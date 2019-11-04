#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int N = 200000 + 10;
const int M = 200000 + 10;

int n, q, rt, cnt, idx;
int first[N], W[N], maxx[N];
int f[N], dep[N], siz[N], son[N], dfn[N], rev[N], top[N];

struct edge
{
	int to, _next;
} e[M << 1];

struct Seg_Tree
{
	int lc, rc;
	int add, val;
} t[N << 2];

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v)
{
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void Update(int p)
{
	t[p].val = t[p << 1].val + t[p << 1 | 1].val;
}

void Build(int p, int l, int r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
	{
		t[p].val = W[rev[l]];
		return;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	Update(p);
}

void Spread(int p)
{
	if(t[p].add != 0)
	{
		t[p << 1].add = t[p << 1].add + t[p].add;
		t[p << 1 | 1].add = t[p << 1 | 1].add + t[p].add;
		t[p << 1].val = t[p << 1].val + t[p].add * (t[p << 1].rc - t[p << 1].lc + 1);
		t[p << 1 | 1].val = t[p << 1 | 1].val + t[p].add * (t[p << 1 | 1].rc - t[p << 1 | 1].lc + 1);
		t[p].add = 0;
	}
}

void Add(int p, int l, int r, int val)
{
	if(l <= t[p].lc && t[p].rc <= r)
	{
		t[p].add = t[p].add + val;
		t[p].val = t[p].val + (t[p].rc - t[p].lc + 1) * val;
		return;
	}
	Spread(p);
	int mid = t[p].lc + t[p].rc >> 1;
	if(l <= mid)
		Add(p << 1, l, r, val);
	if(mid < r)
		Add(p << 1 | 1, l, r, val);
	Update(p);
}

int Query(int p, int l, int r)
{
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].val;
	Spread(p);
	int mid = t[p].lc + t[p].rc >> 1;
	int res = 0;
	if(l <= mid)
		res = res + Query(p << 1, l, r);
	if(mid < r)
		res = res + Query(p << 1 | 1, l, r);
	return res;
}

void dfs1(int x, int p)
{
	f[x] = p;
	siz[x] = 1;
	dep[x] = dep[p] + 1;
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)
		{
			dfs1(e[i].to, x);
			siz[x] += siz[e[i].to];
			if(siz[e[i].to] > siz[son[x]])
				son[x] = e[i].to;
		}
}

void dfs2(int x, int tp)
{
	top[x] = tp;
	dfn[x] = ++idx;
	rev[idx] = x;
	if(son[x])
		dfs2(son[x], tp);//先走重儿子
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != son[x] && e[i].to != f[x])//不是它重儿子也不是它父亲
			dfs2(e[i].to, e[i].to);//轻链的top就是自己
}

int Query_Line(int u, int v)
{
	int res = 0;
	while(top[u] != top[v])
	{
		if(dep[top[u]] < dep[top[v]])
			swap(u, v);
		res += Query(1, dfn[top[u]], dfn[u]);
		u = f[top[u]];
	}
	if(dfn[u] > dfn[v])
		swap(u, v);
	res += Query(1, dfn[u], dfn[v]);
	return res;
}

void Add_Line(int u, int v, int w)
{
	while(top[u] != top[v])
	{
		if(dep[top[u]] < dep[top[v]])
			swap(u, v);
		Add(1, dfn[top[u]], dfn[u], w);
		u = f[top[u]];
	}
	if(dfn[u] > dfn[v])
		swap(u, v);
	Add(1, dfn[u], dfn[v], w);
}

void Add_Sub(int u, int val)
{
	Add(1, dfn[u], dfn[u] + siz[u] - 1, val);
}

int Query_Sub(int u)
{
	return Query(1, dfn[u], dfn[u] + siz[u] - 1);
}

int main()
{
	n = read(), q = read(), rt = 1;
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)
		W[i] = 0;
	for(rgi i = 1; i <= n - 1; ++i)
	{
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	dfs1(rt, 0);
	dfs2(rt, rt);
	Build(1, 1, n);
	for(rgi i = 1; i <= q; ++i)
	{
		int P = read(), Q = read();
		Add_Sub(P, Q);
	}
	for(rgi i = 1; i <= n; ++i)
		printf("%d ", Query_Line(i, i));
	return 0;
}

