#include<cstdio>
#include<cstring>
#include<iostream>
#define in inline
#define ri register int
#define rc register char
#define gc getchar
#define minl(a,b) ((a)<(b)?(a):(b))
#define N 100005
in int read()
{
	ri x=0;
	rc ch=gc();
	while(ch<'0' || ch>'9')
	{
		ch=gc();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0',ch=gc();
	}
	return x;
}
int n,m;
char str[N];
int lcp[N];
int main()
{
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	n=read(),m=read();
	char ch=getchar();
	while(ch<'a' || ch>'z')
	{
		ch=getchar();
	}
	for(register int i=1;i<=n;++i)
	{
		str[i]=ch,ch=gc();
	}
	for(register int i=1;i<=m;++i)
	{
		register int a=read(),b=read();
		register bool flag=false;
		for(register int i=0;i<=minl(n-a,n-b);++i)
		{
			if(str[a+i]<str[b+i])
			{
				puts("0"),flag=true;
				break;
			}
			else if(str[a+i]>str[b+i])
			{
				puts("1"),flag=true;
				break;
			}
		}
		if(flag)
		{
			continue;
		}
		else
		{
			if(a<=b)
			{
				puts("1");
			}
			else
			{
				puts("0");
			}
		}
	}
	return 0;
}
