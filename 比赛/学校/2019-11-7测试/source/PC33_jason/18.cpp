#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int n,m;
int fa[10001];
int find(int x){return (fa[x]==x)?fa[x]:fa[x]=find(fa[x]);}
signed main()
{
	freopen("18.in","r",stdin);
	freopen("18.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		int f1=find(u),f2=find(v);
		if(f1!=f2)
			fa[f1]=f2;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(find(i)==i)
			ans++;
	printf("%d",ans);
	return 0;
}