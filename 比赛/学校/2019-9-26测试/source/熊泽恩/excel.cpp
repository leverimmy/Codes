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

using namespace std;

const int oo = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int r, c, minT, maxT;
ll ans;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
//	freopen("excel.in", "r", stdin);
//	freopen("excel.out", "w", stdout);
	r = read(), c = read(), minT = read(), maxT = read();
	for(rgi i = 1; i <= r; ++i)
		for(rgi j = 1; j <= c; ++j) if(minT <= i + j - 2 << 1 && i + j - 2 << 1 <= maxT)
		{
			ll res1 = 1, res2 = 1, tmp;
			
			res1 *= 4, res1 %= mod;
			if(i > 2)res1 *= i - 2, res1 %= mod;
			else	res1 = 0;
			if(j > 2)res1 *= j - 2, res1 %= mod;
			else	res1 = 0;
			
			res2 *= 2, res2 %= mod;
			if(i > 2)res2 *= i - 2, res2 %= mod;
			else	res2 = 0;
			if(j > 2)res2 *= j - 2, res2 %= mod;
			else	res2 = 0;
			
			tmp = (r - i + 1) * (c - j + 1) % mod * ((res1 + res2) % mod) % mod;
			ans += tmp, ans %= mod;
//			printf("%d %d %lld %lld %lld\n", i, j, res1, res2, res1 + res2);
		}
	printf("%lld", ans);
	return 0;
}
/*
3 3 1 20000

3 3 4 7

4 6 9 12

7 5 13 18

4000 4000 4000 14000

*/
