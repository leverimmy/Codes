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
#define maxn 200
#define inf 0x3f3f3f3f

using namespace std;

int n;
int x[maxn], y[maxn];
double d1 = -inf, d2 = inf, d[maxn], e[maxn][maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

double calc(int a, int b)
{
	return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		x[i] = read(), y[i] = read();
	for(rgi i = 1; i <= n; ++i)
	{
		char cur[maxn] = {'\0'};
		scanf("%s", cur + 1);
		for(rgi j = 1; j <= n; ++j)
		{
			if(cur[j] == '1')
				e[i][j] = calc(i, j);
			else if(i != j)
				e[i][j] = inf;
			else
				e[i][j] = 0;
		}
	}
	for(rgi k = 1; k <= n; ++k)
		for(rgi i = 1; i <= n; ++i)
			for(rgi j = 1; j <= n; ++j)
				if(i != j && j != k && k != i)
					e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
		{
			if(e[i][j] != inf)
				d[i] = max(d[i], e[i][j]);
			d1 = max(d1, d[i]);
		}
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
			if(e[i][j] == inf)
				d2 = min(d2, calc(i, j) + d[i] + d[j]);
	printf("%.6lf", max(d1, d2));
	return 0;
}

