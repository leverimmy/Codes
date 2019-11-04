#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <iostream>
#define ll long long
#define il inline
#define rgi register int
#define rgl register ll

using namespace std;

const ll N = 1000 + 10;

ll n, ans;
ll a[N], b[N];

il ll read()
{
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	for(rgl i = 1; i <= n; ++i)
		a[i] = read();
	for(rgl i = 1; i <= n; ++i)
		b[i] = read();
	sort(a + 1, a + n + 1, greater<ll>());
	sort(b + 1, b + n + 1, less<ll>());
	for(rgl i = 1; i <= n; ++i)
		ans += a[i] * b[i];
	printf("%lld", ans);
	return 0;
}

