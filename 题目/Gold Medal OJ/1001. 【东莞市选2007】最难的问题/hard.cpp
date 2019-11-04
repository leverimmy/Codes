#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define maxn 210

using namespace std;

const int inf = 0x3f3f3f3f;

int n, m;
int e[maxn][maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= n; ++j)
			e[i][j] = inf;
		e[i][i] = 0;
	}
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read(), w = read();
		e[u][v] = e[v][u] = min(e[u][v], w);
	}
	for(rgi k = 1; k <= n; ++k)
		for(rgi i = 1; i <= n; ++i)
			for(rgi j = 1; j <= n; ++j)
			{
				if(i == j || j == k || k == i)
					continue;
				e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
			}
	if(e[1][n] == inf)
		puts("-1");
	else
		printf("%d", e[1][n]);
	return 0;
}

