#include<cstdio>
inline int read()
{
	register int x=0;
	register char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+ch-'0',ch=getchar();
	}
	return x;
}
const int T=100005,mod=1000000007;
int t,k,l,r;
inline long long int ny(int x)
{
	if(x==1)
	{
		return 1;
	}
	register long long int mini=mod/x,sum=mini*x;
	while(true)
	{
		if(sum==1)
		{
			return mini;
		}
		sum+=((mod-sum)/x)*x+x,mini+=(mod-sum)/x+1,sum%=mod;
	}
}
inline long long int C(int x,int y)
{
	if(x>y || x<0 || y<0)
	{
		return 0;
	}
	if(x>y/2)
	{
		x=y-x;
	}
	register long long int ans=1;
	for(register int i=y;i>=y-x+1;--i)
	{
		ans*=i,ans%=mod;
	}
	for(register int i=x;i>=1;--i)
	{
		ans*=ny(i),ans%=mod;
	}
	return ans;
}
int main()
{
	freopen("pool.in","r",stdin);
	freopen("pool.out","w",stdout);
	t=read(),k=read();
	register long long int ans;
	register int x;
	for(register int i=1;i<=t;++i)
	{
		ans=0,l=read(),r=read();
		for(register int j=l;j<=r;++j)
		{
			x=((j+1)/(k+1));
			for(register int m=0;m<=x;++m)
			{
				ans+=C(m,j+1-m*k),ans%=mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
