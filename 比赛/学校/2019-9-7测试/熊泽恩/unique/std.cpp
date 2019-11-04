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
const int N = 1e5 + 10;

int T, n, m;
int p1[N], p2[N];

struct edge
{
	int u, v, w;
} E[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^48), ch = getchar();
	return f ? -x : x;
}

int Find1(int x)
{
	return x == p1[x] ? x : p1[x] = Find1(p1[x]);
}

int Find2(int x)
{
	return x == p2[x] ? x : p2[x] = Find2(p2[x]);
}

bool cmp(struct edge a, struct edge b)
{
	return a.w < b.w;
}

int main()
{
	T = read();
	while(T--)
	{
		n = read(), m = read();
		for(rgi i = 1; i <= m; ++i)
		{
			int u = read(), v = read(), w = read();
			E[i].u = u, E[i].v = v, E[i].w = w;
		}
		sort(E + 1, E + m + 1, cmp);
		for(rgi i = 1; i <= n; ++i) p1[i] = p2[i] = i;
		memset(first, -1, sizeof(first));
		for(rgi i = 1; i <= m;)
		{
			int cur = i;
			for(rgi j = i; e[cur].wt == e[j].wt && j <= m; ++j)
			{
				if(Find2(E[j].u) != Find2(E[j].v))
				{
					if(Find(E[j].u) != Find(E[j].v))
						p[E[j].v] = E[j].u;
					else
					{
						flag = 1;
						break;
					}
				}
			}
			if(flag)
				break;
			for(;e[cur].wt == e[i].wt && i <= m; ++i)
				if(Find2(e[i].u) != Find2(e[i].v))
					p2[Find2(e[i].u)] = Find2(e[i].v);
		}
		if(flag)
			puts("NO");
 	 	else
			puts("YES");
	}
	return 0;
}

