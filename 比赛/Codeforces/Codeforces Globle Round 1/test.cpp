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
	for(int i = 1; i < T; i++)
		printf("%d ans:%d\n", i, gcd(i ^ T, i & T));
	return 0;
}
