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
#define maxn 20010

using namespace std;

const double dk = 0.993;

ll n, ans, T, a = 1, b = 2, best = 2147483647;
ll w[maxn], d[maxn], sum_w[maxn], sum_d[maxn], k;

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll calc(ll x, ll y)
{
	if(x > y)
		swap(x, y);
	ll res =
	    sum_d[x] * sum_w[x]
	    + sum_d[y] * (sum_w[y] - sum_w[x])
	    + sum_d[n + 1] * (sum_w[n] - sum_w[y])
	    - k;
	return res;
}

void SA()
{
	T = 5000;
	while(T > 1e-10)
	{
		ll cur_a = rand() % n + 1;
		ll cur_b = rand() % n + 1;
		while(cur_a == cur_b)
			cur_b = rand() % n + 1;
		ll cur_ans = calc(cur_a, cur_b);
		ll delta = cur_ans - ans;
		if(delta < 0)
		{
			a = cur_a;
			b = cur_b;
			ans = cur_ans;
		}
		else if(RAND_MAX * exp(-delta / T) <= rand())
		{
			a = cur_a;
			b = cur_b;
			ans = cur_ans;
		}
		if(ans < best)
			best = ans;
		T *= dk;
	}
}

int main()
{
	srand(19260817);
	n = read();
	for(register ll i = 1; i <= n; ++i)
	{
		w[i] = read();
		d[i] = read();
		sum_w[i] = sum_w[i - 1] + w[i];
		sum_d[i + 1] = sum_d[i] + d[i];
		k += w[i] * sum_d[i];
	}//prework
	a = 1, b = 2;
	best = ans = calc(a, b);
	for(register ll i = 1; i <= 10000; ++i)
		SA();
	printf("%lld", best);
	return 0;
}

