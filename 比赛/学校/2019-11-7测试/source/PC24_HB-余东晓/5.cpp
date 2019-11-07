#include<cstdio>
#include<cstring>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
bool isprime(ll x)
{
	int g=x%10ll;
	if(x>10&&g!=1&&g!=3&&g!=7&&g!=9)
		return 0;
	int p=std::sqrt(x);
	for(int i=2;i<=p;i++)
		if(x%(ll)p==0ll)
			return 0;
	return 1;
}
signed main()
{
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	while(!isprime(n+1ll))
		n++;
	return!printf("%lld\n",n+1ll);
}
