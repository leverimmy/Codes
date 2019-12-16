#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

#define int long long

int a, b, c, d, e, f, max_val, ans;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

signed main() {
	a = read(), b = read(), c = read(), d = read(), e = read(), f = read();
	if(e >= f) {
		max_val = std::min(a, d);
		a -= max_val, d -= max_val;
		ans = e * max_val + f * std::min(b, std::min(c, d));
	}
	else {
		max_val = std::min(b, c);
		max_val = std::min(max_val, d);
		b -= max_val, c -= max_val, d -= max_val;
		ans = f * max_val + e * std::min(a, d);
	}
	printf("%lld", ans);
	return 0;
}

