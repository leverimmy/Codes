#include<cstdio>
#define N 100005
#define ri register int
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
int p[N];
int main()
{
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	ri n=read(),f=read(),ans=0;
	for(ri i=1;i<=n;++i)
	{
		p[i]=read();
	}
	ri maxa=n-f-1;
	for(ri a=1,maxl;a<=maxa;++a)
	{
		maxl=(n-a-f+1)>>1;
		for(ri l=1;l<=maxl;++l)
		{
			register bool flag=true;
			for(ri i=a,j=a+l+f;i<a+l;++i,++j)
			{
				if(p[i]!=p[j])
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				++ans;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
