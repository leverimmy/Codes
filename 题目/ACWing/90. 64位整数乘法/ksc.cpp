#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define il inline
#define ll long long
#define rgi register ll

using namespace std;

ll a, b, p;

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll ksc(ll a, ll b, ll mod)
{
	ll res = 0;
	while(b)
	{
		if(b & 1)
			res = (res + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return res;
}

int main()
{
	a = read(), b = read(), p = read();
	printf("%lld", ksc(a, b, p));
	return 0;
}

