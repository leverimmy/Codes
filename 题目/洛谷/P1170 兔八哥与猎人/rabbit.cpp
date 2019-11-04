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

int n, a, b, c, d, deltax, deltay;

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
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a = read(), b = read();
		c = read(), d = read();
		deltax = abs(a - c);
		deltay = abs(b - d);
		if(gcd(deltax, deltay) == 1)
			puts("no");
		else
			puts("yes");
	}
	return 0;
}

