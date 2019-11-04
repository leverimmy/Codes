#include <cstdio>

using namespace std;

int t;
long long cnt=0;

long long _gcd(long long a,long long b)
{
	if(a<b)
	{
		long long t=a;
		a=b;
		b=t;
	}
	if(b==1)
		return a-1;
	if(a==b)
		return 0;
	if(b==0)
		return -1;
	else
		return _gcd(b,a%b)+a/b;
}

int main()
{
	//freopen("sword.in","r",stdin);
	//freopen("sword.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		long long a,b;
		a=b=0;
		scanf("%lld %lld",&a,&b);
		printf("%lld\n",_gcd(a,b));
	}
	return 0;
}