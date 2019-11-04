#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define il inline
#define ll long long
#define rgi ll
#define MOD 10007
#define maxn 100010 << 1

using namespace std;

ll n, m;

struct matrix
{
	ll a[20][20];
	matrix()
	{
		for(rgi i = 0; i < 20; ++i)
			for(rgi j = 0; j < 20; ++j)
				a[i][j] = 0;
	}
	void init()
	{
		for(rgi i = 0; i < 20; ++i)
			a[i][i] = 1;
	}
} ans;

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void prework(ll x)
{
	for(rgi i = 1; i <= x; ++i)
		ans.a[i][1] = (1 << i - 1);
}

struct matrix mul(struct matrix a, struct matrix b)
{
	struct matrix res;
	for(rgi i = 1; i <= m; ++i)
		for(rgi j = 1; j <= m; ++j)
			for(rgi k = 1; k <= m; ++k)
				res.a[i][j] = (res.a[i][j] + (a.a[i][k] * b.a[k][j]) % MOD) % MOD;
	return res;
}

struct matrix ksm(struct matrix base, ll power)
{
	struct matrix res;
	res.init();
	while(power)
	{
		if(power & 1)
			res = mul(res, base);
		base = mul(base, base);
		power >>= 1;
	}
	return res;
}

ll f(ll x)
{
	struct matrix cur;
	for(rgi i = 1; i <= m; ++i)
	{
		if(i == 1)
		{
			for(rgi j = 1; j <= m; ++j)
				cur.a[i][j] = 1;
		}
		else
			cur.a[i][i - 1] = 1;
	}
	struct matrix ccc = ksm(cur, x - m);
	return mul(ans, ccc).a[1][1];
}

int main()
{
	n = read(), m = read();
	ans.init();
	prework(m);
	/*for(rgi i = 1; i <= n; ++i)
	{
		if(i <= m)
			printf("%lld ", ans.a[i][1]);
		else
			printf("%lld ", f(i + m));
	}*/
	if(n <= m)
		printf("%lld", ans.a[n][1] % MOD);
	else
		printf("%lld", f(n + m) % MOD);
	return 0;
}

