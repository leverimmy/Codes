#include<cstdio>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<cstring>
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
#define INF 0x7f7f7f7f
struct edge
{
	int to,next,weight;
}a[1000010];
int head[100010],cnt(0);
void addedge(int x,int y,int w)
{
	a[cnt]=(edge){y,head[x],w};
	head[x]=cnt++;
}
int dist[100010],vis[100010];
bool spfa(int s,int n)
{
	vis[s]=1;
	std::queue<int>q;
	q.push(s);
	dist[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i!=-1;i=a[i].next)
		{
			int v=a[i].to;
			if(dist[v]==INF)
			{
				dist[v]=dist[u]^a[i].weight;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
			else if(dist[v]!=(dist[u]^a[i].weight))
			{
				memset(vis,0,sizeof(int)*(n+2));
				return 0;
			}
		}
	}
	return 1;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		cnt=0;
		int n,m,flg(0);
		scanf("%d%d",&n,&m);
		memset(head,-1,sizeof(int)*(n+2));
		for(int i=1;i<=m;i++)
		{
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			addedge(x,y+1,w);
			addedge(y+1,x,w);
		}
		memset(dist,INF,sizeof(int)*(n+2));
		for(int i=1;i<=n;i++)
			if(dist[i]==INF)
				if(!spfa(i,n))
				{
					flg=1;
					break;
				}
		if(flg)
			puts("No");
		else
			puts("Yes");
		memset(a,0,sizeof(struct edge)*(m*2+4));
	}
	return 0;
}
