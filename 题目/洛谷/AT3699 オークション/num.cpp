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

ll x, k, cur;

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll _pow(int base, int p)
{
	ll res = 1;
	while(p--)
		res *= base;
	return res;
}

int main()
{
	x = read(), k = read();
	cur = _pow(10, k);
	for(register ll i = x / cur;; ++i)
	{
		if(i * cur > x)
		{
			printf("%lld", i * cur);
			break;
		}
	}
	return 0;
}

