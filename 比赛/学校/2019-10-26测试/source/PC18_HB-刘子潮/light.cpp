#include<cstdio>
#define maxi(a,b) ((a)>(b)?(a):(b))
#define ri register int
#define rc register char
#define in inline
#define gc getchar
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
int n,m,a[N],l,r,p,v,ans;
int main()
{
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	n=read(),m=read();
	for(ri i=1;i<=n;++i)
	{
		a[i]=read();
	}
	for(ri i=1;i<=m;++i)
	{
		l=read(),r=read(),p=read(),v=read(),ans=0;
		for(ri j=l;j<=r;++j)
		{
			if(a[j]%p==v)
			{
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
