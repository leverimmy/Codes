#include <iostream>
#include <cstdio>

#define MAXN 100005

using namespace std;

int n, m;
int a[MAXN], f[MAXN][305];

void read(int &x)
{
	x = 0;
	char c = getchar();
    while (!isdigit(c))
		c = getchar();
    while (isdigit(c))
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
}
int main()
{
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 0; i <= 300; i++)
	{
		for (int j = n; j >= 1; j--)
		{
			if (j + a[j] + i > n)
				f[j][i] = 1;
			else f[j][i] = f[j + a[j] + i][i] + 1;
		}
	}
	read(m);
	for (int i = 1; i <= m; i++)
	{
		int p, k;
		read(p);
		read(k);
		if (k > 300)
		{
			int ans = 0;
			while (p < n)
			{
				p += a[p] + k;
				ans++;
			}
			printf("%d\n", ans);
		}
		else printf("%d\n", f[p][k]);
	}
	return 0;
}
