#include<cstdio>
#define in inline
#define ri register int
#define rc register char
#define gc getchar
#define N 15
#define S 10000
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
int n,s,a[N<<1];
bool f[N<<1][S],ans;
void print()
{
//	for(int i=1;i<=2*n;++i)
//	{
//		for(int j=1;j<=s;++j)
//		{
//			printf("%d ",f[i][j]);
//		}
//		puts("");
//	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	while(true)
	{
		ans=false;
		n=read();
		if(n==0)
		{
			break;
		}
		s=read();
		for(register int i=1;i<=2*n;++i)
		{
			a[i]=read();
		}
		for(register int i=1;i<=2*n;++i)
		{
			for(register int j=1;j<=s;++j)
			{
				f[i][j]=false;
			}
		}
		for(register int i=1;i<=n;++i)
		{
			f[2*i-1][1]=true;
		}
		print();
//		while(ans==false)
		{
		for(register int i=n-2;i>=0;--i)
		{
			if(a[2*i+2]<=a[2*i+3])
			{
				for(register int j=1;j<=s;++j)
				{
					for(register int k=1+a[2*i+1];k<=1+a[2*i+2];++k)
					{
						if(k<=j)
						{
							f[2*i+1][j]|=f[2*i+2][j-k];
						}
					}
				}
			}
		}
		print();
		for(register int i=1;i<=a[1];++i)
		{
			ans|=f[1][s-i];
		}
		}
		printf("%d\n",ans);
	}
	return 0;
}
