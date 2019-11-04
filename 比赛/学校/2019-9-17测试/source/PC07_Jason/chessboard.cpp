#include<bits/stdc++.h>
using namespace std;
#define inf 99999999
struct edge
{
	int to,w,nxt;
}e[1000001];
int head[1001];
int edge_num=-1;
void add(int u,int v,int w)
{
	e[++edge_num].nxt=head[u];
	e[edge_num].to=v;
	e[edge_num].w=w;
	head[u]=edge_num;
}
void add_edge(int u,int v,int w)
{
	add(u,v,w);
	add(v,u,0);
}
int s,t;
int dep[1001];
bool bfs(int s,int t)
{
	memset(dep,0x3f,sizeof(dep));
	dep[s]=0;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];i!=-1;i=e[i].nxt)
			if(e[i].w)
			{
				int to=e[i].to;
				if(dep[to]>inf)
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
			int f=dfs(to,min(used,e[i].w));
			used-=f;
			e[i].w-=f;
			e[i^1].w+=f;
		}
	}
	return flow-used;
}
int dinic()
{
	int maxflow=0;
	while(bfs(s,t))
		maxflow+=dfs(s,inf);
	return maxflow;
}
int main()
{
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			char tmp;
			cin>>tmp;
			if(tmp=='.')
				add_edge(i,j+n,1);
		}
	s=0,t=n+n+1;
	for(int i=1;i<=n;i++)
		add_edge(0,i,1);
	for(int i=1;i<=n;i++)
		add_edge(i+n,t,1);
	printf("%d",dinic());
	return 0;
}
