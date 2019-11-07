#include <bits/stdc++.h>
using namespace std;
long long f[100000];
int main()
{
	freopen("19.in","r",stdin);
	freopen("19.out","w",stdout);
	long long S,T;
	scanf("%lld%lld",&S,&T);
	long long a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	long long MOD=a*b*c*d;
	if(1%MOD)
	{
		printf("1 2 ");
	}
	f[1]=1;
	f[2]=1;
	for(long long i=3;i<=T;i++)
	{
		f[i]=f[i-1]+f[i-2];
		f[i]%=MOD;
		if((f[i]%a)&&(f[i]%b)&&(f[i]%c)&&(f[i]%d))
		{
			printf("%lld ",i);
		}
	}
	return 0;
}

