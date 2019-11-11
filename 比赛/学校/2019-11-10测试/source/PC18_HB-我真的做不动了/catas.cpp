#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cassert>
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
int ans[100010],ind[100010];
/*void dfs(int u,int fa)
{
	size[u]=1;
	for(int i=head[u];i!=-1;i=a[i].next)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		dfs(v,u);
		size[u]+=size[v];
		if(dge[v]==1)
			ans[u]+=size[v];
		else
			
	}
}*/
bool vis[100010];
void bfs(int s,int p)
{
	memset(vis,0,sizeof(vis));
	std::queue<int>q;
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=1;
		for(int i=head[u];i!=-1;i=a[i].next)
		{
			int v=a[i].to;
			if(vis[v]||v==p)
				continue;
			q.push(v);
		}
	}
}
signed main()
{
	freopen("catas.in","r",stdin);
	freopen("catas.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int u;
		while(~scanf("%d",&u)&&u)
		{
			addedge(u,i);
			ind[i]++;
		}
	}
	int s=n+1;
	for(int i=1;i<=n;i++)
		if(!ind[i])
			addedge(s,i);
	for(int i=1;i<=n;i++)
	{
		int ans(-1);
		bfs(s,i);
		for(int p=1;p<=n;p++)
			ans+=!(vis[p]);
		printf("%d\n",ans);
	}
	return 0;
}
