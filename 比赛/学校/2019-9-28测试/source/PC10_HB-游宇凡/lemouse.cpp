#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

int read()
{
	int out = 0;
	char c;
	while (!isdigit(c = getchar()));
	for (; isdigit(c); c = getchar()) out = out * 10 + c - '0';
	return out;
}

const int N = 1010;

int n, m, a[N][N], f[2][N][N];

int main()
{
	freopen("lemouse.in", "r", stdin);
	freopen("lemouse.out", "w", stdout);
	
	n = read();
	m = read();
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			a[i][j] = read();
		}
	}
	
	memset(f, 0x3f, sizeof(f));
	
	for (int i = n; i >= 1; --i)
	{
		for (int j = m; j >= 1; --j)
		{
			if (i == n && j == m)
			{
				f[0][i][j] = f[1][i][j] = 0;
				continue;
			}
			f[0][i][j] = min(f[0][i + 1][j] + a[i + 1][j - 1] + a[i + 1][j + 1] + a[i + 2][j],
							 f[1][i][j + 1] + a[i][j + 2] + a[i + 1][j + 1]);
			f[1][i][j] = min(f[0][i + 1][j] + a[i + 2][j] + a[i + 1][j + 1],
							 f[1][i][j + 1] + a[i - 1][j + 1] + a[i + 1][j + 1] + a[i][j + 2]);
		}
	}
	
	cout << f[0][1][1] + a[1][1] + a[1][2] + a[2][1];
	
	return 0;
}
