#include<cstdio>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define mod 1000000007ll
ll fastpow(ll x,int y)
{
	ll opt(1);
	while(y)
	{
		if(y&1)
			(opt*=x)%=mod;
		(x*=x)%=mod;
		y>>=1;
	}
	return opt;
}
ll inv(ll p)
{
	return fastpow(p,1000000005);
}
signed main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ll n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	ll p=n-k;
	ll q=m-1;
	ll r=p-q;
	if(r<0)
		return puts("0");
	if(!r)
		return puts("1");
	ll ans=1;
	for(int i=1;i<=p;i++)
		(ans*=i)%=mod;
	for(int i=1;i<=q;i++)
		(ans*=inv(i))%=mod;
	for(int i=1;i<=r;i++)
		(ans*=inv(i))%=mod;
	return!printf("%lld\n",ans);
}
