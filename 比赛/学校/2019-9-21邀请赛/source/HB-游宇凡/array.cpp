#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

int read()
{
	int out = 0;
	char c;
	while (!isdigit(c = getchar()));
	for (; isdigit(c); c = getchar()) out = out * 10 + c - '0';
	return out;
}

const int N = 100010;
const int B = 300;

int n, m, a[N], f[B + 5][N];

int main()
{
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	
	n = read();
	
	for (int i = 1; i <= n; ++i) a[i] = read();
	
	for (int i = 0; i <= B; ++i)
	{
		for (int j = n; j >= 1; --j)
		{
			if (j + a[j] + i > n) f[i][j] = 1;
			else f[i][j] = f[i][j + a[j] + i] + 1;
		}
	}
	
	m = read();
	
	for (int i = 1; i <= m; ++i)
	{
		int p = read();
		int k = read();
		if (k <= B) printf("%d\n", f[k][p]);
		else
		{
			int ans = 0;
			while (p <= n)
			{
				++ans;
				p += a[p] + k;
			}
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
