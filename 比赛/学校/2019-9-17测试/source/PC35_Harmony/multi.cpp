#pragma GCC optimize (2)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#define INF 0x3f3f3f3f
#define MO 200005
#define NO 200005
#define eps 1e-9
#define P 998244353ll
#define fup(i, x, y) for (int i = x; i <= y; i++)
#define fdn(i, x, y) for (int i = x; i >= y; i--)
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define lln putchar('\n')
#define blk putchar(' ')
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
typedef pair<db, pair<int, int> > pfi;
inline ll read()
{
	char ch = ' ', last;
	ll ans = 0;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ans = ans * 10 + int(ch - '0'), ch = getchar();
	if (last == '-')
		return -ans;
	return ans;
}
void write(ll x)
{
	if (x < 0)
		putchar('-'), x = -x;
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}
//head

int n, m, p[NO], cnt, head[NO], s, t, ans[NO], tot;
db dis[NO];
bool book[NO];
struct node
{
	int next, to;
	db cost;
}edge[MO << 1];
priority_queue<pfi, vector<pfi>, greater<pfi> > q;
//variable

void add(int from, int to, db cost)
{
	edge[++cnt].next = head[from];
	edge[cnt].to = to;
	edge[cnt].cost = cost;
	head[from] = cnt;
}
void init()
{
	freopen("multi.in", "r", stdin);
	freopen("multi.out", "w", stdout);
	n = read(), m = read();
	fup (i, 1, m)
	{
		int x = read(), y = read(), z = read();
		add(x, y, log2(z));
		add(y, x, log2(z));
	}
	s = read(), t = read();
	fup (i, 1, n)
		dis[i] = INF;
	dis[s] = 0, q.push(mp(0.0, mp(s, 0)));
	while (!q.empty())
	{
		pii cur = q.top().se;
		q.pop();
		if (book[cur.fi])
			continue;
		book[cur.fi] = true;
		p[cur.fi] = cur.se;
		for (int i = head[cur.fi]; i; i = edge[i].next)
			if (dis[edge[i].to] + eps > dis[cur.fi] + edge[i].cost)
				dis[edge[i].to] = dis[cur.fi] + edge[i].cost, q.push(mp(dis[edge[i].to], mp(edge[i].to, cur.fi)));
	}
	int cur = t;
	while (cur)
		ans[++tot] = cur, cur = p[cur];
	fdn (i, tot, 1)
		write(ans[i]), blk;
	lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main

