#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 100010

using namespace std;

int n, siz;
int _next[maxn], vis[maxn], ans[maxn], dis[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

void dfs(int cur, int step)
{
	//if(vis[cur])
	//	return;
	vis[cur] = 1;
	dis[cur] = step;
	if(ans[_next[cur]])
		ans[cur] = ans[_next[cur]] + 1;
	else if(dis[_next[cur]])
	{
		ans[cur] = dis[cur] - dis[_next[cur]] + 1;
		int to = _next[cur];
		while(to != cur)
		{
			ans[to] = ans[cur];
			to = _next[to];
		}
	}
	else
	{
		dfs(_next[cur], step + 1);
		if(!ans[cur])
			ans[cur] = ans[_next[cur]] + 1;
	}
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		_next[i] = read();
	for(rgi i = 1; i <= n; ++i)
		if(!vis[i])
			dfs(i, 0);
	for(rgi i = 1; i <= n; ++i)
		write(ans[i]), putchar('\n');
	return 0;
}

