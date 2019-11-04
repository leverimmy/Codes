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
#define maxn 50010

using namespace std;

ll n, m, first, last;
ll a[maxn];

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read(), m = read();
	first = 1, last = n;
	for(register ll i = 1; i <= n; ++i)
	{
		if(m <= (n - i) * (n - i - 1) / 2)
			a[first++] = i;
		else
		{
			a[last--] = i;
			m = m - (last - first + 1);
		}
	}
	for(register ll i = 1; i <= n; ++i)
		printf("%lld ", a[i]);
	return 0;
}

