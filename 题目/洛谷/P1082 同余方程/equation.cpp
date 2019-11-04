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

int a, b, x, y;

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

void exgcd(int a, int b)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b);
	ll tx = x;
	x = y;
	y = tx - a / b * y;
}

int main()
{
	a = read();
	b = read();
	exgcd(a, b);
	while(x < 0)
		x += b;
	x %= b;
	printf("%d", x);
	return 0;
}

