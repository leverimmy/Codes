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
#define maxn 200010

using namespace std;

const ll inf = 0x3f3f3f3f3f3f3f3f;

ll n, m, s, cur = inf, ans = inf;
ll left, right, small = inf, big = -inf;
ll w[maxn], v[maxn], l[maxn], r[maxn];
ll pre_n[maxn], pre_v[maxn];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool check(ll W)
{
	ll y = 0;
	for(rgi i = 1; i <= n; ++i)
	{
		if(w[i] >= W)
		{
			pre_n[i] = pre_n[i - 1] + 1;
			pre_v[i] = pre_v[i - 1] + v[i];
		}
		else
		{
			pre_n[i] = pre_n[i - 1];
			pre_v[i] = pre_v[i - 1];
		}
	}
	for(rgi i = 1; i <= m; ++i)
		y += (pre_n[r[i]] - pre_n[l[i] - 1]) * (pre_v[r[i]] - pre_v[l[i] - 1]);
	cur = y > s ? y - s : s - y;
	if(y > s)
		return 1;
	else
		return 0;
}

int main()
{
	n = read(), m = read(), s = read();
	for(rgi i = 1; i <= n; ++i)
	{
		w[i] = read();
		v[i] = read();
		small = min(small, w[i]);
		big = max(big, w[i]);
	}
	for(rgi i = 1; i <= m; ++i)
	{
		l[i] = read();
		r[i] = read();
	}
	left = small - 1, right = big + 1;
	while(left <= right)
	{
		ll mid = (left + right) >> 1;
		if(check(mid))
			left = mid + 1;
		else
			right = mid - 1;
		if(cur < ans)
			ans = cur;
	}
	printf("%lld", ans);
	return 0;
}

