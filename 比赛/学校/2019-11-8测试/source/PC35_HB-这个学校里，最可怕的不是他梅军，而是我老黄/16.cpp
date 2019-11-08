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
int n,m;
int x,y,w;
int head[1010];
int cnt[1010];
int dist[1010];
int vis[1010];
int cal(0);
struct edge
{
	int to,next,weight;
}a[2020];
void addedge(int xi,int yi,int wi)
{
	a[cal].to=yi;
	a[cal].next=head[xi];
	a[cal].weight=wi;
	head[xi]=cal++;
}
bool spfa(int s)
{
	memset(dist,INF,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	std::queue<int> q;
	cnt[s]=1;
	dist[s]=0;
	vis[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		vis[t]=0;
		for(int i=head[t];i!=-1;i=a[i].next)
		{
			int v=a[i].to;
			if(dist[v]>dist[t]+a[i].weight)
			{
				dist[v]=dist[t]+a[i].weight;
				cnt[v]=cnt[t]+1;
				if(cnt[v]>n)
					return 1;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return 0;
}
signed main()
{
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	while(~scanf("%d%d",&n,&m))
	{
		memset(head,-1,sizeof(head));
		memset(a,0,sizeof(a));
		cal=0;
		while(m--)
		{
			scanf("%d%d%d",&x,&y,&w);
			addedge(x,y,w);
			if(w>=0)
				addedge(y,x,w);
		}
		spfa(1)?printf("yes\n"):printf("no\n");
	}
	return 0;
}
