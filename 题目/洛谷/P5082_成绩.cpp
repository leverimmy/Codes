#include <cstdio>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int n;
ll sum, tot;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)	putchar('-'), x = -x;
	while(x >= 10)	write(x / 10);
	putchar(x % 10 + 48);
}

int main()
{
	scanf("%d", &n);
	for(rgi i = 1; i <= n; ++i)
	{
		ll t;
		scanf("%lld", &t);
		sum += t;
	}
	for(rgi i = 1; i <= n; ++i)
	{
		ll t;
		scanf("%lld", &t);
		tot += t;
	}
	printf("%.6lf", (3 * sum - 2 * tot) * 1.0 / (sum - tot));
	return 0;
}

