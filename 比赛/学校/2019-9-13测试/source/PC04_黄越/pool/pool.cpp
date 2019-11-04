#include <cstdio>
#include <cctype>
#include <numeric>
#include <algorithm>
using namespace std;

int read() {
	int x, c;
	while (!isdigit(c = getchar())); x = c - 48;
	while (isdigit(c = getchar())) x = x * 10 + c - 48;
	return x;
}

const int MOD = 1000000007;
int f[100010];

int main() {
	freopen("pool.in", "r", stdin);
	freopen("pool.out", "w", stdout);
	int t = read(), k = read();
	for (int i = 0; i <= k; ++i)
		f[i] = 1;
	for (int i = k + 1; i < 100010; ++i)
		f[i] = (f[i - 1] + f[i - 1 - k]) % MOD;
	for (int i = 1; i < 100010; ++i)
		f[i] += f[i - 1], f[i] %= MOD;
	for (int a, b; t--; printf("%d\n", (f[b + 1] - f[a] + MOD) % MOD))
		a = read(), b = read();
	return 0;
}
