#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5000 + 10;
const int M = 200000 + 10;

int n, m, cnt, ans;
int first[N], p[N], len[N], belong[N];

struct edge
{
	int to, _next, wt;
} e[M << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

int Find(int x)
{
	return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int x, int y)
{
	int px = Find(x), py = Find(y);
	p[px] = py;
}

void Boruvka()
{
	while(1)
	{
		memset(len, oo, sizeof(len));
		int flag = 0;
		for(rgi x = 1; x <= n; ++x)
		{
			for(rgi i = first[x]; ~i; i = e[i]._next)
			{
				int y = e[i].to;
				if(Find(x) != Find(y))
					if(len[Find(x)] > e[i].wt)
					{
						len[Find(x)] = e[i].wt;
						belong[Find(x)] = Find(y);
					}
			}
		}
		for(rgi i = 1; i <= n; ++i)
		{
			if(len[i] != len[0] && Find(i) != Find(belong[i]))
			{
				flag = 1;
				ans += len[i];
				Union(i, belong[i]);
			}
		}
		if(!flag)
			break;
	}
}

void Out()
{
	int flag = 1;
	for(rgi i = 1; i <= n - 1; ++i)
		if(Find(i) != Find(i + 1))
		{
			flag = 0;
			break;
		}
	if(!flag)
		puts("orz");
	else
		printf("%d", ans);
}

int main()
{
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)
		p[i] = i;
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	Boruvka();
	Out();
	return 0;
}

