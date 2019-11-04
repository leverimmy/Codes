#include<cstdio>
#define ri register ll
#define ll long long
#define mod 1000000007
using namespace std;
inline ll read()
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
inline ll qmi(ri x,ri pow)
{
	ri a=x,ans=1;
	for(ri i=pow;i;i>>=1)
	{
		if(i&1)
		{
			ans*=a;
			ans%=mod;
		}
		a*=a;
		a%=mod;
	}
	return ans;
}
inline ll c(ri x,ri y)
{
	if(!x)
	{
		return 1;
	}
	if(x==1)
	{
		return y;
	}
	if((x<<1)>y)
	{
		x=y-x;
	}
	ri ans=1;
	for(ri i=y-x+1;i<=y;++i)
	{
		ans*=i;
		ans%=mod;
	}
	for(ri i=2;i<=x;++i)
	{
		ans*=qmi(i,1000000005);
		ans%=mod;
	}
	return ans;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ri n=read(),m=read(),k=read();
	printf("%lld",c(m-1,n-k));
	return 0;
}
