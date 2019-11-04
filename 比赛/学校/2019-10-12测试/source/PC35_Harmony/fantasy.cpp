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
#define NO 500005
#define eps 1e-9
#define P 998244353ll
#define fup(i, x, y) for (register int i = x; i <= y; ++i)
#define fdn(i, x, y) for (register int i = x; i >= y; --i)
#define mp(x, y) make_pair(x, y)
#define fi first
#define se second
#define ls o << 1
#define  rs o << 1 | 1
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

int n, m, hn[NO], d[NO], in[NO], b[NO], c[NO], nex[NO], cnt, head[NO], s, t, ans, a[NO], out[NO];
queue<int> q;
struct node
{
	int next, to, fl;
}edge[NO << 3];
//variable

void add(int from, int to, int fl)
{
	edge[++cnt].next = head[from];
	edge[cnt].to = to;
	edge[cnt].fl = fl;
	head[from] = cnt;
}
bool bfs(int s, int t)
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
			nex[now] = edge[i].to;
			MIN -= nf, ff += nf, edge[i].fl -= nf, edge[i ^ 1].fl += nf;
			if (!MIN)
				return ff;
		}
	}
	return ff;
}
void init()
{
	freopen("fantasy.in", "r", stdin);
	freopen("fantasy.out", "w", stdout);
	n = read(), m = read(), s = 2 * n + 1, t = s + 1, cnt = 1;
	fup (i, 1, m)
	{
		int x = read(), y = read(), z = read();
		in[a[i] = x]++, b[i] = y, c[i] = z, add(s, x, 1), add(x, s, 0);
		add(x, y + n, 1), add(y + n, x, 0), add(x, z + n, 1), add(z + n, x, 0);
	}
	fup (i, 1, n)
		add(i + n, t, in[i]), add(t, i + n, 0);
	ans = 0;
	while (bfs(s, t))
		ans += dfs(s, INF);
	fup (i, 1, m)
		if (nex[a[i]] == b[i] + n)
			putchar('0'), out[b[i]]++;
		else
			putchar('1'), out[c[i]]++;
	lln;
}
//functions

int main()
{
	init();
	return 0;
}
//main
