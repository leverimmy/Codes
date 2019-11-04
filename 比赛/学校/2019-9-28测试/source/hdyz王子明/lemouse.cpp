#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn = 1005;

int n, m;

int a[maxn][maxn], f[maxn][maxn][2];

int read(void)
{
	int s = 0, w = 1;
	char ch = getchar();
	for(; ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') w = -1;
	for(; ch <= '9' && ch >= '0'; ch = getchar()) s = s * 10 + ch - '0';
	return s * w;
}

int main()
{
	freopen("lemouse.in", "r", stdin);
	freopen("lemouse.out", "w", stdout);
	n = read(); m = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) a[i][j] = read();
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(i == 1 && j == 1) 
			{
				f[i][j][0] = f[i][j][1] = a[1][1] + a[1][2] + a[2][1];
				continue;
			}
			else {
				f[i][j][1] = min(f[i - 1][j][1] + a[i][j - 1] + a[i][j + 1] + a[i + 1][j], f[i - 1][j][0] + a[i][j + 1] + a[i + 1][j]);
				f[i][j][0] = min(f[i][j - 1][0] + a[i - 1][j] + a[i][j + 1] + a[i + 1][j], f[i][j - 1][1] + a[i][j + 1] + a[i + 1][j]);
			}
		}
	}
	cout << min(f[n][m][1], f[n][m][0]) << '\n';
	return 0;
}
