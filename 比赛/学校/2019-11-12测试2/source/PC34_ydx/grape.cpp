#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
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
char cb[1<<17],*cs=cb,*ct=cb;
#define getc() (cs==ct&&(ct=(cs=cb)+fread(cb,1,1<<17,stdin),cs==ct)?0:*cs++)
inline void read(int &res)
{
    char ch;
    for(;!isdigit(ch=getc()););
    for(res=ch-'0';isdigit(ch=getc());res=res*10+ch-'0');
}
inline void read(ll &res)
{
    char ch;
    for(;!isdigit(ch=getc()););
    for(res=ch-'0';isdigit(ch=getc());res=res*10+ch-'0');
}
struct edge
{
	int to,next,s,t;
}a[800080];
int head[200020],cnt(0);
void addedge(int x,int y,int s,int t)
{
	a[cnt]=(edge){y,head[x],s,t};
	head[x]=cnt++;
}
bool vis[200020],col[200020];
std::queue<int>q;
bool bfs(int s,int t)
{
	memset(col,0,sizeof(col));
	memset(vis,0,sizeof(vis));
	q.push(s);
	vis[s]=1;
	col[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(register int i=head[u];i!=-1;i=a[i].next)
		{
			if(a[i].s>t||a[i].t<t)
				continue;
			int v=a[i].to;
			if(vis[v]&&col[u]==col[v])
				return 0;
			if(!vis[v])
			{
				vis[v]=1;
				col[v]=col[u]^1;
				q.push(v);
			}
		}
	}
	return 1;
}
signed main()
{
	freopen("grape.in","r",stdin);
	freopen("grape.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n,m,k;
	read(n);
	read(m);
	read(k);
	register int x,y,s,t;
	for(register int i=1;i<=m;i++)
	{
		read(x);
		read(y);
		read(s);
		read(t);
		addedge(x,y,s+1,t);
		addedge(y,x,s+1,t);
	}
	for(register int i=1;i<=k;i++)
		if(bfs(1,i))
			puts("Yes");
		else
			puts("No");
	return 0;
}
