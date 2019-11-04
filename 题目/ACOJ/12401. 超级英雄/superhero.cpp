#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;
const int M = 2000 + 10;

int n, m, cnt, ans;
int first[N], match[N << 2], vis[N << 2];

struct edge
{
	int to, _next;
} e[M];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

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
	for(rgi i = 0; i <= m - 1; ++i)
	{
		memset(vis, 0, sizeof(vis));
		if(match[i] == -1)
		{
			if(Find(i))
				ans++;
			else
				break;
		}
	}
}

int main()
{
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	memset(match, -1, sizeof(match));
	for(rgi i = 0; i <= m - 1; ++i)
	{
		int u = read(), v = read();
		Add_Edge(i, u + m);
		Add_Edge(i, v + m);
	}
	Hungary();
	/*for(rgi i = 0; i <= n - 1; ++i)
		cout << match[i + m] << " ";
	cout << endl;*/
	printf("%d", ans);
	return 0;
}

