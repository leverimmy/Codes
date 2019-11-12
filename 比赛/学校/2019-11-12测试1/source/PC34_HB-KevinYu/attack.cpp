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
struct edge
{
	int to,next;
}a[200020];
int head[100010],cnt(0);
void addedge(int x,int y)
{
	a[cnt]=(edge){y,head[x]};
	head[x]=cnt++;
}
int dist[100010],dep[100010],p[100010],vis[100010],val[100010];
void dfs(int u,int fa,int col)
{
	vis[u]=col;
	p[u]=fa;
	dist[u]=dist[fa]+val[u];
	dep[u]=dep[fa]+1;
	for(int i=head[u];i!=-1;i=a[i].next)
	{
		int v=a[i].to;
		if(v==fa||vis[u])
			continue;
		dfs(v,u,col);
	}
}
signed main()
{
	freopen("attack.in","r",stdin);
	freopen("attack.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	dfs(1,0,0);
	int s=0,t=0;
	for(int i=1;i<=n;i++)
		if(dist[i]>dist[s])
			s=i;
	memset(dist,0,sizeof(dist));
	dfs(s,0,0);
	for(int i=1;i<=n;i++)
		if(dist[i]>dist[t])
			t=i;
	int ans=dist[t];
	memset(dist,0,sizeof(dist));
	memset(vis,0,sizeof(vis));
	while(dep[t]!=dep[s])
	{
		vis[t]=INF;
		t=p[t];
	}
	vis[s]=INF;
	int tot(0),uans(0);
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			s=t=0;
			dfs(i,0,++tot);
			for(int p=1;p<=n;p++)
				if(dist[p]>dist[s]&&vis[i]==vis[p])
					s=p;
			dfs(s,0,tot);
			for(int p=1;p<=n;p++)
				if(vis[i]==vis[p])
					uans=std::max(uans,dist[p]);
		}
	return!printf("%d\n",uans+ans);
}
