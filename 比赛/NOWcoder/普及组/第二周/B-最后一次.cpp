#include <cstdio>
#include <cmath>

using namespace std;

long long n;

int is_prime(long long t)
{
	if(t<2)
		return 0;
	if(t==2)
		return 1;
	for(long long i=2;i<=sqrt(n)+1;i++)
		if(t%i==0)
			return 0;
	return 1;
}

int main()
{
	scanf("%lld",&n);
	for(long long i=n;i>=1;i--)
		if(is_prime(i)==1)
		{
			printf("%lld",i);
			break;
		}
	return 0;
}