#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

ll n, m, l, ans;

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll gcd(ll a, ll b) {
	return !b ? a : gcd(b, a % b);
}

ll Ceil(ll up, ll down) {
	ll pr1 = up / down;
	double pr2 = up * 1.0 / down;
	if(pr2 - pr1 >= 0.5)
		return pr1 + 1;
	else
		return pr1;
}

int main() {
	n = read(), m = read(), l = read();
	if(n < m)	std::swap(n, m);
//	if(n % l == 0 && m % l == 0)
//		printf("%lld", gcd(n / l, m / l));
	if(std::max(Ceil(n, l), Ceil(m, l)) < 50000000) {
		for(rgi i = 1; i <= Ceil(m, l); ++i) {
			if(((n + l) * i + n - m) % (m + l) == 0)
				ans++;
		}
		printf("%lld", ans);
	}
	else {
		puts("0");
	}
	return 0;
}

