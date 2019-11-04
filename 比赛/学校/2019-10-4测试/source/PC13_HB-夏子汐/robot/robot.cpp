#include<cstdio>
#define ri register int
#define N 50000
inline int read()
{
	ri x=0;
	register char ch=getchar();
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
int a[N],b[N],fa[N],fb[N];
int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout); 
	ri n=read(),m1=read(),m2=read();
	for(ri i=1;i<=n;++i)
	{
		b[i]=a[i]=read();
	}
	ri cost1=0,cost2=0;
	for(ri i=n-1;i;--i)
	{
		for(ri j=i+1;j<=n;++j)
		{
			if(a[i]==a[j])
			{
				fa[i]+=fa[j];
				break;
			}
			if(a[i]>a[j])
			{
				++fa[i];
			}
		}
	}
	a[0]=a[1];
	fa[0]=fa[1];
	for(ri i=1;i<=n;++i)
	{
		if(a[i]<a[i-1])
		{
			a[i]=a[i-1];
			fa[i]=fa[i-1]-1;
			cost1+=m1;
			continue;
		}
		if(fa[i]*m1>m2+fa[i-1]*m1)
		{
			a[i]=a[i-1];
			fa[i]=fa[i-1];
			cost1+=m2; 
		}
	}
	for(ri i=n-1;i;--i)
	{
		for(ri j=i+1;j<=n;++j)
		{
			if(b[i]==b[j])
			{
				fb[i]+=fb[j];
				break;
			}
			if(b[i]<b[j])
			{
				++fb[i];
			}
		}
	}
	b[0]=b[1];
	fb[0]=fb[1];
	for(ri i=1;i<=n;++i)
	{
		if(b[i]>b[i-1])
		{
			b[i]=b[i-1];
			fb[i]=fb[i-1]-1;
			cost2+=m2;
			continue;
		}
		if(fb[i]*m2>m1+fb[i-1]*m2)
		{
			b[i]=b[i-1];
			fb[i]=fb[i-1];
			cost2+=m1; 
		}
	}
	printf("%d",cost1<cost2?cost1:cost2);
	return 0;
}
