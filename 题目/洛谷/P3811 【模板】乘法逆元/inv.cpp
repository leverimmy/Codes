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
#define maxn 3000010

using namespace std;

ll n, p;
ll inv[maxn] = {0, 1};

il int read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read(), p = read();
	for(register ll i = 2; i <= n; ++i)
	{
		inv[i] = -(p / i) * inv[p % i];
		inv[i] = (inv[i] % p + p) % p;
	}
	for(register ll i = 1; i <= n; ++i)
		printf("%lld\n", inv[i]);
	return 0;
}

