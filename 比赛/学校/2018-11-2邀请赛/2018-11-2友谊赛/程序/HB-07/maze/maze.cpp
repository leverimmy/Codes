#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

const int N=250010;

int read()
{
	int out=0;
	char c;
	for (c=getchar();!isdigit(c);c=getchar());
	for (;isdigit(c);c=getchar()){out=out*10+c-'0';}
	return out;
}

char rc()
{
	char c;
	for (c=getchar();!isupper(c);c=getchar());
	return c;
}

void write(int x)
{
	if (x>9)
	{
		write(x/10);
	}
	putchar(x%10+'0');
}

void add(int u,int v);
int find(int x);
void dfs1(int u);
void dfs2(int u); 

struct Edge
{
	int u,v,w;
	bool operator<(Edge& b)
	{
		return w>b.w;
	}
} e[N<<1];

int head[N],nxt[N<<1],to[N<<1],cnt;
int n,m,q,f[N],ans,dep[N],siz[N],fa[N],son[N],top[N],tot;

int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	
	int i,j,u,v,x,y;
	char c;
	
	n=read();
	m=read();
	
	for (i=1;i<=n;++i)
	{
		for (j=1;j<=m;++j)
		{
			c=rc();
			e[tot].w=read();
			e[tot].u=(i-1)*m+j;
			if (c=='R')
			{
				e[tot++].v=(i-1)*m+j+1;
			}
			else if (c=='D')
			{
				e[tot++].v=i*m+j;
			}
			c=rc();
			e[tot].w=read();
			e[tot].u=(i-1)*m+j;
			if (c=='R')
			{
				e[tot++].v=(i-1)*m+j+1;
			}
			else if (c=='D')
			{
				e[tot++].v=i*m+j;
			}
		}
	}
	
	sort(e,e+tot);
	
	for (i=1;i<=n*m;++i)
	{
		f[i]=i;
	}
	
	for (i=0;i<tot;++i)
	{
		if (find(e[i].u)!=find(e[i].v))
		{
			f[find(e[i].u)]=find(e[i].v);
			add(e[i].u,e[i].v);
			add(e[i].v,e[i].u);
		}
	}
	
	dfs1(1);
	top[1]=1;
	dfs2(1);
	
	q=read();
	
	while (q--)
	{
		x=read();
		y=read();
		u=(x-1)*m+y;
		x=read();
		y=read();
		v=(x-1)*m+y;
		ans=dep[u]+dep[v];
		while (top[u]!=top[v])
		{
			if (dep[top[u]]>dep[top[v]])
			{
				u=fa[top[u]];
			}
			else
			{
				v=fa[top[v]];
			}
		}
		ans-=2*min(dep[u],dep[v]);
		write(ans);
		putchar('\n');
	}
	
	return 0;
}

void dfs1(int u)
{
	int i,v;
	siz[u]=1;
	for (i=head[u];i;i=nxt[i])
	{
		v=to[i];
		if (v!=fa[u])
		{
			fa[v]=u;
			dep[v]=dep[u]+1;
			dfs1(v);
			siz[u]+=siz[v];
			if (siz[v]>siz[son[u]])
			{
				son[u]=v;
			}
		}
	}
}

void dfs2(int u)
{
	int i,v;
	if (son[u])
	{
		top[son[u]]=top[u];
		dfs2(son[u]);
	}
	for (i=head[u];i;i=nxt[i])
	{
		v=to[i];
		if (v!=fa[u]&&v!=son[u])
		{
			top[v]=v;
			dfs2(v);
		}
	}
}

int find(int x)
{
	return x==f[x]?x:f[x]=find(f[x]);
}

void add(int u,int v)
{
	nxt[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
