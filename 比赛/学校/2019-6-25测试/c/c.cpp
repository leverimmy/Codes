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
#define maxn 1000010

using namespace std;

int n, q, cnt, flag;
int first[maxn], dis[maxn];

struct node
{
	int to, _next, wt;
} e[maxn];

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

void Add_Edge(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void dfs(int cur)
{
	int ddd = 1, www;
	for(rgi i = first[cur]; i; i = e[i]._next)
	{
		if(ddd)
		{
			www = e[i].wt;
			ddd = 0;
			continue;
		}
		if(e[i].wt != www)
		{
			flag = 1;
			break;
		}
	}
}

int main()
{
	n = read(), q = read();
	for(rgi i = 1; i <= q; ++i)
	{
		int op = read();
		if(op == 1)
		{
			int u = read(), v = read(), w = read();
			Add_Edge(u, v, w);
			Add_Edge(v, u, w);
		}
		else if(op == 2)
		{
			int pos = read();
			flag = 0;
			dfs(pos);
			printf("%d\n", flag);
		}
	}
	return 0;
}

