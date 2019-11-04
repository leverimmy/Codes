#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 30

using namespace std;

int n, m, x, y;
int a[maxn][maxn];
ll f[maxn][maxn];

il ll read()
{
	register ll  x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(ll x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

int main()
{
	f[0][0] = 1;
	n = read(), m = read();
	x = read(), y = read();
	a[x][y] = 1;
	if(x >= 2)
		a[x - 2][y + 1] = 1;
	if(x >= 2 && y >= 1)
		a[x - 2][y - 1] = 1;
	if(x >= 1)
		a[x - 1][y + 2] = 1;
	if(x >= 1 && y >= 2)
		a[x - 1][y - 2] = 1;
	a[x + 2][y + 1] = 1;
	if(y >= 1)
		a[x + 2][y - 1] = 1;
	a[x + 1][y + 2] = 1;
	if(y >= 2)
		a[x + 1][y - 2] = 1;
	for(rgi i = 1; i <= n; ++i)
	{
		if(a[i][0])
			break;
		else
			f[i][0] = f[i - 1][0];
	}
	for(rgi i = 1; i <= m; ++i)
	{
		if(a[0][i])
			break;
		else
			f[0][i] = f[0][i - 1];
	}
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
		{
			if(a[i][j] == 1)
				continue;
			else
				f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	write(f[n][m]);
	return 0;
}

