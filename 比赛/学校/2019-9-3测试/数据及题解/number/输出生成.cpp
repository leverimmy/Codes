#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
int T;
ll n,ans;
ll Calc(ll x)
{
	return (2ll*x+1)*(x+1ll)*x/6ll;
}
ll calc(ll x)
{
	return (x+1ll)*x/2ll;
}
bool Check(ll x)
{
	return Calc(x)<=n;
}
ll F(ll x)
{
	if(!n)return 0;
	if((x+1ll)*x/2ll>=n)
	{	
		ll l=1,r=x,mid;
		while(l<r)
		{
			mid=(l+r)/2ll;
			if((mid+1ll)*mid/2ll>=n)r=mid;
			else l=mid+1;
		}
		return l;
	}
	else
	{
		ll l=0,r=x-1,mid;
		while(l<r)
		{
			mid=(l+r)/2ll;
			if(1ll*x*x-calc(mid)>=n)l=mid+1;
			else r=mid;
		}
		l--;
		return 2*x-l-1;
	}
}
int main()
{	
	freopen("number10.in","r",stdin);
	freopen("number10.out","w",stdout);
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%lld",&n);
		ll l=1,r=1500000,mid;
		while(l<r)
		{
			mid=(l+r)/2;
			if(Check(mid))l=mid+1;
			else r=mid;
		}
		n-=Calc(l-1);
		ans=(l-1ll)*(l-1ll)+F(l);
		printf("%lld\n",ans);
	}
	return 0;
}
