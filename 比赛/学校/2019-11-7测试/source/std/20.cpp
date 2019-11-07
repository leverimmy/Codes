#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;
int k,use[20],a[10][10],top;

void solve()
{
	if (a[1][1] + a[2][2] + a[3][3] + a[4][4] != 34)
		return;
	if (a[1][4] + a[2][3] + a[3][2] + a[4][1] != 34)
		return;
	++top;
	if (top == k)
	{
		for (int i = 1; i <= 4; i++)
			for (int j = 1; j <= 4; j++)
			{
				if (j == 4)
					printf("%d\n",a[i][j]);
				else
					printf("%d ",a[i][j]);
			}
		exit(0);
	}
}

void dfs(int x,int y)
{
	if (x == 5)
	{
		solve();
		return;
	}
	if (y == 5)
	{
		if (a[x][1] + a[x][2] + a[x][3] + a[x][4] != 34)
			return;
		dfs(x + 1,1);
		return;
	}
	for (int i = 1; i <= 16; i++)
		if (!use[i])
		{
			if (x == 4 && a[1][y] + a[2][y] + a[3][y] + i != 34)
				continue;
			use[i] = 1;
			a[x][y] = i;
			dfs(x,y + 1);
			use[i] = 0;
			a[x][y] = 0; 
		}
}

int main()
{
	freopen("20.in","r",stdin);
	freopen("20.out","w",stdout);
	scanf("%d",&k);
	dfs(1,1);
	
	return 0;
}
