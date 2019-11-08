#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <string> 
#include <queue>
#include <cmath>
#include <stack>
#include <algorithm>
#define INF 0x3f3f3f3f
#define NO 100005
#define MO 1000005
#define fi first
#define se second
#define lln putchar('\n')
#define blk putchar(' ')
#define fup(i, x, y) for(register int i = x; i <= y; ++i)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef double db;
using namespace std;
typedef pair<int, int> pii;
ll read()
{
	ll ret = 0;
	char ch = ' ', last;
	while (ch < '0' || ch > '9')
		last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9')
		ret = (ret << 3) + (ret << 1) + ch - '0', ch = getchar();
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
// head

int n, m, cnt, head[NO], t, dfn[NO], low[NO], ans, tot;
bool stk[NO];
stack<int> s;
struct node
{
	int v, ne;
}e[MO << 1];
// variable

void add(int u, int v)
{
	e[++cnt].ne = head[u];
	e[cnt].v = v;
	head[u] = cnt;
}
void tar(int u)
{
	dfn[u] = low[u] = ++t, s.push(u), stk[u] = true;
	for (int i = head[u]; i; i = e[i].ne)
			if (!dfn[e[i].v])
				tar(e[i].v), low[u] = min(low[u], low[e[i].v]);
			else if (stk[e[i].v])
				low[u] = min(low[u], dfn[e[i].v]);
//	cout << u << ',' << dfn[u] << ',' << low[u] << endl;
	if (dfn[u] == low[u])
	{
		ans++;
		int cur = s.top();
		while (s.top() != u)
			stk[cur] = false, s.pop(), cur = s.top();
	}
}
void init()
{
	memset(head, 0, sizeof(int) * (n + 1));
	memset(dfn, 0, sizeof(int) * (n + 1));
	if (scanf("%lld", &n) == -1)
		exit(0);
	m = read(), ans = cnt = t = 0;
	fup (i, 1, m)
	{
		int x = read(), y = read();
		add(x, y);
	}
	fup (i, 1, n)
		if (!dfn[i])
			tar(i);
	write(ans), lln;
}
//functions

int main()
{
	freopen("10.in", "r", stdin);
	freopen("10.out", "w", stdout);
	while (1)
		init();
	return 0;
}
//main
