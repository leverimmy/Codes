#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <ctime>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 50010

using namespace std;

const double dk = 0.523;

ll n, k, m, ans;
ll used[maxn], yes[maxn], no[maxn];

struct node
{
	ll c, p;
} cow[maxn];

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a , struct node b)
{
	return a.p + a.c < b.p + b.c;
}

ll calc()
{
	ll res = 0, money = m;
	ll cur[maxn] = {0};
	for(register ll i = 1; i <= n; ++i)
	{
		if(used[i])
			cur[i] = cow[i].c;
		else
			cur[i] = cow[i].p;
	}
	sort(cur + 1, cur + n + 1);
	for(rgi i = 1; i <= n; ++i)
	{
		if(money >= cur[i])
		{
			money -= cur[i];
			res++;
		}
	}
	return res;
}

void SA()
{
	ll T = 5000;
	while(T > 1)
	{
		ll id_x = rand() % k + 1;
		ll id_y = rand() % (n - k) + 1;
		used[yes[id_x]] = 0;
		used[no[id_y]] = 1;
		swap(yes[id_x], no[id_y]);
		ll cur_ans = calc();
		ll delta = cur_ans - ans;
		if(delta > 0)
			ans = cur_ans;
		else if(2 * RAND_MAX * exp(-delta / T) < rand())
		{
			used[yes[id_x]] = 0;
			used[no[id_y]] = 1;
			swap(yes[id_x], no[id_y]);
		}
		T *= dk;
	}
}

int main()
{
	srand(20040301);
	n = read(), k = read(), m = read();
	for(register ll i = 1; i <= n; ++i)
	{
		cow[i].p = read();
		cow[i].c = read();
		if(i <= k)
		{
			used[i] = 1;
			yes[i] = i;
		}
		else
			no[i - k] = i;
	}
	sort(cow + 1, cow + n + 1, cmp);
	ans = calc();
	for(rgi i = 1; i <= 5; ++i)
		SA();
	printf("%lld", ans);
	return 0;
}
