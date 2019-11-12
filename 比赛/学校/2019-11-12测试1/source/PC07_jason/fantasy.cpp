#include<bits/stdc++.h>
using namespace std;
#define inf 999999999
struct edge
{
	int to,nxt,w;
}e[1000001];
int edge_num=-1;
int cur[100010];
int head[100010];
void add_edge(int u,int v,int w)
{
	e[++edge_num].nxt=head[u];
	e[edge_num].w=w;
	e[edge_num].to=v;
	head[u]=edge_num;
}
void add(int u,int v,int w)
{
	add_edge(u,v,w);
	add_edge(v,u,0);
}
int s,t;
int dep[100010];
bool bfs(int s,int t)
{
	queue<int>q;
	memset(dep,0x3f,sizeof(dep));
	memcpy(cur,head,sizeof(cur));
	dep[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i!=-1;i=e[i].nxt)
		{
			int to=e[i].to;
			if(e[i].w&&dep[to]>dep[u]+1)
			{
				dep[to]=dep[u]+1;
				q.push(to);
			}
		}
	}
	return dep[t]<inf;
}
int dfs(int u,int flow)
{
	if(u==t) return flow;
	int used=flow;
	for(int i=head[u];i!=-1;i=e[i].nxt)
	{
		int to=e[i].to;
		if(dep[to]==dep[u]+1&&e[i].w&&used)
		{
			cur[u]=i;
			int f=dfs(to,min(used,e[i].w));
			used-=f;
			e[i].w-=f;
			e[i^1].w+=f;
		}
	}
	return flow-used;
}
int maxflow;
void dinic()
{
	while(bfs(s,t))
		maxflow+=dfs(s,inf);
}
int a[100001];
signed main()
{
	freopen("fantasy.in","r",stdin);
	freopen("fantasy.out","w",stdout);
	memset(head,-1,sizeof(head));
	s=0,t=100001;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,u,v;
		scanf("%d%d%d",&x,&u,&v);
		a[x]++;
		add(s,i,1);
		add(i,m+u,1);
		add(i,m+v,1);
	}
	for(int i=1;i<=n;i++)
		add(i+m,t,a[i]);
	dinic();
//	printf("%d\n",maxflow);
	for(int i=1;i<=m;i++)
	{
		if(e[head[i]].w)
			printf("0");
		else
			printf("1");
	}
	return 0;
}
