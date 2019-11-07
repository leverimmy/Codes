#include <bits/stdc++.h>

using namespace std;

const int maxn = 40;
int n,a[maxn][maxn],choose[maxn];

void solve()
{
	for (int i = 1; i <= n; i++)
		if (choose[i])
			for (int j = 1; j <= n; j++)
				if (i != j && choose[j] != a[i][j])
					return;
	for (int i = 1; i <= n; i++)
		if (choose[i])
			printf("%d ",i);
	exit(0);
}

void dfs(int dep)
{
	if (dep == n + 1)
	{
		solve();
		return;
	}
	choose[dep] = 1;
	dfs(dep + 1);
	choose[dep] = 0;
	dfs(dep + 1);
}

int main()
{
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d",&a[i][j]);
	dfs(1);
	
	return 0;
}
