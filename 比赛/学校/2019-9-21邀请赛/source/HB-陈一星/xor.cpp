#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<cctype>
#define M 9010000
using namespace std;
const int inf=0x3f3f3f3f;
inline int read()
{
	int x=0,f=1;char s=getchar();
	while (!isdigit(s))
	{
		if(s=='-') f=-1;
		s=getchar();
	}
	while (isdigit(s))
	{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}

int t,n,m,g[50],fa[M],ccc,len;

inline void init()
{
	memset(g,0,sizeof(g));
	for (int i=1;i<=2*n;i++)
	{
		for (int j=0;j<=32;j++)
		{
			fa[(i-1)*32+j]=(i-1)*32+j;
		}
	}	
	ccc=1;
}

inline void get_split(int num)
{
	len=0;
	while (num!=0)
	{
		g[len++]=num&1;
		num>>=1;
	}
	len--;
}

inline int find(int a)
{
	if (fa[a]!=a)
		fa[a]=find(fa[a]);
	return fa[a];
}

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	t=read();
	while (t--)
	{
		n=read(),m=read();
		init();
		for (int i=1;i<=m;i++)
		{
			int x=read(),y=read(),k=read();
			get_split(k);
			if (!ccc)
				continue;
			for (int i=0;i<=len;i++)
			{
				if (g[i]==1)
				{
					int X=find((x-1)*32+i);
					int Y=find(y*32+i);
					int S=find((x-1+n)*32+i);
					int T=find((y+n)*32+i);
					if (X==Y||S==T)
					{
						printf("No\n");
						ccc=0;
						break;
					}
					fa[X]=T;
					fa[Y]=S;
				}
				else
				{
					int X=find((x-1)*32+i);
					int Y=find(y*32+i);
					int S=find((x-1+n)*32+i);
					int T=find((y+n)*32+i);
					if (S==Y||X==T)
					{
						printf("No\n");
						ccc=0;
						break;
					}
					fa[X]=Y;
					fa[S]=T;
				}
			}
		}
		if (ccc)
			printf("Yes\n");
	}
	return 0;
}
