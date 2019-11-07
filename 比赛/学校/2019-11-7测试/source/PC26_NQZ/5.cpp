#include <bits/stdc++.h>
using namespace std;
bool flag;
bool isprime(long long x)
{
	for(long long i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	long long now;
	scanf("%lld",&now);
	while(1)
	{
		now++;
		if(isprime(now))
		{
			printf("%lld",now);
			return 0;
		}
	}
	return 0;
}

