#include <bits/stdc++.h>
using namespace std;
int siz[100001];
int fa[100001];
struct edge
{
	int u,v,w;
}e[100001];
bool cmp(edge a,edge b){return a.w<b.w;}
int find(int x){return (fa[x]==x)?fa[x]:fa[x]=find(fa[x]);}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1,cmp);
	long long ans=0;
	for(int i=1;i<=n;i++)
		fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++)
	{
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2)
		{
			if(find(1)==f1)
				ans+=1ll*siz[f2]*e[i].w;
			if(find(1)==f2)
				ans+=1ll*siz[f1]*e[i].w;
			fa[f1]=f2;
			siz[f2]+=siz[f1];
		}
	}
	printf("%lld",ans);
	return 0;
}
