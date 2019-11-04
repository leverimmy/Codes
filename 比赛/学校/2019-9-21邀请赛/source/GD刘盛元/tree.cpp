#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<cstdlib>
const int M=2e5;
const int N=1e5;
using namespace std;
struct Edge
{
	int to,val,front;
}G[M];
int head[N],gs,n,m;
void add(int x,int y,int w)
{
	G[gs].to=y;
	G[gs].front=head[x];
	G[gs].val=w;
	head[x]=gs++;
}
struct data
{
	int x,y,w;
}e[M];
int vis[M],fa[N],ans;
int fd(int p)
{
	int i=p,j;
	while (fa[i]>=0) i=fa[i];
	while (i!=p)
	{
		j=fa[p],fa[p]=i,p=j;
	}
	return i;
}
void unoi(int p,int q)
{
	int p1=fd(p);
	int q1=fd(q);
	if (p1==q1) return;
	int t=fa[p1]+fa[q1];
	if (fa[p1]>fa[q1]) fa[q1]=t,fa[p1]=q1;
	else fa[p1]=t,fa[q1]=p1;
}
bool cmp(data a,data b)
{
	return a.w<b.w;
}
void kruskar()
{
	for (int i=1;i<=n;i++) fa[i]=-1;
	sort(e+1,e+1+m,cmp);
	int cnt=0;
	for (int i=1;i<=m;i++)
	{
		int tx=fd(e[i].x),ty=fd(e[i].y);
		if (tx!=ty)
		{
			vis[i]=1;
			unoi(e[i].x,e[i].y);
			ans+=e[i].w;
			cnt++;
			if (cnt==n-1) break;
		}
	}
}
int f[N];
void Tree_dp(int x,int fa,int sum)
{
	f[x]=max(f[fa],sum);
	for (int i=head[x];i!=-1;i=G[i].front)
	{
		int y=G[i].to;
		if (y==fa) continue;
		Tree_dp(y,x,G[i].val);
	}
}
int x,y,w;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	}
	kruskar();
	ans=0;
	for (int i=1;i<=m;i++)
	{
		if (vis[i]==1)
		{
			add(e[i].x,e[i].y,e[i].w);
			add(e[i].y,e[i].x,e[i].w);
		}
	}
	Tree_dp(1,0,0);
	for (int i=1;i<=n;i++) ans+=f[i];
	cout<<ans;
	return 0;
}
