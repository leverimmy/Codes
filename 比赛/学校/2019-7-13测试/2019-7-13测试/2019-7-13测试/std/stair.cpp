#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int M = 10007;

long long n;
int m, f[20], anss;

struct Matrix
{
	int a[10][10];
	Matrix()
	{
		memset(a, 0, sizeof(a));
	}
	Matrix operator*(Matrix &b)
	{
		Matrix out;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				for (int k = 0; k < m; ++k)
				{
					out.a[i][j] = (out.a[i][j] + a[i][k] * b.a[k][j]) % M;
				}
			}
		}
		return out;
	}
} mul, ans;

int main()
{
	freopen("stair.in", "r", stdin);
	freopen("stair.out", "w", stdout);
	int i, j, k;
	cin >> n >> m;
	--n;
	f[0] = 1;
	for (i = 1; i <= m; ++i)
	{
		for (j = i - m; j < i; ++j)
		{
			if (j >= 0)
			{
				f[i] += f[j];
			}
		}
	}
	for (i = 0; i < m - 1; ++i)
	{
		mul.a[i][i + 1] = 1;
	}
	for (i = 0; i < m; ++i)
	{
		mul.a[m - 1][i] = 1;
	}
	for (i = 0; i < m; ++i)
	{
		ans.a[i][i] = 1;
	}
	for (i = 60; i >= 0; --i)
	{
		ans = ans * ans;
		if (n & (1ll << i))
		{
			ans = ans * mul;
		}
	}
	for (i = 0; i < m; ++i)
	{
		anss = (anss + ans.a[0][i] * f[i + 1]) % M;
	}
	cout << anss;
	return 0;
}
