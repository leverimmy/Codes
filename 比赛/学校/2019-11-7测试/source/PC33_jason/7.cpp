#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int n;
int a[21][21];
int p[21];
void dfs(int x,int num)
{
	if(n-x+1+num<(n+1)/2)return;
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
			if(p[i]==1)
				for(int j=1;j<=n;j++)
				{
					if(a[i][j]!=p[j])
						return;
				}
		for(int i=1;i<=n;i++)
			if(p[i])
				printf("%d ",i);
		exit(0);
	}
	dfs(x+1,num);
	p[x]=1;
	dfs(x+1,num+1);
	p[x]=0;
}
signed main()
{
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	dfs(1,0);
	return 0;
}