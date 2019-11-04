#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int tot,ans=0;
int fir[100010],fa[100010];
struct edge
{
	int from;
	int to;
	int dis;
	int next;
}v[500010],e[200010];
void add(int x,int y,int z)
{
	e[++tot].from=x;
	e[tot].to=y;
	e[tot].dis=z;
	e[tot].next=fir[x];
	fir[x]=tot;
}
bool cmp(edge a,edge b)
{
	return a.dis<b.dis;
}
int find(int x)
{
	if(fa[x]!=x) return fa[x]=find(fa[x]);
	else return x;
}
void dfs(int p,int s,int fa)
{
	ans+=s;
	for(int i=fir[p];i;i=e[i].next)
	{
		int q=e[i].to;
		if(q==fa) continue;
		dfs(q,max(s,e[i].dis),p);
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[i].from=a;
		v[i].to=b;
		v[i].dis=c;
	}
	sort(v+1,v+m+1,cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int f1=find(v[i].from),f2=find(v[i].to);
		if(f1!=f2)
		{
			fa[f1]=f2;
			add(v[i].from,v[i].to,v[i].dis);
			add(v[i].to,v[i].from,v[i].dis);
		}
	}
	dfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}
