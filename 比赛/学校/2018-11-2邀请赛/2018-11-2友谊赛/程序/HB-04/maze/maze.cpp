#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<cstdlib>
#include<algorithm>
#include<complex>
#include<iostream>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
char c1,c2;
int x,y;
#define nd(x,y) x*(n-1)+y
struct edge
{
    int to,next,weight;
}a[2000020];
int cnt(0);
int head[1000010];
int dist[1000010];
int vis[1000010];
int dg[1000010];
int q,flg,tmf;
int tmv;
struct node
{
    int dist,id;
    node(){}
    node(int dist,int id):dist(dist),id(id){}
};
bool operator <(node xi,node yi)
{
    return xi.dist>yi.dist;
}
struct pt
{
	int id;
	int rcost;
	int dcost;
}k[1000010];
bool operator <(pt xi,pt yi)
{
    return min(xi.dcost,xi.rcost)<min(yi.dcost,yi.rcost);
}
void addedge(int xi,int yi,int wi)
{
    a[cnt].to=yi;
    a[cnt].next=head[xi];
    a[cnt].weight=wi;
    head[xi]=cnt++;
}
void dijkstra(int s)
{
    memset(vis,0,sizeof(vis));
    memset(dist,INF,sizeof(dist));
    priority_queue<node> q;
    q.push(node(0,s));
    dist[s]=0;
    while(!q.empty())
    {
        node t=q.top();
        q.pop();
        if(vis[t.id])continue;
        vis[t.id]=1;
        for(int i=head[t.id];i!=-1;i=a[i].next)
        {
            int v=a[i].to;
            if(dist[v]>t.dist+a[i].weight)
            {
                dist[v]=t.dist+a[i].weight;
                q.push(node(dist[v],v));
            }
        }
    }
}
void build()
{
	addedge(nd(1,1),nd(1,2),1);
	addedge(nd(1,1),nd(2,1),1);
	addedge(nd(1,m),nd(2,m),1);
	addedge(nd(1,m),nd(1,m-1),1);
	addedge(nd(n,1),nd(n,2),1);
	addedge(nd(n,1),nd(n-1,1),1);
	addedge(nd(n,m),nd(n,m-1),1);
	addedge(nd(n,m),nd(n-1,m),1);
	for(int i=2;i<=n-1;i++)
	{
		addedge(nd(i,1),nd(i,1),1);
		addedge(nd(i,1),nd(i+1,2),1);
		addedge(nd(i,1),nd(i-1,1),1);
		addedge(nd(i,m),nd(i,m-1),1);
		addedge(nd(i,m),nd(i+1,m),1);
		addedge(nd(i,m),nd(i-1,m),1);
	}
	for(int i=2;i<=m-1;i++)
	{
		addedge(nd(1,i),nd(2,i),1);
		addedge(nd(1,i),nd(i+1,1),1);
		addedge(nd(1,i),nd(i-1,1),1);
		addedge(nd(n,i),nd(n-1,i),1);
		addedge(nd(n,i),nd(n,i-1),1);
		addedge(nd(n,i),nd(n,i+1),1);
	}
	for(int i=2;i<=n-1;i++)
	{
		for(int j=2;j<=m-1;j++)
		{
			addedge(nd(i,j),nd(i-1,j),1);
			addedge(nd(i,j),nd(i,j-1),1);
			addedge(nd(i,j),nd(i+1,j),1);
			addedge(nd(i,j),nd(i,j+1),1);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)dg[nd(i,j)]=4;
	for(int i=1;i<=n;i++)
	{
		dg[nd(i,1)]--;
		dg[nd(i,m)]--;
	}
	for(int i=1;i<=m;i++)
	{
		dg[nd(1,i)]--;
		dg[nd(n,i)]--;
	}
	dg[nd(1,1)]--;
	dg[nd(1,m)]--;
	dg[nd(n,1)]--;
	dg[nd(n,m)]--;
}
int find(int si,int ei)
{
	for(int i=head[si];i!=-1;i=a[i].next)
	{
		if(a[i].to==ei&&a[i].weight==INF)return i;
	}
	return -1;
}
void init()
{
	int pn=k[1].id;
	int pk=1;
	int ti=eg-tgt;
	while(ti--)
	{
		int xn=pn/(n-1)+1;
		int yn=pn%(n-1);
		if(flg==1)
		{
			tmf=1;
			tmv=k[pk].dcost;
			k[pk].dcost=INF;
			flg=0;
		}
		if(flg==2)
		{
			tmf=2;
			tmv=k[pk].dcost;
			k[pk].dcost=INF;
			flg=0;
		}
		if(flg==3)
		{
			tmf=3;
			tmv=k[pk].rcost;
			k[pk].rcost=INF;
			flg=0;
		}
		if(flg==4)
		{
			tmf=4;
			tmv=k[pk].rcost;
			k[pk].rcost=INF;
			flg=0;
		}
		if(k[pk].dcost<k[pk].rcost)
		{
			if(dg[nd(xn+1,yn)])
			{
				int e1=find(nd(xn+1,yn),nd(xn,yn));
				int e2=find(nd(xn,yn),nd(xn+1,yn));
				if(e1!=-1&&e2!=-1)
				{
					a[e1].weight=INF;
					a[e2].weight=INF;
					dg[nd(xn+1,yn)]--;
					dg[pn]--;
				}
				else
				{
					flg=1;
				}
			}
			else
			{
				flg=2;
			}
		}
		else
		{
			if(dg[nd(xn,yn+1)])
			{
				int e1=find(nd(xn,yn+1),nd(xn,yn));
				int e2=find(nd(xn,yn),nd(xn,yn+1));
				if(e1!=-1&&e2!=-1)
				{
					a[e1].weight=INF;
					a[e2].weight=INF;
					dg[nd(xn,yn+1)]--;
					dg[pn]--;
				}
				else
				{
					flg=3;
				}
			}
			else
			{
				flg=4;
			}
		}
		if(tmf==1)
		{
			k[pk].dcost=tmv;
		}
		if(tmf==2)
		{
			k[pk].dcost=tmv;
		}
		if(tmf==3)
		{
			k[pk].rcost=tmv;
		}
		if(tmf==4)
		{
			k[pk].rcost=tmv;
		}
		if(!dg[pn])pn=k[++pk].id;
	}
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	build();
	int eg=m*(n-1)+n*(m-1)*2;
	int tgt=(n*m-1)*2;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>c1>>x>>c2>>y;
			if(c1=='X')k[nd(i,j)].dcost=INF;
			else k[nd(i,j)].dcost=x;
			if(c2=='X')k[nd(i,j)].rcost=INF;
			else k[nd(i,j)].rcost=y;
			k[nd(i,j)].id=nd(i,j);
		}
	}
	sort(k+1,k+n*m+1);
	init();
	scanf("%d",&q);
	while(q--)
	{
		int sxq,syq,exq,eyq;
		scanf("%d%d%d%d",&sxq,&syq,&exq,&eyq);
		dijkstra(nd(sxq,syq));
		printf("%d\n",dist[nd(exq,eyq)]);
	}
	return 0;
}
