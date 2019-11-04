#include <cstdio>
#include <cstdlib>
#include <cstring>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int n, m, p;
double a, b, s;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	scanf("%d %d %d", &n, &m, &p);
	s = p * m / 2.0;
	b = gcd(n, m) + gcd(abs(p - n), m) + p;
	a = s - b / 2.0 + 1;
	printf("%.0f", a);
	return 0;
}

