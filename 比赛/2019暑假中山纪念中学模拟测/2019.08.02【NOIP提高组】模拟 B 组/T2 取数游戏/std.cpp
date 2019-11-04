#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cctype>
#define ll long long
#define il inline
#define rgi register int
#define maxn 110

using namespace std;

int n, ans;
int a[maxn << 1];
int f[maxn << 1][maxn << 1], r[maxn << 1][maxn << 1];

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
	for(rgi i = 1; i <= n; ++i)
		a[i] = a[i + n] = read();
	for(rgi i = 1; i <= n << 1; ++i)
		for(rgi j = 1; j <= n << 1; ++j)
			for(rgi k = i; k <= j; ++k)
				r[i][j] += a[k] & 1;
	for(rgi k = 1; k <= n; ++k)
	{
		memset(f, 0, sizeof(f));
		for(rgi i = 1; i <= n << 1; ++i)
			f[i][i] = a[i] & 1;
		for(rgi i = k + n - 1; i >= k + 1; i--)
			for(rgi j = i + 1; j <= k + n - 1; ++j)
				f[i][j] = max(r[i][j] - f[i + 1][j], r[i][j] - f[i][j - 1]);
		if(r[k + 1][k + n] - f[k + 1][k + n - 1] > f[k + 1][k + n - 1])
			ans++;
	}
	printf("%d", ans);
	return 0;
}

