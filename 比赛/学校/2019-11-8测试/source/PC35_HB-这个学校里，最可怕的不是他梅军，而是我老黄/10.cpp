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
}a[1010];
int head[1010],cnt(0),low[1010],fa[1010],hep[1010],top(0),tot(0),dfn[1010],vis[1010],now(0),lst[1010];
void addedge(int x,int y)
{
	a[cnt]=(edge){y,head[x]};
	head[x]=cnt++;
}
void tarjan(int u)
{
    low[u]=dfn[u]=++now;
    hep[++top]=u;
	vis[u]=1;
    for(int i=head[u];i!=-1;i=a[i].next)
    {
        int v=a[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=std::min(low[u],low[v]);
        }
        else if(vis[v])
			low[u]=std::min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        ++tot;
        vis[u]=0;
        while(hep[top+1]!=u)
        {
            fa[hep[top]]=tot;
            vis[hep[top--]]=0;
        }
    }
}
signed main()
{
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		memset(head,-1,sizeof(head));
		memset(a,0,sizeof(a));
		memset(dfn,0,sizeof(dfn));
		memset(lst,0,sizeof(lst));
		memset(low,0,sizeof(low));
		memset(vis,0,sizeof(vis));
		memset(hep,0,sizeof(hep));
		memset(fa,0,sizeof(fa));
		cnt=now=tot=top=0;
		while(m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			addedge(x,y);
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i])	
				tarjan(i);
		printf("%d\n",tot);
	}
	return 0;
}
