#include<cstdio>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdlib>
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
}a[100010];
int head[10010],cnt(0);
void addedge(int x,int y,int w)
{
	a[cnt]=(edge){y,head[x],w};
	head[x]=cnt++;
}
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
int dist[10010];
bool vis[10010];
std::priority_queue<node>q;
int dijkstra(int s,int t)
{
	memset(dist,INF,sizeof(dist));
	memset(vis,0,sizeof(vis));
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
			if(a[i].weight+t.d<dist[v])
			{
				dist[v]=a[i].weight+t.d;
				q.push(node(dist[v],v));
			}
		}
	}
	return dist[t];
}
signed main()
{
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		memset(head,-1,sizeof(head));
		memset(a,0,sizeof(a));
		cnt=0;
		while(m--)
		{
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			addedge(x,y,w);
		}
		printf("%d\n",dijkstra(1,n));
	}
	return 0;
}
