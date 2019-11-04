#include<cstdio>
#include<cstdlib>
#include<cstring>
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
/*
struct edge
{
	int to,next,weight;
}a[1000010];
int head[250025],cnt(0);
void addedge(int x,int y,int w)
{
	a[cnt]=(edge){y,head[x],w};
	head[x]=cnt++;
}
*/
struct point
{
	int x,y;
}p[550];
int getdis(int x,int y)
{
	return abs(p[x].x-p[y].x)+abs(p[x].y-p[y].y);
}
/*
struct node
{
	int d,id;
	node(){}
	node(int d,int id):d(d),id(id){}
};
bool operator <(node x,node y)
{
	return x.d>y.d;
}
bool vis[250025];
int dist[250025];
void dijkstra(int s)
{
	memset(vis,0,sizeof(vis));
	memset(dist,INF,sizeof(dist));
	std::priority_queue<node>q;
	q.push(node(0,s));
	dist[s]=0;
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		int u=t.id;
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=head[u];i!=-1;i=a[i].next)
		{
			int v=a[i].to;
			if(dist[v]>t.d+a[i].weight)
			{
				dist[v]=t.d+a[i].weight;
				q.push(node(dist[v],v));
			}
		}
	}
}
signed main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=1;i<=n-1;i++)
		for(int j=0;j<=k;j++)
			addedge(i+n*j,i+1+n*j,getdis(i,i+1));
	for(int i=1;i<=n-2;i++)
		for(int j=1;j<=k;j++)
			addedge(i+n*(j-1),i+2+n*j,getdis(i,i+2));
	for(int i=1;i<=k;i++)
		addedge(n*i,n+n*i,0);
	dijkstra(1);
	return!printf("%d\n",dist[n+n*k]);
}
*/
int f[505][505];
signed main()
{
	freopen("transport.in","r",stdin);
	freopen("transport.out","w",stdout);
	memset(f,INF,sizeof(f));
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	f[1][0]=0;
	for(int i=1;i<=n-1;i++)
		for(int j=0;j<=k;j++)
			for(int p=1;p+j-1<=k&&i+p<=n;p++)
				f[i+p][j+p-1]=std::min(f[i+p][j+p-1],f[i][j]+getdis(i,i+p));
	for(int i=0;i<=k;i++)
		f[n][k]=std::min(f[n][k],f[n][i]);
	return!printf("%d\n",f[n][k]);
}
