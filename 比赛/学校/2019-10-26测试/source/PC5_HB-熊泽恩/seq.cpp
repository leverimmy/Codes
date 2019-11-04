#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

ll ans;

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll gcd(ll a, ll b) {
	if(!b)	return a;
	ans += a / b;
	return gcd(b, a % b);
}

int main() {
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	
	gcd(read(), read());
	printf("%lld", ans + 1);
	
	return 0;
}

