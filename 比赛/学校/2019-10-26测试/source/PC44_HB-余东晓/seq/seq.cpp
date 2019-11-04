#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
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
ll gcd(ll x,ll y)
{
	if(!y)
		return 1ll;
	return x/y+gcd(y,x%y);
}
signed main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	ll x1,x2;
	scanf("%lld%lld",&x1,&x2);
	return!printf("%lld\n",gcd(x1,x2));
}
