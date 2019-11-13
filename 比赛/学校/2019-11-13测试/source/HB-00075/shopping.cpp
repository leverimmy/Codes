#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 0x3f3f3f3fll
#define NO 10005
#define ls o << 1
#define rs o << 1 | 1
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, pair<int, int> > pii;
ll read()
{
	ll ret = 0;
	char ch = ' ', last;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = ((ret + (ret << 2)) << 1) + (ch ^ '0'), ch = getchar();
	return last == '-' ? -ret : ret;
}
void write(ll x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
//head

int n, m;
ll tot, a[NO], sl[NO << 2], sr[NO << 2], s2m[NO << 2], c[NO << 2], lz[NO << 2];
struct node
{
	int s2m, sl, sr, c;
};
pair<int, int> q;
//variable

void upd(int o)
{
	if (!c[ls])
	{
		sl[o] = 0, sr[o] = sr[rs], s2m[o] = s2m[rs], c[o] = c[rs];
		return;
	}
	if (!c[rs])
	{
		sl[o] = sl[ls], sr[o] = 0, s2m[o] = s2m[ls], c[o] = c[ls];
		return;
	}
	sl[o] = sl[ls];
	if (c[ls] == 1 && sr[ls])
		sl[o] += sl[rs];
	sr[o] = sr[rs];
	if (c[rs] == 1 && sl[rs])
		sr[o] += sr[ls];
	s2m[o] = s2m[ls] + s2m[rs], c[o] = c[ls] + c[rs] - 1;
	if (c[ls] > 1 && c[rs] > 1)
		s2m[o] += (sr[ls] + sl[rs]) * (sr[ls] + sl[rs]);
	if (!(sr[ls] * sl[rs]))
		c[o]++;
}
node upd(node x, node y)
{
	if (!y.c)
	{
		x.sr = 0;
		return x;
	}
	if (!x.c)
	{
		y.sl = 0;
		return y;
	}
	node ret;
	ret.sl = x.sl;
	if (x.c == 1 && x.sr)
		ret.sl += y.sl;
	ret.sr = y.sr;
	if (y.c == 1 && y.sl)
		ret.sr += x.sr;
	ret.s2m = x.s2m + y.s2m, ret.c = x.c + y.c - 1;
	if (x.c > 1 && y.c > 1)
		ret.s2m += (x.sr + y.sl) * (x.sr + y.sl);
	if (!(x.sr && y.sl))
		ret.c++;
	return ret;
}
void pd(int o)
{
	if (lz[o])
		lz[ls] = lz[rs] = sl[ls] = sl[rs] = sr[ls] = sr[rs] = s2m[ls] = s2m[rs] = c[ls] = c[rs] = lz[o] = 0;
}
void build(int o, int l, int r)
{
	if (l == r)
		sl[o] = sr[o] = a[l], s2m[o] = 0, c[o] = 1;
	else
	{
		int mid = l + r >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		upd(o);
	}
}
node ask(int o, int l, int r, int L, int R)
{
	if (l >= L && r <= R)
	{
		node ret = node{ s2m[o], sl[o], sr[o], c[o] };
		lz[o] = 1, s2m[o] = sl[o] = sr[o] = c[o] = 0;
		return ret;
	}
	else
	{
		pd(o);
		int mid = l + r >> 1, f = 0;
		node ret;
		if (L <= mid)
			ret = ask(ls, l, mid, L, R), f = 1;
		if (R > mid)
		{
			if (f)
				ret = upd(ret, ask(rs, mid + 1, r, L, R));
			else
				ret = ask(rs, mid + 1, r, L, R);
		}
		upd(o);
		return ret;
	}
}
void init()
{
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	build(1, 1, n);
	for (int i = 1; i <= n; ++i)
		q[i] = make_pair(read(), read()), swap(q[i].first, q[i].second);
	while (m--)
	{
		int l = q[i].second, r = q[i].first;
		node ans = ask(1, 1, n, l, r);
		tot += ans.s2m + (ans.sl * ans.sl) * bool(ans.c > 1) + ans.sr * ans.sr;
		cout << ans.s2m + (ans.sl * ans.sl) * bool(ans.c > 1) + ans.sr * ans.sr << endl;
	}
	write(tot), putchar('\n');
}
//functions

int main()
{
	init();
	return 0;
}
//main
