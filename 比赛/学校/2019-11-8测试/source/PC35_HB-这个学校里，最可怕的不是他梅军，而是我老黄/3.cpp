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
	int to,next;
	bool isb;
}a[200020];
int head[10010],cnt(0),dfn[10010],low[10010],now;
void addedge(int x,int y)
{
	a[cnt]=(edge){y,head[x]};
	head[x]=cnt++;
}
int n,m;
void tarjan(int u,int imp)
{
	dfn[u]=low[u]=++now;
	for(int i=head[u];i!=-1;i=a[i].next)
	{
		int v=a[i].to;
		if(!dfn[v])
		{
			tarjan(v,i);
			low[u]=std::min(low[u],low[v]);
			if(low[v]>dfn[u])
				a[i].isb=a[i^1].isb=1;
		}	
		else if(i!=imp^1)
			low[u]=std::min(low[u],dfn[v]);
	}
}
signed main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	while(~scanf("%d%d",&n,&m))
	{
		memset(head,-1,sizeof(head));
		memset(a,0,sizeof(a));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		cnt=now=0;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			addedge(x,y);
			addedge(y,x);
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i,0);
		int ans(0);
		for(int i=0;i<m*2;i+=2)
			if(a[i].isb)
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}
