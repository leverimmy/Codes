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
#define maxn 50

using namespace std;

int n, x, y;
int a[maxn][maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	x = 1, y = (n >> 1) + 1;
	for(rgi i = 1; i <= n * n; ++i)
	{
		a[x][y] = i;
		if(x == 1 && y == n)
			x++;
		else if(x == 1)
			x = n, y++;
		else if(y == n)
			x--, y = 1;
		else if(a[x - 1][y + 1])
			x++;
		else
			x--, y++;
	}
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= n; ++j)
			printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}

