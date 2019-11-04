#include<bits/stdc++.h>
using namespace std;
vector<int>e[500001];
int fa[500001],siz[500001];
int find(int x){return (fa[x]==x)?fa[x]:fa[x]=find(fa[x]);}
void join(int x,int y)
{
	int f1=find(x),f2=find(y);
	if(f1!=f2)
	{
		fa[f1]=f2;
		siz[f2]+=siz[f1];
	}
}
int p[500001];
int occ[500001];
signed main()
{
	freopen("migration.in","r",stdin);
	freopen("migration.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]),fa[i]=i,siz[i]=1;
	vector<int>v;
	for(int i=n;i>=1;i--)
	{
		if(p[i]<0)
			printf("!");
		occ[p[i]]=1;
		for(int j=0;j<e[p[i]].size();j++)
		{
			int to=e[p[i]][j];
			if(occ[to]==1)
				join(p[i],to);
		}
		if(siz[find(p[n])]==n-i+1)
			v.push_back(1);
		else
			v.push_back(0);
	}
	reverse(v.begin(),v.end());
	for(int i=0;i<n;i++)
		if(v[i]==1)
			printf("YES\n");
		else
			printf("NO\n");
	return 0;
}
