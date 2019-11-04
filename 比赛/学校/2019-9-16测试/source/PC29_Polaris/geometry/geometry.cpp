#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cctype>
#include<stack>
using namespace std;
const int M=101000;
const int inf=0x3f3f3f3f;
int fa[M],n,m,q,siz[M],vis[M],ans;
inline int read()
{
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)) {if (s=='-') f=-1; s=getchar();}
	while (isdigit(s)) {x=(x<<1)+(x<<3)+(s^48); s=getchar();}
	return x*f;
}
inline int find(int a)
{
	if (fa[a]!=a)
	{
		fa[a]=find(fa[a]);
	}
	return fa[a];
}
int main()
{
	freopen("geometry.in","r",stdin);
	freopen("geometry.out","w",stdout);
	n=read();m=read();q=read();
	for (int i=1;i<=n;i++)
		fa[i]=i,fa[i+n]=i+n,siz[i]=1;
	for (int i=1;i<=m;i++)
	{
		int u=read();
		char s[10];
		scanf("%s",s);
		int v=read();
		if (s[0]=='p')
		{
			int x=find(u);
			int y=find(v);
			int s=find(y+n);
			int t=find(x+n);
			if (x==s||y==t)
			{
				printf("There must be something wrong!");
				return 0;
			}
			if (x==y&&s==t)
			{
				continue;
			}
			fa[x]=y;
			siz[y]+=siz[x];
			fa[s]=t;
			siz[t]+=siz[s];
		}
		if (s[0]=='v')
		{
			int x=find(u);
			int y=find(v);
			int s=find(y+n);
			int t=find(x+n);
			if (x==y||s==t)
			{
				printf("There must be something wrong!");
				return 0;
			}
			if (x==s&&y==t)
			{
				continue;
			}
			fa[s]=x;
			siz[x]+=siz[s];
			fa[t]=y;
			siz[y]+=siz[t];
		}
	}
	for (int i=1;i<=n;i++)
	{
		int x=find(i);
		if (!vis[x])
		{
			ans+=((siz[x]==1)?0:siz[x]*(siz[x]-1)/2);
			vis[x]=1;
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=q;i++)
	{
		int u=read(),v=read();
		int x=find(u);
		int y=find(v);
		int t=find(u+n);
		if (x==y)
		{
			printf("Parallel\n");
		}
		else if (y==t)
		{
			printf("Vertical\n");
		}
		else
		{
			printf("No idea\n");
		}
	}
	return 0;
}
