#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int M = 1e6 + 10;

ll n, m, k, ans = 1LL;
ll inv[M] = {0, 1LL};

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(rgl i = 2; i <= m; ++i)
	{
		inv[i] = -(mod / i) * inv[mod % i];
		inv[i] = (inv[i] % mod + mod) % mod;
	}
	for(rgl i = 1; i <= m - 1; ++i)
		ans = ans * (n - k + 1 - i) % mod;
//	printf("%lld\n", ans);
	for(rgl i = 1; i <= m - 1; ++i)
		ans = ans * inv[i] % mod;
	printf("%lld", ans);
	return 0;
}
/*
888 222 555

999888 555333 222333

*/
