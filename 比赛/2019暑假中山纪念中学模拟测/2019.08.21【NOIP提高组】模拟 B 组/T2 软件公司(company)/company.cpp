#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <string>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 100 + 10;
const int M = 100 + 10;

int n, m;
int f[N][M][M];
//f[i][j][k] -> the ith person, before: worked j program A, and k program B

struct People
{
	int x, y;
} p[N];

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("company.in", "r", stdin);
	freopen("company.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		p[i].x = read();
		p[i].y = read();
	}
	for(rgi i = 0; i <= m; ++i)
		for(rgi j = 0; j <= m; ++j)
			f[0][i][j] = oo;
	f[0][0][0] = 0;
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 0; j <= m; ++j)
			for(rgi k = 0; k <= m; ++k)
			{
				f[i][j][k] = oo;
				for(rgi l = j; l >= 0; --l)
				{
					for(rgi o = k; o >= 0; --o)
					{
						f[i][j][k] = min(f[i][j][k], max(f[i - 1][l][o], p[i].x * (j - l) + p[i].y * (k - o)));
					}
				}
//				cout << i << " " << j << " " << k << " " << f[i][j][k] << endl;
			}
	printf("%d", f[n][m][m]);
	return 0;
}

