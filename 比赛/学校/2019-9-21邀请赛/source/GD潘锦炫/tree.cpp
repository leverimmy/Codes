#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;


int ans;
int n,m;
int x,y,z;
int u,v;
vector<int>g[100005];
vector<int>c[100005];

int dis[100005];
int vis[100005];
queue<int>q;


int main()
{
	
	freopen("tree.in","r",stdin); 
	freopen("tree.out","w",stdout); 
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(y);
		c[x].push_back(z);
		g[y].push_back(x);
		c[y].push_back(z);
	}
	
	memset(dis,0x3f,sizeof(dis));
	
	q.push(1);
	dis[1]=0;
	
	
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++)
		{
			v=g[u][i];
			if(!vis[v])
			{
				if(dis[v]>c[u][i]&&dis[v]>dis[u])
				{
					dis[v]=max(dis[u],c[u][i]);
					q.push(v);
				}
			}
		}
	}
	
	for(int i=2;i<=n;i++)
	ans+=dis[i];
	
	printf("%d",ans);
	
	
	return 0;
}
