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
#define maxn 210
#define inf 0x3f3f3f3f

using namespace std;

int n, m, q, k;
int time[maxn], e[maxn][maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	for(rgi i = 0; i <= n - 1; ++i)
		for(rgi j = 0; j <= n - 1; ++j)
			e[i][j] = inf;
	for(rgi i = 0; i <= n - 1; ++i)
		e[i][i] = 0;
}

int main()
{
//	freopen("testdata.in", "r", stdin);
//	freopen("ans.out", "w", stdout);
	n = read(), m = read();
	init();
	for(rgi i = 0; i <= n - 1; ++i)
		time[i] = read();
	for(rgi i = 0; i <= m - 1; ++i)
	{
		int u = read(), v = read(), w = read();
		e[u][v] = e[v][u] = w;
	}
	q = read();
	for(rgi i = 0; i <= q - 1; ++i)
	{
		int s = read(), t = read(), day = read();
		while(time[k] <= day && k <= n - 1)
		{
			for(rgi i = 0; i <= n - 1; ++i)
				for(rgi j = 0; j <= n - 1; ++j)
					e[i][j] = min(e[i][j] , e[i][k] + e[k][j]);
			k++;
		}
		if(e[s][t] == inf || time[s] > day || time[t] > day)
			puts("-1");
		else
			printf("%d\n", e[s][t]);
	}
	return 0;
}

