#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int a[11];
vector<int>v;
int cnt=0;
int ans[100001][11];
void dfs(int u,int x)
{
	if(u==n+1)
	{
		vector<int>rem;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			rem.push_back(a[i]+a[j]);
		}
		sort(rem.begin(),rem.end());
		for(int i=0;i<n*(n-1)/2;i++)
			if(rem[i]!=v[i])
				return;
		++cnt;
		for(int i=1;i<=n;i++)
			ans[cnt][i]=a[i];
		return;
	}
	for(int i=x;i<=10;i++)
	{
		a[u]=i;
		dfs(u+1,i);
	}
}
signed main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n*(n-1)/2;i++)
	{
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	dfs(1,0);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
	return 0;
}
/*
4
3 5 4 7 6 5
*/