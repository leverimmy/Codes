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
	int to,next,weight;
}a[300030];
int head[50050],cnt(0);
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
int dist[50050],val[50050],rad[50050],mx[50050];
std::priority_queue<node>q;
std::stack<int>st;
void dijkstra(int l)
{
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		int u=t.id;
		if(dist[u]!=t.d)
			continue;
		st.push(u);
		for(int i=head[u];i!=-1;i=a[i].next)
		{
			int v=a[i].to;
			if(val[v]>l)
				continue;
			if(dist[v]>t.d+a[i].weight&&mx[v]>t.d+a[i].weight)
			{
				dist[v]=t.d+a[i].weight;
				q.push(node(dist[v],v));
			}
		}
	}
}
signed main()
{
	freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout);
	memset(head,-1,sizeof(head));
	memset(mx,INF,sizeof(mx));
	memset(dist,INF,sizeof(dist));
	int n,m,ans(0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	while(m--)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		addedge(x,y,w);
		addedge(y,x,w);
	}
	for(int l=10;l>=1;l--)
	{
		memset(rad,INF,sizeof(rad));
		for(int i=1;i<=n;i++)
		{
			if(val[i]==l)
			{
				q.push(node(0,i));
				dist[i]=0;
				dijkstra(l);
			}
			while(!st.empty())
			{
				int u=st.top();
				st.pop();
				if(mx[u]>dist[u])
					ans++;
				rad[u]=std::min(rad[u],dist[u]);
				dist[u]=INF;
			}
		}
		for(int i=1;i<=n;i++)
			mx[i]=std::min(mx[i],rad[i]);
	}
	return!printf("%d\n",ans);
}
