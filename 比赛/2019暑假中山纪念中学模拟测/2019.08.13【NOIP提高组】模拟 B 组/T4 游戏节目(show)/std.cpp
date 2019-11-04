#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1000000 + 10;

int n, k, cnt1, cnt2, tot;
ll x, y;
ll delta_ab, delta_ac;

int a[N], b[N], c[N];

struct activity
{
	ll ab, ac;
} front[N], back[N];

struct Seg_Tree
{
	ll lc, rc;
	ll val;
} t[N << 2];

il ll read()
{
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs1(int step, int cur, ll dab, ll dac)
{
	if(step >= k)
		return;
	if(dab > 0 && dac > 0)
		y++;
	for(rgi i = cur + 1; i <= n; ++i)
		dfs1(step + 1, i, dab + a[i] - b[i], dac + a[i] - c[i]);
}

void dfs2(int x)
{
	cnt1++;
	front[cnt1].ab = delta_ab;
	front[cnt1].ac = delta_ac;
	for(rgi i = x + 1; i <= n >> 1; ++i)
	{
		delta_ab += a[i] - b[i];
		delta_ac += a[i] - c[i];
		dfs2(i);
		delta_ab -= a[i] - b[i];
		delta_ac -= a[i] - c[i];
	}
}

void dfs3(int x)
{
	cnt2++;
	back[cnt2].ab = delta_ab;
	back[cnt2].ac = delta_ac;
	for(rgi i = x + 1; i <= n; ++i)
	{
		delta_ab += a[i] - b[i];
		delta_ac += a[i] - c[i];
		dfs3(i);
		delta_ab -= a[i] - b[i];
		delta_ac -= a[i] - c[i];
	}
}

void Modify(int p, ll l, ll r, ll pos, int val)
{
	t[p].val += val;
	if(l >= r)
		return;
	ll mid = l + r >> 1;
	if(pos <= mid)
	{
		if(!t[p].lc)
		{
			tot++;
			t[p].lc = tot;
		}
		Modify(t[p].lc, l, mid, pos, val);
		if(!t[t[p].lc].val)
			t[p].lc = 0;
	}
	else
	{
		if(!t[p].rc)
		{
			tot++;
			t[p].rc = tot;
		}
		Modify(t[p].rc, mid + 1, r, pos, val);
		if(!t[t[p].rc].val)
			t[p].rc = 0;
	}
}

ll Query(int p, ll l, ll r, ll pos)
{
	ll res = 0;
	if(l >= r)
		return t[p].val;
	ll mid = l + r >> 1;
	if(pos <= mid)
	{
		if(t[p].lc)
			res += Query(t[p].lc, l, mid, pos);
	}
	else
	{
		if(t[p].lc)
			res += t[t[p].lc].val;
		if(t[p].rc)
			res += Query(t[p].rc, mid + 1, r, pos);
	}
	return res;
}

bool cmp2(struct activity a, struct activity b)
{
	return a.ab < b.ab;
}

bool cmp3(struct activity a, struct activity b)
{
	return a.ab > b.ab;
}

signed main()
{
	freopen("show.in", "r", stdin);
	freopen("show.out", "w", stdout);
	n = read(), k = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	for(rgi i = 1; i <= n; ++i)
		b[i] = read();
	for(rgi i = 1; i <= n; ++i)
		c[i] = read();
	dfs1(0, 0, 0, 0);
	dfs2(0);
	dfs3(n >> 1);
	sort(front + 1, front + cnt1 + 1, cmp2);
	sort(back + 1, back + cnt2 + 1, cmp3);
	int j = 1;
	for(rgi i = 1; i <= cnt1; ++i)
	{
		while(j <= cnt2 && front[i].ab + back[j].ab > 0)
		{
			Modify(0, 0, 8000000000, 4000000000 - back[j].ac, 1);
			j++;
		}
		x += Query(0, 0, 8000000000, front[i].ac - 1 + 4000000000);
	}
	printf("%lld", x - y);
	return 0;
}

