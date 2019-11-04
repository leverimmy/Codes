#include <cstdio>
#include <cstring>
//#include <cmath>
#define rgi register int
#define il inline
#define ll long long
#define c 2009

using namespace std;

ll s = 0, t = 1, n, p;

ll pow(int base, int power)
{
	ll ans = 1;
	for(int i = 1; i <= power; i++)
		ans *= base % c;
	return ans % c;
}

int main()
{
	scanf("%d %d", &n, &p);
	for(int i = 1; i <= n; i++)
	{
		t = pow(p, i) % c;
		s = (s + i * t) % c;
		//for(int j = 1; j <= i; j++)
		//	s = (s + t) % c;
	}
	printf("%lld\n", s);
	return 0;
}

