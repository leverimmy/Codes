#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,m;
int ver_cnt;
struct edge{int u,v,w;}ed[200001];
bool cmp(edge a,edge b){return a.w<b.w;}

vector<int>e[200001];
int fa[200001];
int a[200001];

int find(int x){return (fa[x]==x)?fa[x]:fa[x]=find(fa[x]);}
void kruskal()
{
	ver_cnt=n;
	sort(ed+1,ed+m+1,cmp);
	for(int i=1;i<=2*n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int f1=find(ed[i].u),f2=find(ed[i].v);
		if(f1!=f2)
		{
			fa[f1]=++ver_cnt;
			fa[f2]=ver_cnt;
			e[ver_cnt].push_back(f1);
			e[ver_cnt].push_back(f2);
			a[ver_cnt]=ed[i].w;
		}
	}
}

int f[200001][21];
int dep[200001];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=20;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if(to!=fa)
			dfs(to,u);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]>=dep[y])
			x=f[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);
	kruskal();
	dfs(ver_cnt,0);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",a[lca(u,v)]);
	}
	return 0;
}
/*
4 6 
1 2 3
1 3 5
2 4 1
3 4 2
4 1 3
2 3 7
3
2 4
2 3
1 4
*/