#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int mod = 1000000007;

int n;
ll f[(int)5e5 + 10] = {0, 1LL};

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	n = read();
	for(rgi i = 2; i <= (int)5e5 + 9; ++i)
		f[i] = f[i - 1] + f[i + 1 >> 1], f[i] %= mod;
	
//	for(rgi i = 1; i <= n; ++i)
//		printf("%lld\n", f[i + 2 >> 1]);
		
	printf("%lld", f[n + 2 >> 1]);
	return 0;
}

