#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 50 + 10;
const int M = 50 + 10;
const int MAXT = 2500 + 10;

int n, m, T;
int c[M], f[M][M][2], g[MAXT];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read(), m = read(), T = read();
	/*
	f[i][j][k] -> 对于每一行来说，第i格，这一行刷了j次，颜色为k，最大收益

	1.沿着上一个格子刷下去
		f[i][j][c[i]] = f[i][j][c[i]] + 1
		f[i][j][!c[i]] = f[i][j][!c[i]]
	2.重开一次刷下去：
		2.1刷同色
			f[i][j][c[i]] = max(f[i][j][c[i]], max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + 1)
		2.2刷异色
			f[i][j][!c[i]] = max(f[i][j][!c[i]], max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]))

	g[i] -> 对于每一行来说，刷了i次能达到的最大收益

	g[i] = max(g[i], g[i - j] + max(f[n][i][0], f[n][i][1]))
	*/
	for(rgi l = 1; l <= n; ++l)
	{
		for(rgi i = 1; i <= m; ++i)
			scanf("%1d", &c[i]);
		memset(f, 0, sizeof(f));
		for(rgi i = 1; i <= m; ++i)
		{
			for(rgi j = 1; j <= i; ++j)
			{
				f[i][j][c[i]] = f[i - 1][j][c[i]] + 1;
				f[i][j][!c[i]] = f[i - 1][j][!c[i]];
				f[i][j][c[i]] = max(f[i][j][c[i]], max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]) + 1);
				f[i][j][!c[i]] = max(f[i][j][!c[i]], max(f[i - 1][j - 1][0], f[i - 1][j - 1][1]));
			}
		}
		for(rgi i = T; i >= 0; --i)
			for(rgi j = 1; j <= min(i, m); ++j)
				g[i] = max(g[i], g[i - j] + max(f[m][j][0], f[m][j][1]));
	}
	printf("%d", g[T]);
	return 0;
}

