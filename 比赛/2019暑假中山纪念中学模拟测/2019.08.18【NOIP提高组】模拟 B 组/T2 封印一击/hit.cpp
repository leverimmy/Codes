#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
#define rgi register ll
#define il inline

using namespace std;

const ll N = 100000 + 10;

ll n, L, R, ans;

struct node
{
	ll l, r;
} p[N];

il ll read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a, struct node b)
{
	return a.r < b.r;
}

ll calc(ll x)
{
	ll res = 0;
	for(rgi i = 1; i <= n; ++i)
	{
		if(x < p[i].l)
			res += p[i].l;
		else if(x > p[i].r)
			continue;
		else
			res += x;
	}
	return res;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		p[i].l = read();
		p[i].r = read();
	}
	sort(p + 1, p + n + 1, cmp);
	L = 1, R = n;
	ans = calc(p[1].r);
	while(L <= R)
	{
//		printf("%lld %lld\n", L, R);
		ll mid = L + R + 1 >> 1;
		ll cur_ans = calc(p[mid].r);
		if(cur_ans > ans)
		{
			L = mid;
			ans = cur_ans;
		}
		else
			R = mid - 1;
	}
	printf("%lld %lld", p[L].r, ans);
	return 0;
}
/*
5
1 10
2 9
3 8
4 7
5 6

3
1 2
8 11
9 12

*/

