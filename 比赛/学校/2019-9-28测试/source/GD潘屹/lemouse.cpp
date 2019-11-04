#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m;
int d[1005][1005], f[1005][1005][2];

int main()
{
	freopen("lemouse.in", "r", stdin);
	freopen("lemouse.out", "w", stdout);
	memset(f, 0x7f, sizeof(f));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &d[i][j]);
	f[1][1][0] = f[1][1][1] = d[1][1] + d[2][1] + d[1][2];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && j == 1) continue;
			f[i][j][0] = f[i][j][1] = d[i + 1][j] + d[i][j + 1];
			f[i][j][0] += min(f[i][j - 1][1], f[i][j - 1][0] + d[i - 1][j]);
			f[i][j][1] += min(f[i - 1][j][0], f[i - 1][j][1] + d[i][j - 1]);
		}
	printf("%d", min(f[n][m][0], f[n][m][1]));
	return 0;
}
