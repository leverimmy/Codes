#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define NO 200005
#define INF 0x3f3f3f3fll
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define ls o << 1
#define rs o << 1 | 1
#define rt 1, 1, n + 1
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define fdn(i, x, y) for (register int i = x; i >= y; --i)
#define lln putchar('\n')
#define blk putchar(' ')
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll, ll> pii;
typedef pair<ll, pair<pii, pii> > piiiii;
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

ll Min[NO << 2], p[NO << 2], n, k, pre[NO];
priority_queue<piiiii> q;
//variable

void build(int o, int l, int r)
{
	if (l == r)
		Min[o] = pre[l - 1], p[o] = l - 1;
	else
	{
		int mid = l + r >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		if (Min[ls] > Min[rs])
			Min[o] = Min[rs], p[o] = p[rs];
		else
			Min[o] = Min[ls], p[o] = p[ls];
	}
}
int ask(int o, int l, int r, int L, int R)
{
	if (l >= L && r <= R)
		return p[o];
	else
	{
		int mid = l + r >> 1, cur = 0, ret = 0;
		ll MIN = INF * INF;
		if (L <= mid)
			ret = ask(ls, l, mid, L, R), MIN = pre[ret];
		if (R > mid)
			cur = ask(rs, mid + 1, r, L, R), (MIN > pre[cur] ? (MIN = pre[cur], ret = cur) : ret);
		return ret;
	}
}
inline piiiii get(register int r, register int lll, register int llr)
{
	register int pn = ask(rt, lll, llr);
	return mp(pre[r] - pre[pn], mp(mp(pn + 1, r), mp(lll, llr)));
}
void init()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n = read(), k = read();
	fup (i, 1, n)
		pre[i] = pre[i - 1] + read();
	build(rt);
	fup (i, 1, n)
		q.push(get(i, 1, i));
	while (!q.empty() && --k)
	{
		piiiii now = q.top();
//		cout << now.fi << ',' << now.se.fi.fi << ' ' << now.se.fi.se << ',' << now.se.se.fi << ' ' << now.se.se.se << endl;
		q.pop();
		if (now.se.fi.fi - 1 >= now.se.se.fi)
			q.push(get(now.se.fi.se, now.se.se.fi, now.se.fi.fi - 1));
		if (now.se.fi.fi + 1 <= now.se.se.se)
			q.push(get(now.se.fi.se, now.se.fi.fi + 1, now.se.se.se));
	}
	write(q.top().fi), lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main
