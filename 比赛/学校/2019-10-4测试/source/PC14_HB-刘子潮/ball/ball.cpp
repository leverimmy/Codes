#include<cstdio>
#define in inline
#define ri register int
#define ll long long int
#define rl register long long int
#define rc register char
#define mod 1000000007
in int read()
{
	ri x=0,p=1;
	rc ch=getchar();
	while(ch<'0' || ch>'9')
	{
		ch=getchar();
		if(ch=='-')
		{
			p=-1;
		}
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	}
	return x*p;
}
int n,m,k;
in ll ny(int x)
{
	if(x==1)
	{
		return 1;
	}
	rl ans=mod/x,y=(x*ans)%mod;
	while(y!=1)
	{
		ans+=(mod-y)/x+1,y=(x*ans)%mod;
	}
	return ans;
}
in int C(int x,int y)
{
	if((x<<1)>y)
	{
		x=y-x;
	}
	rl ans=1;
	for(ri i=y-x+1;i<=y;++i)
	{
		ans*=i,ans%=mod;
	}
	for(ri i=1;i<=x;++i)
	{
		ans*=ny(i),ans%=mod;
	}
	return ans;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read(),k=read();
	printf("%d\n",C(m-1,n-k));
	return 0;
}
