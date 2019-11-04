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
#define MO 1000005
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

int n, m, cnt, head[NO], dis[NO], f[NO];
struct ED
{
	int from, to, cost;
}ed[MO];
struct node
{
	int next, to, cost;
}edge[MO << 1];
//variable

void add(int from, int to, int cost)
{
	edge[++cnt].next = head[from];
	edge[cnt].to = to;
	edge[cnt].cost = cost;
	head[from] = cnt;
}
void dfs(int now, int last)
{
	for (int i = head[now]; i; i = edge[i].next)
		if (edge[i].to != last)
			dis[edge[i].to] = max(dis[now], edge[i].cost), dfs(edge[i].to, now);
}
bool cmp(ED i, ED j)
{
	return i.cost < j.cost;
}
int getf(int o)
{
	return o == f[o] ? o : f[o] = getf(f[o]);
}
void init()
{
	n = read(), m = read();
	fup (i, 1, m)
		ed[i] = { read(), read(), read() };
	fup (i, 1, n)
		f[i] = i;
	sort(ed + 1, ed + m + 1, cmp);
	fup (i, 1, m)
		if (getf(ed[i].from) != getf(ed[i].to))
			f[ed[i].from] = ed[i].to, add(ed[i].from, ed[i].to, ed[i].cost), add(ed[i].to, ed[i].from, ed[i].cost);
	dfs(1, 0);
	int ans = 0;
	fup (i, 1, n)
		ans += dis[i];
	write(ans), lln;
}
//functions

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout); 
	init();
	return 0;
}
//main
