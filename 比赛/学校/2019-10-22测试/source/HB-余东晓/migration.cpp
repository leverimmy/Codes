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
std::vector<int>a[200020];
int fa[200020],nd[200020];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool vis[200020],o[200020];
signed main()
{
	freopen("migration.in","r",stdin);
	freopen("migration.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int rt(0);
	std::queue<int>q;
	for(int i=1;i<=n;i++)
		scanf("%d",&nd[i]);
	rt=nd[n];
	for(int p=n;p>=1;p--)
	{
		int u=nd[p];
		vis[u]=1;
		for(int i=0;i<a[u].size();i++)
		{
			int v=a[u][i];
			if(vis[v])
			{
				int fu=find(u),fv=find(v);
				if(fu==fv)
					continue;
				fa[fv]=fu;
			}
		}
		int fu=find(u),fr=find(rt);
		if(fu!=fr)
			q.push(fu);
		while((!q.empty())&&find(q.front())==fr)
			q.pop();
		o[p]=q.empty();
	}
	for(int i=1;i<=n;i++)
		if(o[i])
			puts("YES");
		else
			puts("NO");
	return 0;
}
