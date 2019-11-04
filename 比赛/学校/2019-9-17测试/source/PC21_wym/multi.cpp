#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
double dis[200010];
int top,pre[100010],ans[100010];
struct node
{
	double pos,dis;
	bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};
struct edge
{
	double to,len;
};
priority_queue<node>q;
bool vis[200010];
vector<edge>ed[200010];
void dijkstra()
{
	dis[(int)s]=0;
	q.push((node){s,0});
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		int x=t.pos;
		if(vis[x])
			continue;
		vis[x]=true;
		for(int i=0;i<ed[x].size();i++)
		{
			int y=ed[x][i].to;
			if(dis[y]>dis[x]+ed[x][i].len)
			{
				dis[y]=dis[x]+ed[x][i].len;
				pre[y]=x;
				if(!vis[y])
					q.push((node){y,dis[y]});
			}
		}
	}

}
int main()
{
	freopen("multi.in","r",stdin);
	freopen("multi.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		dis[i]=2147483647;
	long long t1,t2,t3;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&t1,&t2,&t3);
		ed[t1].push_back((edge){t2,log10(t3)});
	}
	scanf("%d%d",&s,&t);
	dijkstra();
	for(int i=t;i;i=pre[i])
		ans[++top]=i;
	for(int i=top;i>=1;i--)
		printf("%d ",ans[i]);
	return 0;
}

