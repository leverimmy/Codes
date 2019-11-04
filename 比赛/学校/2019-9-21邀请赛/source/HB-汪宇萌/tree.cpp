#include<bits/stdc++.h>
using namespace std;
long long n,m,s,dis[200010];
struct node
{
	long long pos,dis;
	bool operator <( const node &x )const
    {
        return x.dis < dis;
    }
};
struct edge
{
	long long to,len;
};
priority_queue<node>q;
bool vis[200010];
vector<edge>ed[200010];
void dijkstra()
{
	dis[s]=0;
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
			if(dis[y]>max(dis[x],ed[x][i].len))
			{
				dis[y]=max(dis[x],ed[x][i].len);
				if(!vis[y])
					q.push((node){y,dis[y]});
			}
		}
	}

}
int main()
{
 	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&m);
	s=1;
	for(int i=1;i<=n;++i)
		dis[i] = 0x7fffffff;
	int t1,t2,t3;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&t1,&t2,&t3);
		ed[t1].push_back((edge){t2,t3});
		ed[t2].push_back((edge){t1,t3});
	}
	dijkstra();
	unsigned long long ans=0;
	for(int i=2;i<=n;i++)
		ans+=dis[i];
	cout<<ans;
	return 0;	
}

