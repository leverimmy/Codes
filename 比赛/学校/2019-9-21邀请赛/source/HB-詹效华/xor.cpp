#include <bits/stdc++.h>
using namespace std;
#define inf 2147483647
struct edge
{
	int to,w;
	edge(int x1=0,int x2=0){to=x1,w=x2;}
};
vector<edge>e[100010];
int n,m;
int dis[100010],vis[100010];
bool spfa(int s)
{
	queue<int>q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=0;i<e[u].size();i++)
		{
			int to=e[u][i].to;
			if(dis[to]==inf)
			{
				dis[to]=dis[u]^e[u][i].w;
				q.push(to);
			}
			else if(dis[to]!=(dis[u]^e[u][i].w))
				return false;
		}
	}
	return true;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=n+1;i++)
			e[i].clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			e[l].push_back(edge(r+1,k));
			e[r+1].push_back(edge(l,k));
		}
		int flag=0;
		for(int i=1;i<=n+1;i++)
			dis[i]=inf;
		for(int i=1;i<=n;i++)
			if(dis[i]==inf)
				if(!spfa(i))
					flag=1;
		if(!flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
