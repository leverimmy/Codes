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
#define f(x) (x)*(x)
struct edge
{
	int to,next;
	ll weight;
}a[1000010];
int head[250025],cnt(0);
void addedge(int x,int y,ll w)
{
	a[cnt]=(edge){y,head[x],w};
	head[x]=cnt++;
}
struct point
{
	ll x,y;
}p[1010];
ll getdis(int x,int y)
{
	return f(p[x].x-p[y].x)+f(p[x].y-p[y].y);
}
struct node
{
	ll d;
	int id;
	node(){}
	node(ll d,int id):d(d),id(id){}
};
bool operator <(node x,node y)
{
	return x.d>y.d;
}
ll dist[1010];
bool vis[1010];
ll prims(int s,int n)
{
    ll ans(-INF);
    int tot(0);
    memset(dist,INF,sizeof(dist));
    memset(vis,0,sizeof(vis));
    std::priority_queue<node>q;
    q.push(node(0,s));
    dist[s]=0;
    while(!q.empty())
    {
        node t(q.top());
        q.pop();
        if(t.d!=dist[t.id])
			continue;
        vis[t.id]=1;
        tot++;
        for(int i=head[t.id];i!=-1;i=a[i].next)
        {
            int v=a[i].to;
            if(!vis[v]&&a[i].weight<dist[v])
            {
                dist[v]=a[i].weight;
                q.push(node(dist[v],v));
            }
        }
    }
	for(int i=1;i<=n;i++)
		ans=std::max(ans,dist[i]);
    return ans;
}
signed main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&p[i].x,&p[i].y);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				addedge(i,j,getdis(i,j));
	return!printf("%lld\n",prims(1,n));
}
