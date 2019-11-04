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
#define maxn 50
#define inf 0x3f3f3f3f

using namespace std;

ll n, minn = inf, sum, left, right, ans;
ll a[maxn];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll check(ll x)
{
	ll res = 0;
	for(rgi i = 1; i <= n; ++i)
		if(a[i] < x)
			res += x - a[i];
	return res <= min(x, a[0]);
}

int main()
{
	n = read();
	for(rgi i = 0; i <= n; ++i)
	{
		a[i] = read();
		minn = min(a[i], minn);
		sum += a[i];
	}
	right = sum;
	left = minn;
	while(left <= right)
	{
		ll mid = (left + right) >> 1;
		if(check(mid))
		{
			left = mid + 1;
			ans = mid;
		}
		else
			right = mid - 1;
	}
	printf("%lld", ans);
	return 0;
}

