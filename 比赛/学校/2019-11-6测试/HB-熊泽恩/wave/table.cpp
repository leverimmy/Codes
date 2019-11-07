#include <bits/stdc++.h>
#define int long long
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 50 + 10;
const int M = 2500 + 10;

int f[N][M];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int solve(int n) {
	int a[n + 1], cnt = 0;
	for(rgi i = 1; i <= n; ++i)	a[i] = i;
	do {
		int ans = 0;
		for(rgi i = 1; i <= n - 1; ++i)
			ans += abs(a[i] - a[i + 1]);
		f[n][ans]++;
	} while(std::next_permutation(a + 1, a + n + 1));
	return cnt;
}

signed main() {
	freopen("table.in", "w", stdout);
	putchar('{');
	for(rgi i = 1; i <= 14; ++i)
		solve(i);
	
	for(rgi i = 1; i <= 14; ++i) {
		putchar('{');
		for(rgi j = 1; j <= 200; ++j)
			printf("%lld, ", f[i][j]);
		printf("%lld", f[i][201]);
		putchar('}');
		putchar(','), putchar(' ');
	}	
	putchar('}');
	return 0;
}

