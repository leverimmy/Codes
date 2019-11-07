#include <bits/stdc++.h>

using namespace std;

const int maxn = 405;
int n,m,limit,v[maxn][maxn],w[maxn][maxn];
int f[2][maxn][maxn],now,last,ans;

int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&limit);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d",&v[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d",&w[i][j]);
	now = 1,last = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(f[now],0,sizeof(f[now]));
		for (int j = 1; j <= m; j++)
			for (int k = 0; k <= limit; k++)
			{
				f[now][j][k] = f[last][j][k];
				if (j != 1)
					f[now][j][k] = max(f[now][j][k],f[now][j - 1][k]);
				if (k >= v[i][j])
				{
					f[now][j][k] = max(f[now][j][k],f[last][j][k - v[i][j]] + w[i][j]);
					if (j != 1)
						f[now][j][k] = max(f[now][j][k],f[now][j - 1][k - v[i][j]] + w[i][j]);
				}
			}
		swap(now,last);
	}
	for (int i = 0; i <= limit; i++)
		ans = max(ans,f[last][m][i]);
	printf("%d\n",ans);
	
	return 0;
}
