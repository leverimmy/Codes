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
#define maxn 10010
#define maxm 100010

using namespace std;

int n, m, cnt, white, black, f = 1, ans;
int vis[maxn], first[maxn];

struct edge
{
	int to, _next;
} e[maxm << 1];

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

void Add_Edge(int u, int v)
{
	e[++cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

int dfs(int cur, int color)
{
	if(vis[cur])
	{
		if(vis[cur] == color)
			return 1;
		return 0;
	}
	vis[cur] = color;
	if(color == -1)//white
		white++;
	else if(color == 1)//black
		black++;
	int flag = 1;
	for(rgi i = first[cur]; i && flag; i = e[i]._next)
		flag = flag && dfs(e[i].to, -color);
	return flag;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	for(rgi i = 1; i <= n; ++i)
	{
		if(vis[i])
			continue;
		black = white = 0;
		if(!dfs(i, -1))
		{
			f = 0;
			break;
		}
		ans += min(white, black);
	}
	if(f)
		write(ans);
	else
		puts("Impossible");
	return 0;
}

