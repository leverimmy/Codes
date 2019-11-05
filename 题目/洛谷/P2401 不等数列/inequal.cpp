#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int mod = 2015;
const int N = 1000 + 10;
const int K = 1000 + 10;

int n, k, f[N][K];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), k = read();
	f[1][0] = 1;
	for(rgi i = 2; i <= n; ++i)	{
		f[i][0] = 1;
		for(rgi j = 1; j <= k; ++j)
			f[i][j] = (f[i - 1][j - 1] * (i - j) % mod + f[i - 1][j] * (j + 1) % mod) % mod;
	}
	printf("%d", f[n][k]);
	return 0;
}

