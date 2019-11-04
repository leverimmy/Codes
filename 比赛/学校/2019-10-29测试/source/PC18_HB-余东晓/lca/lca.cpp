#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<complex>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
#define ll long long
int n,m,s;
int cnt(0);
int head[100010],d[100010],p[100010][18];
struct edge
{
    int to,next;
}a[200020];
void addedge(int u,int v)
{
	a[cnt]=(edge){v,head[u]};
    head[u]=cnt++;
}
void dfs(int u,int fa)
{
    d[u]=d[fa]+1;
    p[u][0]=fa;
    for(int i=1;(1<<i)<=d[u];i++)p[u][i]=p[p[u][i-1]][i-1];
    for(int i=head[u];i!=-1;i=a[i].next)
    {
        int v=a[i].to;
        if(v!=fa)dfs(v,u);
    }
}
int lca(int a,int b)
{
    if(d[a]>d[b])swap(a,b);
    for(int i=20;i>=0;i--)
    {
        if(d[a]<=d[b]-(1<<i))
        {
            b=p[b][i];
        }
    }
    if(a==b)return a;
    for(int i=20;i>=0;i--)
    {
        if(p[a][i]==p[b][i])continue;
        else a=p[a][i],b=p[b][i];
    }
    return p[a][0];
}
int main()
{
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
	int rt;
    for(int i=1;i<=n;i++)
    {
        int x;
		scanf("%d",&x);
		if(!x)
			rt=i;
		else
			addedge(x,i);
    }
    dfs(rt,0);
    for(int i=1;i<=m;i++)
    {
		int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    return 0;
}
