#include<cstdio>
#define maxn 100005
using namespace std;
inline int read()
{
	register char ch=getchar();
	register int x=0;
	while(ch<'0' || ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
int x[maxn],y[maxn];
int main()
{
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	register int n=read(),m=read(),s=0;
	for(register int i=0,a,b;i<m;++i)
	{
		a=read();
		b=read();
		++x[a];
		++y[b];
	}/*
	for(register int i=1;i<=n;++i)
	{
		if(x[i]==n)
		{
			for(register int i=1;i<=n;++i)
			{
				--y[i];
			}
		}
		else
		{
			break;
		}
	}
	for(register int i=n;i>0;--i)
	{
		if(x[i]==n)
		{
			for(register int i=1;i<=n;++i)
			{
				--y[i];
			}
		}
		else
		{
			break;
		}
	}
	for(register int i=1;i<=n;++i)
	{
		if(y[i]==n)
		{
			for(register int i=1;i<=n;++i)
			{
				--x[i];
			}
		}
		else
		{
			break;
		}
	}
	for(register int i=n;i>0;--i)
	{
		if(y[i]==n)
		{
			for(register int i=1;i<=n;++i)
			{
				--x[i];
			}
		}
		else
		{
			break;
		}
	}*/
	for(register int i=1;i<=n;++i)
	{
		if(!x[i])
		{
			++s;
		}
		if(!y[i])
		{
			++s;
		}
	}
	printf("%d",s);
	return 0;
}
