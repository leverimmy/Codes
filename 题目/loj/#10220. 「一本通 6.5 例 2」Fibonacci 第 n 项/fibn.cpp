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
#define maxn 110
#define maxm 110

using namespace std;

ll n, mod;

struct matrix
{
	ll n, m;
	ll a[maxn][maxm];
	matrix()
	{
		n = m = 0;
		for(rgi i = 0; i < maxn; ++i)
			for(rgi j = 0; j < maxm; ++j)
				a[i][j] = 0;
	}
	void init()
	{
		for(rgi i = 0; i < maxn; ++i)
			a[i][i] = 1;
	}
};

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct matrix mul(struct matrix a, struct matrix b)
{
	struct matrix ans;
	ans.n = a.n, ans.m = b.m;
	for(rgi i = 1; i <= a.n; ++i)
		for(rgi j = 1; j <= b.m; ++j)
			for(rgi k = 1; k <= a.m; ++k)
				ans.a[i][j] = (ans.a[i][j] + (a.a[i][k] * b.a[k][j]) % mod) % mod;
	return ans;
}

struct matrix ksm(struct matrix base, ll power)
{
	struct matrix res;
	res.n = base.n, res.m = base.m;
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

ll fib(ll x)
{
	struct matrix ans, cur;
	ans.n = ans.m = 2;
	cur.n = 1, cur.m = 2;
	ans.a[1][1] = ans.a[1][2] = ans.a[2][1] = 1;
	cur.a[1][1] = cur.a[1][2] = 1;
	struct matrix ccc = ksm(ans, x - 2);
	return mul(ccc, cur).a[1][1];
}

int main()
{
	n = read(), mod = read();
	if(n <= 2)
		printf("1");
	else
		printf("%lld", fib(n + 1));
	return 0;
}

