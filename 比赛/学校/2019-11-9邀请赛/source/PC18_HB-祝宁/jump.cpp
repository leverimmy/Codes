#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<cassert>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<list>
#define ll long long
#define INF 0x3f3f3f3f
struct edge
{
	int to,next;
}a[100010];
int head[50005],cal(0);
void addedge(int x,int y)
{
	a[cal]=(edge){y,head[x]};
	head[x]=cal++;
}
int dep[50005],cnt[50005][201],n,k;
ll omiga(0),ans(0);
void init(int u,int fa)
{
	dep[u]=dep[fa]+1;
	cnt[u][dep[u]%k]=1;
	for(int i=head[u];i!=-1;i=a[i].next)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		init(v,u);
		for(int p=0;p<k;p++)
			cnt[u][p]+=cnt[v][p];
	}
}
int dc[201];
void dfs(int u,int fa)
{
	for(int i=0;i<k;i++)
		dc[i]=cnt[1][i]-cnt[u][i];
	ll delta(0);
	if(u!=1)
		delta=(ll)cnt[u][dep[u]%k]-(ll)dc[(k*50000-dep[u]+1)%k];
	omiga-=delta;
	ans+=omiga;
	for(int i=head[u];i!=-1;i=a[i].next)
	{
		int v=a[i].to;
		if(v==fa)
			continue;
		dfs(v,u);
	}
	omiga+=delta;
}
signed main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	dep[0]=-1;
	init(1,0);
	for(int i=1;i<=n;i++)
		omiga+=(ll)(dep[i]/k)+(ll)(!(!(dep[i]%k)));
	dfs(1,0);
	return!printf("%lld\n",ans/2);
}
