#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline
#define int ll

using namespace std;

const int mod = 1e4 + 7;
const int K = 1e4 + 10;

int a, b, k, n, m, ans1, ans2;
int c[K][K];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int ksm(int base, int power)
{
	int res = 1 % mod;
	while(power)
	{
		if(power & 1)
			res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}

signed main()
{
	a = read(), b = read(), k = read(), n = read(), m = read();
	ans1 = ksm(a, n), ans2 = ksm(b, m);
	for(rgi i = 1; i <= k + 1; ++i)	c[i][1] = c[i][i] = 1;
	for(rgi i = 2; i <= k + 1; ++i)
		for(rgi j = 2; j <= i - 1; ++j)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j] % mod;
	/*for(rgi i = 1; i <= k + 1; ++i)
	{
		for(rgi j = 1; j <= i; ++j)
			printf("c[%d][%d] = %d ", i, j, c[i][j]);
		puts("");
	}*/
//	printf("%lld %lld %lld\n", ans1, ans2, c[k + 1][n + 1]);
	printf("%lld", ans1 * ans2 * c[k + 1][n + 1] % mod);
	return 0;
}

