#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
int n,s,a[maxn][maxn];

int main()
{
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	scanf("%d%d",&n,&s);
	for (int i = 1; i <= s; i++)
		a[i][++a[i][0]] = n++;
	for (int i = 2; i <= s; i++)
		a[s][++a[s][0]] = n++;
	for (int i = s - 1; i >= 2; i--)
		a[i][++a[i][0]] = n++;
	for (int i = s; i > 1; i--)
	{
		a[1][i] = n++;
		a[1][0]++;
	}
	for (int i = 1; i <= s; i++)
	{
		for (int j = 1; j <= a[i][0]; j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	
	return 0;
}
