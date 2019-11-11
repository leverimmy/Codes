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
	int to,next,weight;
}a[1000010];
int head[200020],cnt(0);
void addedge(int x,int y,int w)
{
	a[cnt]=(edge){y,head[x],w};
	head[x]=cnt++;
}
int v[100010],dist[100010];
void dfs(int u,int fa)
{
	dist[u]=dist[fa]+1;
	for(int i=head[u];i!=-1;i=a[i].next)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		dfs(v,u);
	}
}
signed main()
{
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n,S(0);
	dist[0]=-1;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		addedge(x,y,w);
		addedge(y,x,w);
		S+=w<<1;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	int ans(INF);
	for(int i=1;i<=n;i++)
		if(v[i])
		{
			dfs(i,0);
			for(int p=1;p<=n;p++)
				ans=std::min(ans,S-dist[p]*2);
		}
	if(ans==INF)
		ans=-1;
	return!printf("%d\n",ans);
}
