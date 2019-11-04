#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define rgl register long long
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;
const int M = 1000000 + 10;

int n, m, ans, tot, all;
int p[N << 1], vis[N][N];

struct edge
{
	int u, v, w;
} e[M];

il int read()
{
    rgi x = 0, f = 0, ch;
    while(!isdigit(ch = getchar())) f |= ch == '-';
    while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int Find(int x){return x == p[x] ? x : p[x] = Find(p[x]);}
void Union(int a, int b){int pa = Find(a), pb = Find(b); if(pa != pb) p[pa] = pb, tot++;}
bool Check(int a, int b){return Find(a) == Find(b);}

void Kruskal()
{
	for(rgi i = 1; i <= all; ++i)
	{
		if(!Check(e[i].u, e[i].v))
		{
			Union(e[i].u, e[i].v);
			ans += e[i].w;
		}
		if(tot == n - 1)
			break;
	}
}

int main()
{
//	freopen("testdata (1).in", "r", stdin);
//	freopen("testdata (1).out", "w", stdout);
	while(n = read())
	{
		m = read(); all = ans = tot = 0;
		memset(vis, 0, sizeof(vis));
		for(rgi i = 1; i <= n; ++i)	p[i] = i;
		for(rgi i = 1; i <= m; ++i)
		{
			int u = read(), v = read();
			vis[u][v] = vis[v][u] = 1;
			Union(u, v);
		}
		for(rgi i = 1; i <= n; ++i)
			for(rgi j = 1; j <= n; ++j)
				if(!vis[i][j])
				{
					e[++all].u = i;
					e[all].v = j;
					e[all].w = 1;
				}
		Kruskal();
		printf("%d\n", ans);
	}
    return 0;
}

