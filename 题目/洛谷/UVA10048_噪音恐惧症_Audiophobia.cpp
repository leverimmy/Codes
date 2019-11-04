#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 110
#define inf 0x3f3f3f3f

using namespace std;

int n, m, q, kase;
int e[maxn][maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)	putchar('-'), x = -x;
	if(x > 9)	write(x / 10);
	putchar(x % 10 + 48);
}

int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	while(scanf("%d %d %d", &n, &m, &q) == 3 && n)
	{
		if(kase)
			putchar('\n');
		printf("Case #%d\n", ++kase);
		for(rgi i = 1; i <= n; i++)
		{
			for(rgi j = 1; j <= n; ++j)
				e[i][j] = inf;
			e[i][i] = 0;
		}
		for(rgi i = 1; i <= m; ++i)
		{
			int u = read(), v = read(), w = read();
			e[u][v] = e[v][u] = w;
		}
		for(rgi k = 1; k <= n; ++k)
			for(rgi i = 1; i <= n; ++i)
				for(rgi j = 1; j <= n; ++j)
					if(e[i][k] < inf && e[k][j] < inf)
						e[i][j] = min(e[i][j], max(e[i][k], e[k][j]));
		for(rgi i = 1; i <= q; ++i)
		{
			int u = read(), v = read();
			if(e[u][v] >= inf)
				puts("no path");
			else
				write(e[u][v]), putchar('\n');
		}
	}
	return 0;
}

