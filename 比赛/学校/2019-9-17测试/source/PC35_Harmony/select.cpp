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
#define NO 1005
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

int s, t, n, m, p[NO], v[NO], cnt, head[NO], d[NO], hn[NO], ans;
bool a[NO][NO];
queue<int> q;
struct node
{
	int next, to, fl;
}edge[MO << 1];
//variable

bool bfs()
{
	memset(d, -1, sizeof(int) * (cnt + 1));
	for (int i = 1; i <= cnt; i++)
		hn[i] = head[i];
	d[s] = 0, q.push(s); 
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = head[now]; i; i = edge[i].next)
			if (edge[i].fl && d[edge[i].to] == -1)
				d[edge[i].to] = d[now] + 1, q.push(edge[i].to);
	}
	return ~d[t];
}
int dfs(int now, int MIN)
{
	if (!MIN || now == t)
		return MIN;
	int ff = 0;
	for (int i = hn[now]; i; i = edge[i].next)
	{
		hn[now] = i;
		if (d[edge[i].to] == d[now] + 1 && edge[i].fl)
		{
			int nf = dfs(edge[i].to, min(MIN, edge[i].fl));
			MIN -= nf, ff += nf, edge[i].fl -= nf, edge[i ^ 1].fl += nf;
			if (!MIN)
				return ff;
		}
	}
	return ff;
}
void add(int from, int to, int fl)
{
	edge[++cnt].next = head[from];
	edge[cnt].to = to;
	edge[cnt].fl = fl;
	head[from] = cnt;
}
void init()
{
	freopen("select.in", "r", stdin);
	freopen("select.out", "w", stdout);
	n = read(), m = read(), cnt = 1, s = 2 * n + 1, t = 2 * n + 2;
	fup (i, 1, n)
		v[i] = read(), p[i] = read(), add(i, t, p[i] - v[i]), add(t, i, 0), cout << p[i] - v[i] << endl;
	fup (i, 1, m)
		a[read()][read()] = true;
	fup (i, 1, n)
		fup (j, 1, n)
			if (a[i][j] || i == j)
				add(i + n, j, INF), add(j, i + n, 0);
	fup (i, 1, n)
		add(s, i + n, -p[i]), add(i + n, s, 0);
	int cur = -INF;
	while (bfs())
		cur = max(cur, dfs(s, INF)), cout << cur << endl;
	fup (i, 1, n)
		ans += v[i] - p[i];
//	cout << ans << ',' << cur << endl;
	write(ans - cur), lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main

