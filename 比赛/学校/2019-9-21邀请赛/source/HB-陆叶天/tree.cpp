#include <cstdio>
#include <cstring>
#include <cmath> 
#include <algorithm>
using namespace std;
struct node
{
	int u,v,d;
}e[1000009];
struct hahaha
{
	int u,v,d;
}ne[1000009];
int pop,f[500009],n,m,ans,book[500009],jump[500009],ok;
int getf(int v)
{
	if(f[v]==v) return v;
	else
	{
		f[v]=getf(f[v]); 
		return f[v];
	}
}
void dfs(int u,int maxn)
{
	if(book[u]==1) return;
	book[u]=1;
	ans+=maxn;
	for(int i=jump[u];i<jump[u+1];i++)
	{
		int ss=max(maxn,ne[i].d);
		dfs(ne[i].v,ss);
	}
	return; 
}
bool cmp(node a,node b)
{
	if(a.d==b.d) return a.u<b.u;
	else return a.d<b.d;
}
bool cmpx(hahaha a,hahaha b)
{
	if(a.u==b.u)
	{
		return a.d<b.d;
	}
	else
		return a.u<b.u;
}
void merge(int us,int vs,int ds)
{
	int t1=getf(us);
	int t2=getf(vs);
	if(t1!=t2)
	{
		f[t1]=t2;
	}
	ok++;
		ne[ok].u=us;
		ne[ok].v=vs;
		ne[ok].d=ds;
		ok++;
		ne[ok].v=us;
		ne[ok].u=vs;
		ne[ok].d=ds;
	return;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		pop++;
		e[pop].u=x;
		e[pop].v=y;
		e[pop].d=z;
		pop++;
		e[pop].v=x;
		e[pop].u=y;
		e[pop].d=z;
	}
	m*=2;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(getf(e[i].u)!=getf(e[i].v))
		{
			merge(e[i].u,e[i].v,e[i].d);
		}
	}
	sort(ne+1,ne+ok+1,cmpx);
	jump[1]=1;
	for(int i=1;i<=ok;i++)
	{
		if(ne[i].u!=ne[i-1].u && i!=1)
		{
			jump[ne[i].u]=i;
		}
	}
	jump[n+1]=ok+1;
	dfs(1,0);
	printf("%d",ans);
}
