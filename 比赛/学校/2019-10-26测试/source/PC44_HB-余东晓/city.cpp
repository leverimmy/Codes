#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define maxv 10
int n,v[110],num[110],sum[110],tot(0);
std::vector<int>ans[110];
bool judge()
{
	int vn[110];
	memset(vn,0,sizeof(vn));
	int u(0);
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
			vn[++u]=num[i]+num[j];
	std::sort(vn+1,vn+u+1);
	for(int i=1;i<=u;i++)
		if(vn[i]!=v[i])
			return 0;
	return 1;
}
void dfs(int x)
{
	if(x==n)
	{
		if(judge())
			for(int i=1;i<=n;i++)
				ans[++tot].push_back(num[i]);
		return;
	}
	for(int i=1;i<=maxv;i++)
	{
		num[x+1]=i;
		dfs(x+1);
	}
}
signed main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n*(n-1)/2;i++)
		scanf("%d",&v[i]);
	std::sort(v+1,v+n*(n-1)/2+1);
	dfs(0);
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
	{
		for(int p=0;p<n;p++)
			printf("%d ",ans[i][p]);
		puts("");
	}
	return 0;
}
