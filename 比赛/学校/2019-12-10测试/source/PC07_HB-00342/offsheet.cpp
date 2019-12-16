#include<bits/stdc++.h>
using namespace std;
const int inf=999999999;
const long long linf=1e18;
struct edge
{
	int to,from,v,w,nxt;
}e[100001*2];
int edge_cnt=-1;
int head[501];
void add_edge(int u,int v,int w,int val)
{
	e[++edge_cnt].to=v;
	e[edge_cnt].from=u;
	e[edge_cnt].w=w;
	e[edge_cnt].v=val;
	e[edge_cnt].nxt=head[u];
	head[u]=edge_cnt;
}
void add(int u,int v,int w,int val)
{
	add_edge(u,v,w,val);
	add_edge(v,u,0,-val);
}
long long dis[501];
int vis[501];
int pre[501];
bool spfa(int s,int t)
{
	queue<int>q;
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0,vis[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i!=-1;i=e[i].nxt)
		{
			if(e[i].w)
			{
				int to=e[i].to;
				if(dis[to]>dis[u]+e[i].v)
				{
					pre[to]=i;
					dis[to]=dis[u]+e[i].v;
					if(!vis[to])
					{
						vis[to]=1;
						q.push(to);
					}
				}
			}
		}
	}
	return dis[t]<linf;
}
long long maxflow=0,mincost=0;
void MCMF(int s,int t)
{
	while(spfa(s,t))
	{
		int x=t,flow=inf;
		while(x!=s)
		{
			flow=min(flow,e[pre[x]].w);
			x=e[pre[x]].from;
		}
		x=t;
		while(x!=s)
		{
			e[pre[x]].w-=flow;
			e[pre[x]^1].w+=flow;
			x=e[pre[x]].from;
		}
		maxflow+=flow;
		mincost+=1ll*dis[t]*flow;
	}
}
int x[201],y[201],num[201];
int xx[201],yy[201],numm[201];
int main()
{
	freopen("offsheet.in","r",stdin);
	freopen("offsheet.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&x[i],&y[i],&num[i]);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&xx[i],&yy[i],&numm[i]);
	int s=0,t=401;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			add(i,j+n,inf,-abs(x[i]-xx[j])-abs(y[i]-yy[j]));
	for(int i=1;i<=n;i++)
		add(s,i,num[i],0);
	for(int i=1;i<=n;i++)
		add(i+n,t,numm[i],0);
	MCMF(s,t);
	printf("%lld",-mincost);
	return 0;
}
/*
2
0 0 1
3 2 1
2 2 1
5 0 1
*/