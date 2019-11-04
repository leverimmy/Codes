#include<cstdio>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<cstring>
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
	int x,y,w;
}a[1000010];
int fa[100010],siz[100010];
int find(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}
bool operator <(edge x,edge y)
{
	return x.w<y.w;
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,m;ll ans(0);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		siz[i]=1;
	}
	std::sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)
	{
		int x=find(a[i].x),y=find(a[i].y);
		ll w=a[i].w;
		if(x==y)
			continue;
		if(find(1)==x)
			ans+=(ll)siz[y]*w;
		if(find(1)==y)
			ans+=(ll)siz[x]+w;
		fa[x]=y;
		siz[y]+=siz[x];
	}
	return!printf("%lld\n",ans);
}
