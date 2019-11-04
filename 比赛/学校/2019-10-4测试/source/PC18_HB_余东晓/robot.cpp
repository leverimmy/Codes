#include<cstdio>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
int h[50050],dv[1000010];
int f[2][1010];
signed main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	memset(f,0,sizeof(f));
	int n,ic,dc,k(0);
	scanf("%d%d%d",&n,&ic,&dc);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	for(int i=1;i<=n;i++)
		dv[h[i]]=1;
	for(int i=1;i<=1000000;i++)
		if(dv[i])
			dv[i]=++k;
	for(int i=1;i<=n;i++)
		h[i]=dv[h[i]];
	int ans(INF),u=1;
	for(int i=1;i<=k;i++)
	{
		if(i<h[1])f[u][i]=dc;
		else if(i>h[1])f[u][i]=ic;
		else f[u][i]=0;
	}
	for(int i=2,lst,mv;i<=n;i++)
	{
		lst=u;
		u^=1;
		mv=INF;
		for(int j=1;j<=k;j++)
		{
			mv=std::min(mv,f[lst][j]);
			f[u][j]=mv;
		}
		for(int j=1;j<h[i];j++)
			f[u][j]+=dc;
		for(int j=h[i]+1;j<=k;j++)
			f[u][j]+=ic;
	}
	for(int i=1;i<=k;i++)
		ans=std::min(ans,f[u][i]);
	std::reverse(h+1,h+n+1);
	memset(f,0,sizeof(f));
	u=1;
	for(int i=1;i<=k;i++)
	{
		if(i<h[1])f[u][i]=dc;
		else if(i>h[1])f[u][i]=ic;
		else f[u][i]=0;
	}
	for(int i=2,lst,mv;i<=n;i++)
	{
		lst=u;
		u^=1;
		mv=INF;
		for(int j=1;j<=k;j++)
		{
			mv=std::min(mv,f[lst][j]);
			f[u][j]=mv;
		}
		for(int j=1;j<h[i];j++)
			f[u][j]+=dc;
		for(int j=h[i]+1;j<=k;j++)
			f[u][j]+=ic;
	}
	for(int i=1;i<=k;i++)
		ans=std::min(ans,f[u][i]);
	return!printf("%d\n",ans);
}
