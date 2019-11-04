#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define il inline
#define EPS 1e-8

const int N = 2e5 + 10;

int n, k, ans;

double logk, a[N], s[N], slog[N];

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);

	/*scanf("%d %d", &n, &k); logk = log(k);
	for(rgi i = 1; i <= n; ++i)	scanf("%lf", &a[i]);
	
	for(rgi i = 1; i <= n; ++i)	s[i] = s[i - 1] + a[i], slog[i] = slog[i - 1] + log(a[i]);
	
	for(rgi len = 1; len <= n; ++len) {
		for(rgi l = 1; l + len - 1 <= n; ++l) {
			int r = l + len - 1;
			if(fabs(slog[r] - slog[l - 1] - (logk + log(s[r] - s[l - 1]))) <= EPS)
				ans++;
		}
	}
	printf("%d", ans);*/
	
	scanf("%d %d", &n, &k); logk = log(k);
	for(rgi i = 1; i <= n; ++i)	{
		scanf("%lf", &a[i]);
		if(a[i] == 1)	n--, i--;
	}
	
	for(rgi i = 1; i <= n; ++i)	s[i] = s[i - 1] + a[i], slog[i] = slog[i - 1] + log(a[i]);
	
	for(rgi len = 1; len <= n; ++len) {
		for(rgi l = 1; l + len - 1 <= n && slog[l + len - 1] - slog[l - 1] <= 63; ++l) {
			int r = l + len - 1;
			if(fabs(slog[r] - slog[l - 1] - (logk + log(s[r] - s[l - 1]))) <= EPS)
				ans++;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
