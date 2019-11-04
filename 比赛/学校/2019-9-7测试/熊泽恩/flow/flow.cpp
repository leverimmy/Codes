#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#define il inline
#define rgi register int
#define rgl register long long
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;
const int M = 1000 + 10;

int n, m, cnt, ans;
int first[N], V[N];

struct edge
{
	int to, _next, wt;
} e[M << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int cur_ans)
{

}

int main()
{
	freopen("flow.in", "r", stdin);
	freopen("flow.out", "w", stdout);
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)
		V[i] = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	s = read(), t = read();
	dfs(s, 0);
	printf("%d", ans);
	return 0;
}

