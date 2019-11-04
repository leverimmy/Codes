#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000005;
const int MOD = 1000000007;

int N, M, K;
long long fac[MAXN], ifac[MAXN];

long long pw(long long x, long long y)
{
	long long res = 1;
	while (y)
	{
		if (y & 1) res = (res * x) % MOD;
		x = (x * x) % MOD;
		y >>= 1;
	}
	return res;
}

int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	cin >> N >> M >> K;
	int n = N - K;
	int m = M - 1;
	int ans = 0;
	if (n >= m)
	{
		fac[0] = 1;
		for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD;
		ifac[n] = pw(fac[n], MOD - 2);
		for (int i = n - 1; i >= 0; i--) ifac[i] = (ifac[i + 1] * (i + 1)) % MOD;
		ans = (((fac[n] * ifac[m]) % MOD) * ifac[n - m]) % MOD;
	}
	cout << ans << endl;
	return 0;
}
