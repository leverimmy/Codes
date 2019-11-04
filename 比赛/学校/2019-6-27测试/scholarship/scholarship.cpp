#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register long long
#define il inline
#define ll long long
#define maxn 1000010

using namespace std;

ll n, p;
ll ans;
ll a[maxn], s[maxn], c[maxn];

vector <ll> vec;

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void add(ll x)
{
	for(; x < maxn; x += x & -x)
		c[x]++;
}

ll query(ll x)
{
	ll res = 0;
	for(; x; x -= x & -x)
		res += c[x];
	return res;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	p = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] -= p;
	for(rgi i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	for(rgi i = 0; i <= n; ++i)
		vec.push_back(s[i]);
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	for(rgi i = 0; i <= n; ++i)
		s[i] = lower_bound(vec.begin(), vec.end(), s[i]) - vec.begin() + 1;
	for(rgi i = 0; i <= n; ++i)
	{
		ans += query(s[i]);
		add(s[i]);
	}
	printf("%lld", ans);
	return 0;
}

