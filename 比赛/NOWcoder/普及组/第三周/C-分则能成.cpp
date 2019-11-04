#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

long long n,k,sum;

int main()
{
	scanf("%lld %lld",&n,&k);
	long long d=k+1;
	for(long long i=1;i<=k;i++)
	{
		sum+=(n/d)*(n-n/d);
		n=n-n/d;
		d--;
	}
	printf("%lld",sum);
	return 0;
}