#include<cstdio>
#define inf 100000000
#define ri register int
#define f1(i,j) f1[i][j]
#define f2(i,j) f2[i][j]
#define a(i,j) a[i][j]
using namespace std;
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
inline int min(ri x,ri y)
{
	return x<y?x:y;
}
int f1(1005,1005),f2(1005,1005);
int a(1005,1005);
int main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	ri n=read(),m=read();
	for(ri i=1;i<=n;++i)
	{
		for(ri j=1;j<=m;++j)
		{
			a(i,j)=read();
		}
	}
	f1(0,1)=a(1,1);
	for(ri i=1;i<=n;++i)
	{
		for(ri j=1;j<=m;++j)
		{
			if(i==1)
			{
				f1(i,j)=f1(i,j-1)+a(i,j+1)+a(i+1,j);
				f2(i,j)=inf;
				continue;
			}
			if(j==1)
			{
				f1(i,j)=inf;
				f2(i,j)=f2(i-1,j)+a(i,j+1)+a(i+1,j);
				continue;
			}
			f1(i,j)=min(f1(i,j-1)+a(i,j+1)+a(i+1,j)+a[i-1][j],
						f2(i,j-1)+a(i,j+1)+a(i+1,j));
			f2(i,j)=min(f2(i-1,j)+a(i,j+1)+a(i+1,j)+a[i][j-1],
						f1(i-1,j)+a(i,j+1)+a(i+1,j));
		}
	}
	printf("%d",min(f1(n,m),f2(n,m)));
	return 0;
}
