#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 100000 + 10;

int n;
int a[N], rev[N];
int Less[N], Greater[N];

struct Seg_Tree
{
	int lc, rc;
	int val, add;
} t[N << 2], L[N << 2], G[N << 2];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Update(int p)
{
	t[p].val = t[p << 1].val + t[p << 1 | 1].val;
}

void Update_Less(int p)
{
	L[p].val = L[p << 1].val + L[p << 1 | 1].val;
}

void Update_Greater(int p)
{
	G[p].val = G[p << 1].val + G[p << 1 | 1].val;
}

void Build(int p, int l, int r)
{
	t[p].lc = l, t[p].rc = r;
	if(l == r)
	{
		t[p].val = 0;
		return;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	Update(p);
}

void Build_Less(int p, int l, int r)
{
	L[p].lc = l, L[p].rc = r;
	if(l == r)
	{
		L[p].val = Less[l];
		return;
	}
	int mid = l + r >> 1;
	Build_Less(p << 1, l, mid);
	Build_Less(p << 1 | 1, mid + 1, r);
	Update_Less(p);
}

void Build_Greater(int p, int l, int r)
{
	G[p].lc = l, G[p].rc = r;
	if(l == r)
	{
		G[p].val = Greater[l];
		return;
	}
	int mid = l + r >> 1;
	Build_Greater(p << 1, l, mid);
	Build_Greater(p << 1 | 1, mid + 1, r);
	Update_Greater(p);
}

void Spread(int p)
{
	if(t[p].add != 0)
	{
		t[p << 1].add += t[p].add;
		t[p << 1 | 1].add += t[p].add;
		t[p << 1].val += t[p].add * (t[p << 1].rc - t[p << 1].lc + 1);
		t[p << 1 | 1].val += t[p].add * (t[p << 1 | 1].rc - t[p << 1 | 1].lc + 1);
		t[p].add = 0;
	}
}

void Spread_Less(int p)
{
	if(L[p].add != 0)
	{
		L[p << 1].add += L[p].add;
		L[p << 1 | 1].add += L[p].add;
		L[p << 1].val += L[p].add * (L[p << 1].rc - L[p << 1].lc + 1);
		L[p << 1 | 1].val += L[p].add * (L[p << 1 | 1].rc - L[p << 1 | 1].lc + 1);
		L[p].add = 0;
	}
}

void Spread_Greater(int p)
{
	if(G[p].add != 0)
	{
		G[p << 1].add += G[p].add;
		G[p << 1 | 1].add += G[p].add;
		G[p << 1].val += G[p].add * (G[p << 1].rc - G[p << 1].lc + 1);
		G[p << 1 | 1].val += G[p].add * (G[p << 1 | 1].rc - G[p << 1 | 1].lc + 1);
		G[p].add = 0;
	}
}

void Add(int p, int l, int r, int val)
{
	if(l <= t[p].lc && t[p].rc <= r)
	{
		t[p].add += val;
		t[p].val += val * (t[p].rc - t[p].lc + 1);
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

void Add_Less(int p, int l, int r, int val)
{
	if(l <= L[p].lc && L[p].rc <= r)
	{
		L[p].add += val;
		L[p].val += val * (L[p].rc - L[p].lc + 1);
		return;
	}
	Spread_Less(p);
	int mid = L[p].lc + L[p].rc >> 1;
	if(l <= mid)
		Add_Less(p << 1, l, r, val);
	if(mid < r)
		Add_Less(p << 1 | 1, l, r, val);
	Update_Less(p);
}

void Add_Greater(int p, int l, int r, int val)
{
	if(l <= G[p].lc && G[p].rc <= r)
	{
		G[p].add += val;
		G[p].val += val * (G[p].rc - G[p].lc + 1);
		return;
	}
	Spread_Greater(p);
	int mid = G[p].lc + G[p].rc >> 1;
	if(l <= mid)
		Add_Greater(p << 1, l, r, val);
	if(mid < r)
		Add_Greater(p << 1 | 1, l, r, val);
	Update_Greater(p);
}

int Query(int p, int l, int r)
{
	if(l <= t[p].lc && t[p].rc <= r)
		return t[p].val;
	Spread(p);
	int mid = t[p].lc + t[p].rc >> 1;
	int res = 0;
	if(l <= mid)
		res += Query(p << 1, l, r);
	if(mid < r)
		res += Query(p << 1 | 1, l, r);
	return res;
}

int Query_Less(int p, int l, int r)
{
	if(l <= L[p].lc && L[p].rc <= r)
		return L[p].val;
	Spread_Less(p);
	int mid = L[p].lc + L[p].rc >> 1;
	int res = 0;
	if(l <= mid)
		res += Query_Less(p << 1, l, r);
	if(mid < r)
		res += Query_Less(p << 1 | 1, l, r);
	return res;
}

int Query_Greater(int p, int l, int r)
{
	if(l <= G[p].lc && G[p].rc <= r)
		return G[p].val;
	Spread_Greater(p);
	int mid = G[p].lc + G[p].rc >> 1;
	int res = 0;
	if(l <= mid)
		res += Query_Greater(p << 1, l, r);
	if(mid < r)
		res += Query_Greater(p << 1 | 1, l, r);
	return res;
}

int main()
{
	n = read();
	Build(1, 1, n);
	for(rgi i = 1; i <= n; ++i)
	{
		a[i] = read();
		rev[a[i]] = i;
	}
	for(rgi i = n; i >= 1; --i)
	{
		Less[i] = Query(1, 1, a[i] - 1);
		Add(1, a[i], a[i], 1);
	}
	Build_Less(1, 1, n);//Less:后面比它小的个数
	/*
	for(rgi i = 1; i <= n; ++i)
		printf("%d ", Less[i]);
	puts("");*/
	Build(1, 1, n);
	for(rgi i = 1; i <= n; ++i)
	{
		Greater[i] = Query(1, a[i] + 1, n);
		Add(1, a[i], a[i], 1);
	}
	Build_Greater(1, 1, n);//Greater:前面比它大的个数
	/*
	for(rgi i = 1; i <= n; ++i)
		printf("%d ", Greater[i]);
	puts("");*/
	for(rgi i = 1; i <= n; ++i)
	{
		if(i & 1)
		{
			int pos = i + 1 >> 1;
			printf("%d\n", Query_Greater(1, rev[pos], rev[pos]));
			Add_Less(1, 1, rev[pos] - 1, -1);
		}
		else
		{
			int pos = n - (i >> 1) + 1;
			printf("%d\n", Query_Less(1, rev[pos], rev[pos]));
			Add_Greater(1, rev[pos] + 1, n, -1);
		}
	}
	return 0;
}

