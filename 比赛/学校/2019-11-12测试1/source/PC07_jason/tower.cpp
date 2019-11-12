#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u,v,w;
	node(int x1=0,int x2=0,int x3=0){u=x1,v=x2,w=x3;}
};
bool cmp(node a,node b){return a.w<b.w;}
vector<node>rem;
int x[500001],y[500001];
int dis(int a,int b){return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);}
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
signed main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]),fa[i]=i,siz[i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
			rem.push_back(node(i,j,dis(i,j)));
	}
	sort(rem.begin(),rem.end(),cmp);
	for(int i=0;i<rem.size();i++)
	{
//		printf("%d %d %d\n",rem[i].u,rem[i].v,rem[i].w);
		join(rem[i].u,rem[i].v);
		if(siz[find(1)]==n)
		{
			printf("%d",rem[i].w);
			return 0;
		}
	}
	return 0;
}