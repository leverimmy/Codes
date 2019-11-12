#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define NO 400005
#define MO 400005
#define INF 0x3f3f3f3fll
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
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

int T, n, m, head[NO], cnt, c[NO], book[NO];
struct node
{
	int ne, v, ed;
}e[MO << 1];
struct E
{
	int u, v, st, ed;
}ed[MO];
//variable

bool cmp(E i, E j)
{
	return i.st < j.st;
}
inline void add(int u, int v, int ed)
{
	e[++cnt].ne = head[u];
	e[cnt].v = v;
	e[cnt].ed = ed;
	head[u] = cnt;
}
inline bool dfs(int u, int la, int t)
{
//	cout << u << ' '<< la<< ' ' << t<< endl;
	if (book[u] == t && ((c[u] == t && c[la] == t) || (c[u] < t && c[la] < t)))
		return false;
	if (book[u] == t)
		return true;
	book[u] = t, c[u] = (c[la] == t ? c[u] : t);
	for (int i = head[u]; i; i = e[i].ne)
		if (e[i].v != la && e[i].ed >= t)
			if (e[i].v == u || !dfs(e[i].v, u, t))
				return false;
	return true;
}
void init()
{
	freopen("grape.in", "r", stdin);
	freopen("grape.out", "w", stdout);
	n = read(), m = read(), T = read();
	fup (i, 1, m)
		ed[i] = E{ read(), read(), read(), read() };
	sort(ed + 1, ed + m + 1, cmp);
	register int cur = 0;
	register bool f;
	fup (t, 1, T)
	{
		while (ed[cur + 1].st < t && cur < m)
			cur++, add(ed[cur].u, ed[cur].v, ed[cur].ed), add(ed[cur].v, ed[cur].u, ed[cur].ed);
		f = true;
		fup (i, 1, n)
			if (book[i] < t)
				f &= dfs(i, 0, t);
		puts(f ? "Yes" : "No");
	}
}
//functions

int main()
{
	init();
	return 0;
}
//main
