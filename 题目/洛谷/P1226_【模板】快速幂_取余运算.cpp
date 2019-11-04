#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>

using namespace std;

long long b,p,k;

long long ksm(long long base,long long power,long long mod)
{
	long long r=1;
	while(power>0)
	{
		if(power&1)
			r=r*base%mod;
		base=base*base%mod;
		power>>=1;
	}
	return r;
}

int main()
{
	scanf("%lld %lld %lld",&b,&p,&k);
	if(p==0)
		printf("%lld^%lld mod %lld=%lld",b,p,k,1%k);
	else
		printf("%lld^%lld mod %lld=%lld",b,p,k,ksm(b,p,k));
	return 0;
}