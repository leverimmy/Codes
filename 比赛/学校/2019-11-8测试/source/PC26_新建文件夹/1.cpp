#include <bits/stdc++.h>
using namespace std;
long long Qpow(long long a,long long b,long long p)
{
	long long res=1;
	while(b)
	{
		if(b&1)
		{
			res*=a;
			res%=p;
			b--;
		}
		else
		{
			a*=a;
			a%=p;
			b>>=1;
		}
	}
	return res;
}
int main()
{
	freopen("1.in","w",stdin);
	freopen("1.out","r",stdout);
	long long a,b,c;
	while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
	{
		printf("%lld\n",Qpow(a,b,c));
	}
	return 0;
}
