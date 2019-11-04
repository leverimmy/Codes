#include <cstdio>
#define ll long long

using namespace std;

ll l,r;

ll getsum(ll x)
{
	ll ans=0,i;
	for(i=1;i*i<=x;i++)
	{
		ans+=i*i*i;
		x-=i*i;
	}
	return ans+i*x;
}

int main()
{
	scanf("%lld %lld",&l,&r);
	printf("%lld",getsum(r)-getsum(l-1));
	return 0;
}