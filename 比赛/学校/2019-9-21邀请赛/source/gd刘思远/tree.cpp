#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=0;
	int rere=0;
	while (ch<'0'||ch>'9') {ch=getchar();}
	while (ch>='0'&&ch<='9')
	{
		rere=rere*10+ch-'0';
		ch=getchar();
	}
	return rere;
}
inline void write(int rerere)
{
	if (rerere>9) write(rerere/10);
	putchar(rerere%10+'0');
	putchar('\n');
}
struct ss{
	int x,y,z;
}g[500010];
int fa[100010];
inline int get(int x)
{
 	if (x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
bool cmp(ss a,ss b)
{
	return a.z<b.z;
}
struct node{
	int to,val,next,from; 
}gg[500050];
int tot,head[100050],ans,f[100010],n,m,b[500010];
bool v[100010];
void add(int x,int y,int w)
{
	tot++;
	gg[tot].from=x;
	gg[tot].to=y;
	gg[tot].val=w;
	gg[tot].next=head[x];
	head[x]=tot;
}
void bfs(int u)
{
	int h=1,t=1;
	b[1]=1;
	while (h<=t)
	{
		for (register int i=head[b[h]];i;i=gg[i].next)
		{
			int y=gg[i].to;
			int w=gg[i].val;
			if (v[y]==0)
			{
				t++;
				b[t]=y;
				f[y]=max(f[gg[i].from],w);
				v[y]=1;
			}
		}
		h++;
	}	
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read(),m=read();
	for (register int i=1;i<=m;i++)
	{
		g[i].x=read(),g[i].y=read(),g[i].z=read();
	}
	sort(g+1,g+m+1,cmp);
	for (register int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for (register int i=1;i<=m;i++)
	{
		int x=get(g[i].x);
		int y=get(g[i].y);
		if (x==y) continue;
		fa[x]=y;
		add(x,y,g[i].z);
		add(y,x,g[i].z);
	}
	bfs(1);
	for (register int i=2;i<=n;i++)
	{
		ans+=f[i];
	}
	write(ans);
	return 0;
}
