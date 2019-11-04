#include<cstdio>
#include<cstring>
#define mini(a,b) ((a)<(b)?(a):(b))
#define N 1005
inline int read()
{
	register int x=0,p=1;
	register char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		{
			p=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	}
	return x*p;
}
int n,m,f[N][N],a[N][N];
int main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			a[i][j]=read();
		}
	}
	f[0][0]=a[1][1];
	for(register int i=1;i<=n;++i)
	{
		f[i][0]=a[i-1][1]+a[i][1]+a[i+1][1];
	}
	for(register int i=1;i<=m;i++)
	{
		f[0][i]=a[1][i-1]+a[1][i]+a[1][i+1];
	}
	f[1][1]=a[2][1]+a[1][2]+a[2][2];
	for(register int i=2;i<=n;++i)
	{
		f[i][1]=f[i-1][1]+a[i+1][1]+a[i+1][2];
	}
	for(register int i=1;i<=m;++i)
	{
		f[1][i]=f[1][i-1]+a[1][i+1]+a[2][i+1];
	}
	for(register int i=2;i<=n;++i)
	{
		for(register int j=2;j<=m;++j)
		{
			f[i][j]=mini(f[i-1][j]+a[i+1][j-1]+a[i+1][j]+a[i+1][j+1],f[i][j-1]+a[i-1][j+1]+a[i][j+1]+a[i+1][j+1]);
		}
	}
	printf("%d",f[n][m]);
	return 0;
}
