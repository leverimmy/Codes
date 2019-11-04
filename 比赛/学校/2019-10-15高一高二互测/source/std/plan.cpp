#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int to,w;
	edge(int x1=0,int x2=0){to=x1,w=x2;}
};
vector<edge>e[100001];
int dis[100001],pre[100001],vis[100001];
struct cmp
{
	bool operator()(int a,int b)
	{
		return dis[a]>dis[b];
	}
};
void spfa(int s)
{
	priority_queue<int,vector<int>,cmp>q;
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0,vis[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		vis[u]=0;
		for(int i=0;i<e[u].size();i++)
		{
			int to=e[u][i].to;
			if(dis[to]>dis[u]+e[u][i].w)
			{
				dis[to]=dis[u]+e[u][i].w;
				pre[to]=e[u][i].w;
				if(!vis[to])
				{
					vis[to]=1;
					q.push(to);
				}
			}
			else if(dis[to]==dis[u]+e[u][i].w&&e[u][i].w<pre[to])
			{
				dis[to]=dis[u]+e[u][i].w;
				pre[to]=e[u][i].w;
				if(!vis[to])
				{
					vis[to]=1;
					q.push(to);
				}
			}
		}
	}
}
signed main()
{
	freopen("plan.in", "r", stdin);
	freopen("plan.out", "w", stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back((edge){v,w});
		e[v].push_back((edge){u,w});
	}
	spfa(1);
	long long ans=0;
	for(int i=2;i<=n;i++)
		ans+=pre[i];
	printf("%lld",ans);
	return 0;
}
