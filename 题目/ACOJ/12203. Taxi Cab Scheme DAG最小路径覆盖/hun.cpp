#include <iostream>
#include <cstring>
#include <cmath> 
#define rgi register int
#define il inline

using namespace std;

const int N = 4e5 + 10;
const int M = 4e5 + 10;

int T, n, cnt, ans;
int first[N], match[N], vis[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct edge
{
	int to, _next;
} e[M << 1];

struct node
{
	int hour, minute;
	int fromx, fromy;
	int tox, toy;
} a[N];

void Add_Edge(int u, int v)
{
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

bool Find(int x)
{
	for(rgi i = first[x]; ~i; i = e[i]._next)
	{
		int y = e[i].to;
		if(vis[y])
			continue;
	   	vis[y] = 1;
		if(match[y] == -1 || Find(match[y]))
		{
			match[y] = x;
			return 1;
		}
	}
	return 0;
}

void Hungary()
{
	for(rgi i = 1; i <= n; ++i)
	{
		memset(vis, 0, sizeof(vis));
		if(match[i] == -1)
			ans += Find(i);
	}
}

int main()
{
	freopen("taxi.out", "w", stdout);
	T = read();
	while(T--)
	{
		n = read();
		ans = 0;
		memset(match, -1, sizeof(match));
		memset(first, -1, sizeof(first));
		for(rgi i = 1; i <= n; ++i)
		{
			a[i].hour = read();
			a[i].minute = read();
			a[i].fromx = read();
			a[i].fromy = read();
			a[i].tox = read();
			a[i].toy = read();
		}
		for(rgi i = 1; i <= n; ++i)
		{
			for(rgi j = i + 1; j <= n; ++j)//	if(i != j)
			{
				if(a[i].hour * 60 + a[i].minute
					+ abs(a[i].fromx - a[i].tox) + abs(a[i].fromy - a[i].toy)
					+ abs(a[j].fromx - a[i].tox) + abs(a[j].fromy - a[i].toy) 
					<= a[j].hour * 60 + a[j].minute - 1)
				  Add_Edge(i, j + n);
			}
	 	}
		Hungary();
		printf("%d\n", n - ans);
	}
	return 0;
}
