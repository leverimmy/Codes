#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

int n, m, t, ans;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	n = read(), m = read();
	t = sqrt(n * m);
	for(rgi i = 1; i <= t; ++i)
	{
		if((n * m) % i == 0 && n * m / gcd(i, n * m / i) == m)
			ans++;
	}
	ans *= 2;
	printf("%d", ans);
	return 0;
}

