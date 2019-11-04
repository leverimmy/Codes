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

int n, s, t;
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
	n = read(), s = read(), t = read();
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
			e[i][j] = inf;
	for(rgi i = 1; i <= n; ++i)
		e[i][i] = 0;
	for(rgi i = 1; i <= n; ++i)
	{
		int k = read();
		for(rgi j = 1; j <= k; ++j)
		{
			int v = read();
			if(j == 1)
				e[i][v] = 0;
			else
				e[i][v] = 1;
		}
	}
	for(rgi k = 1; k <= n; ++k)
		for(rgi i = 1; i <= n; ++i)
			for(rgi j = 1; j <= n; ++j)
				if(i != j && j != k && k != i)
					e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
	if(e[s][t] == inf)
		puts("-1");
	else
		printf("%d", e[s][t]);
	return 0;
}

