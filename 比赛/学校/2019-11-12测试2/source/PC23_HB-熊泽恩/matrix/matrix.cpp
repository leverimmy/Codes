#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 800 + 10;

ll n, m;
ll a[N][N], b[N][N], sumA[N][N], sumB[N][N];

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	n = read(), m = read();
	for(rgl i = 1; i <= n; ++i)
		for(rgl j = 1; j <= n; ++j) {
			a[i][j] = read();
			sumA[i][j] = sumA[i - 1][j] + a[i][j];
		}
	for(rgl i = 1; i <= n; ++i)
		for(rgl j = 1; j <= n; ++j) {
			b[i][j] = read();
			sumB[i][j] = sumB[i][j - 1] + b[i][j];
		}
	
	for(rgl i = 1; i <= m; ++i) {
		ll A = read(), B = read(), C = read(), D = read();
		ll ans = 0;
		if(A > C)	std::swap(A, C);
		if(B > D)	std::swap(B, D);
		for(rgl j = 1; j <= n; ++j)
			ans += (sumA[C][j] - sumA[A - 1][j]) * (sumB[j][D] - sumB[j][B - 1]);
		printf("%lld\n", ans);
	}
	
	/*for(rgi i = 1; i <= n; ++i) {
		for(rgi j = 1; j <= n; ++j)
			printf("%d ", sumA[i][j]);
		puts("");
	}
	
	puts("");
	
	for(rgi i = 1; i <= n; ++i) {
		for(rgi j = 1; j <= n; ++j)
			printf("%d ", sumB[i][j]);
		puts("");
	}*/
	
	return 0;
}

