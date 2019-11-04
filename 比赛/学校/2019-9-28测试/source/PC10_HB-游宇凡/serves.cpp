#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1005;

int n, m, r[N], dis[N][N], f[N][20], ans;

int main()
{
	freopen("serves.in", "r", stdin);
	freopen("serves.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; ++i) scanf("%d", r + i);
	
	memset(dis, 0x3f, sizeof(dis));
	memset(f, 0x3f, sizeof(f));
	
	for (int i = 1; i <= n; ++i) dis[i][i] = 0;
	
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		dis[u][v] = dis[v][u] = min(dis[u][v], w);
	}
	
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (register int j = 1; j <= n; ++j)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			f[i][r[j]] = min(f[i][r[j]], dis[i][j]);
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 9; j >= 1; --j)
		{
			f[i][j] = min(f[i][j], f[i][j + 1]);
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (dis[i][j] < f[i][r[j] + 1])
			{
				++ans;
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
