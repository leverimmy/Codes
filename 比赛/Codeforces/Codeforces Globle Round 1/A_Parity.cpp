#include <cstdio>

using namespace std;

int a, b, k;
long long ans = 0;

long long ksm(long long base, long long power, long long mod)
{
	long long r = 1;
	while(power > 0)
	{
		if(power & 1)
			r = r * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return r;
}

int main()
{
	scanf("%d %d", &b, &k);
	for(int i = 1; i <= k; i++)
	{
		scanf("%d", &a);
		ans = ans + a * ksm(b, k - i, 2);
	}
	if(ans & 1)
		printf("odd");
	else
		printf("even");
	return 0;
}
