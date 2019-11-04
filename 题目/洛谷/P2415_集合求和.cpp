#include <cstdio>

using namespace std;

long long n,cnt,sum;

long long pow2(int power)
{
	if(power==0)
		return 1;
	else
		return 2*pow2(power-1);
}

int main()
{
	while(scanf("%lld",&n)!=EOF)
	{
		cnt++;
		sum+=n;
	}
	printf("%lld",sum*pow2(cnt-1));
	return 0;
}