#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int T;

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		int num, maxn = -9999;
		scanf("%d", &num);
		for(int i = 1; i < num; i++)
			maxn = gcd(i ^ num, i & num) > maxn ? gcd(i ^ num, i & num) : maxn;
		printf("%d\n",maxn);
	}
	return 0;
}
