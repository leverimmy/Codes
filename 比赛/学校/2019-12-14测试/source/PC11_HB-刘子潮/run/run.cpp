#include<cstdio>
#include<cstring>
#define in inline
#define ri register int
#define rc register char
#define gc getchar
#define maxi(a,b) ((a)>(b)?(a):(b))
#define mini(a,b) ((a)<(b)?(a):(b))
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
int n,m,p;
int dis[N][N];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=n;++i)
	{
		for(register int j=1;j<=n;++j)
		{
			dis[i][j]=1073741824;
		}
	}
	for(register int i=1;i<=m;++i)
	{
		register int x=read(),y=read(),z=read();
		dis[x][y]=z,dis[y][x]=z,dis[i][i]=0;
	}
	for(register int k=1;k<=n;++k)
	{
		for(register int i=1;i<=n;++i)
		{
			for(register int j=1;j<=n;++j)
			{
				if(i!=j && i!=k && j!=k)
				{
					dis[i][j]=mini(dis[i][j],maxi(dis[i][k],dis[k][j]));
				}
			}
		}
	}
	p=read();
	for(register int i=1;i<=p;++i)
	{
		register int a=read(),b=read();
		printf("%d\n",dis[a][b]);
	}
	return 0;
}
