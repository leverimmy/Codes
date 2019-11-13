#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 5e5 + 10;

int len, n, a[N], b[N], ans;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("clean.in", "r", stdin);
	freopen("clean.out", "w", stdout);
	len = read(), n = read();
	for(rgi i = 1; i <= n; ++i) {
		int l = read(), r = read();
		if(l > r)	std::swap(l, r);
		b[r + 1]++, b[l]--;
	}
	for(rgi i = 1; i <= len; ++i)	{
		a[i] = a[i - 1] + b[i];
		ans += !a[i];
	}
	printf("%d", ans);
	return 0;
}

