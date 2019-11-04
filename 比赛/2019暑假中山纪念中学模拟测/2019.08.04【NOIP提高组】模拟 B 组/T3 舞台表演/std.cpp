#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 200 + 10;

int n, m, x, y, k, ans = -oo;
char e[N][N];
int f[N][N][N];
int d[5][2] =
{
	{0, 0}, { -1, 0}, {1, 0}, {0, -1}, {0, 1}
};

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read(), m = read(), x = read(), y = read(), k = read();
	for(rgi i = 1; i <= n; ++i)
		scanf("%s", e[i] + 1);
	memset(f, -1, sizeof(f));
	f[0][x][y] = 0;
	for(rgi l = 1; l <= k; ++l)
	{
		int a = read(), b = read(), c = read();
		for(rgi i = 1; i <= n; ++i)
			for(rgi j = 1; j <= m; ++j)
			{
				if(f[l - 1][i][j] == -1)
					continue;
				f[l][i][j] = max(f[l][i][j], f[l - 1][i][j]);
				int xx = i, yy = j;
				for(rgi t = 1; t <= b - a + 1; ++t)
				{
					xx += d[c][0];
					yy += d[c][1];
					if(xx < 1 || xx > n || yy < 1 || yy > m || e[xx][yy] != '.')
						break;
					f[l][xx][yy] = max(f[l][xx][yy], f[l - 1][i][j] + t);
				}
			}
	}
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
			ans = max(ans, f[k][i][j]);
	printf("%d", ans);
	return 0;
}
