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
#define maxn 20
#define maxm 20

using namespace std;

ll n, MOD;

struct matrix
{
	ll n, m;
	ll a[maxn][maxm];
	matrix()
	{
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

struct matrix mul(struct matrix A, struct matrix B)
{
	struct matrix RES;
	RES.n = A.n, RES.m = B.m;
	for(rgi i = 1; i <= A.n; ++i)
		for(rgi j = 1; j <= B.m; ++j)
			for(rgi k = 1; k <= A.m; ++k)
				RES.a[i][j] = (RES.a[i][j] + (A.a[i][k] * B.a[k][j]) % MOD) % MOD;
	return RES;
}

struct matrix ksm(struct matrix BASE, ll power)
{
	struct matrix res;
	res.n = BASE.n, res.m = BASE.m;
	res.init();
	while(power)
	{
		if(power & 1)
			res = mul(res, BASE);
		BASE = mul(BASE, BASE);
		power >>= 1;
	}
	return res;
}

ll f(ll x)
{
	struct matrix base, ans;
	base.n = base.m = 4;
	ans.n = 4, ans.m = 1;
	base.a[1][1] = base.a[1][2] = base.a[2][2] = base.a[2][3] = base.a[3][3] = base.a[3][4] = base.a[4][3] = 1;
	ans.a[2][1] = ans.a[3][1] = ans.a[4][1] = 1;
	struct matrix ANS = mul(ksm(base, x - 1), ans);
	return x * ANS.a[2][1] - ANS.a[1][1];
}

int main()
{
	n = read(), MOD = read();
	if(n == 1)
		puts("1");
	else
		printf("%lld", (f(n) + MOD) % MOD);
	return 0;
}

