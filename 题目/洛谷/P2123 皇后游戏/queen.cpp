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
#define maxn 20010

using namespace std;

ll T;

struct people
{
	ll a, b, d;
} p[maxn];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct people a, struct people b)
{
	if(a.d != b.d)
		return a.d < b.d;
	if(a.d <= 0)
		return a.a < b.a;
	else
		return a.b > b.b;
}

int main()
{
	T = read();
	for(; T; --T)
	{
		ll n = read();
		ll sum = 0, ans = 0;
		for(rgi i = 1; i <= n; ++i)
		{
			p[i].a = read();
			p[i].b = read();
			if(p[i].a - p[i].b < 0)
				p[i].d = -1;
			else if(p[i].a - p[i].b == 0)
				p[i].d = 0;
			else if(p[i].a - p[i].b > 0)
				p[i].d = 1;
		}
		sort(p + 1, p + n + 1, cmp);
		for(rgi i = 1; i <= n; ++i)
		{
			sum += p[i].a;
			ans = max(ans, sum) + p[i].b;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

