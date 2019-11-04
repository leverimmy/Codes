#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#include <ctime>
#define rgi register int
#define il inline
#define ll long long
#define maxn 100010

using namespace std;

const double dk = 0.997;

ll n, k, tot, ans, T, arr;
bool used[maxn];
ll e[maxn], no[maxn];

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll calc()
{
	ll res = 0;
	for(register ll i = 1; i <= n; ++i)
		if(used[i])
			res += e[i];
	return res;
}

void modify(ll cur)
{
	for(rgi i = cur; i <= n; ++i)
	{
		if((i - cur + 1) % (k + 1))
			used[i] = 1;
		else
			used[i] = 0;
	}
	for(rgi i = cur - 1; i >= 1; --i)
	{
		if((cur - 1 - i) % (k + 1))
			used[i] = 1;
		else
			used[i] = 0;
	}
}

void SA()
{
	T = 5000;
	while(T > 1e-10)
	{
		ll cur = rand() % n + 1;
		modify(cur);
		ll cur_ans = calc();
		ll delta = cur_ans - ans;
		if(delta > 0)
		{
			arr = cur;
			ans = cur_ans;
		}
		else if(RAND_MAX * exp(-delta / T) <= rand())
		{
			modify(arr);
			ans = cur_ans;
		}
		T *= dk;
	}
}

int main()
{
	srand((unsigned)time(0));
	n = read(), k = read();
	for(register ll i = 1; i <= n; ++i)
		e[i] = read();
	for(rgi i = n; i >= 1; --i)
		if((n - i + 1) % (k + 1))
		{
			used[i] = 1;
			arr = i;
		}
	ans = calc();
	SA();
	printf("%lld", ans);
	return 0;
}

