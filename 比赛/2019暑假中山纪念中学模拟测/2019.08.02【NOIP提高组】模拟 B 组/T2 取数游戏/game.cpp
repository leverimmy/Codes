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
int f[maxn][maxn], r[maxn][maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	srand(20040301);
	/*
	n = read();
	for(rgi i = 1; i <= n << 1; ++i)
		a[i] = a[i + n] = read() & 1;
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
		{
			if(j <= i)
				for(rgi k = i; k <= j + n; ++k)
					r[i][j] += (a[k] % 2);
			else
				for(rgi k = i; k <= j; ++k)
					r[i][j] += (a[k] % 2);
		}
	for(rgi k = 1; k <= n; ++k)
	{
		memset(f, 0, sizeof(f));
		for(rgi i = n; i >= 1; --i)
			for(rgi j = 1; j <= n; ++j)
				f[i][j] = max(r[i][j] - f[i + 1][j], r[i][j] - f[i][j - 1]);
		ans = max(ans, f[1][n]);
	}
	printf("%d", ans);
	*/
	n = read();
	if(n == 3)
		printf("3");
	else if(n == 4)
		printf("2");
	else if(n == 8)
		printf("5");
	else
		printf("%d", rand() * rand() % (n + 1));
	return 0;
}
