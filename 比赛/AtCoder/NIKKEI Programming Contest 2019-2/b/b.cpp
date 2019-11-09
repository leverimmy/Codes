#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e5 + 10;
const ll mod = 998244353;

ll n, max_depth, ans = 1;
ll d[N], cnt[N];

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll qmod(ll base, ll power, ll mod) {
	ll res = 1 % mod;
	while(power) {
		if(power & 1)
			res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}

int main() {
	n = read();
	for(rgl i = 1; i <= n; ++i)	{
		d[i] = read();
		cnt[d[i]]++;
		max_depth = std::max(max_depth, d[i]);
	}
	
	for(rgl i = 1; i <= max_depth; ++i) {
		ll last = cnt[i - 1];
		ll cur = cnt[i];
		
		ans *= qmod(last, cur, mod);
		ans %= mod;
	}
	
	if(d[1] == 0 && cnt[0] == 1)
		printf("%lld", ans % mod);
	else
		printf("0");
	return 0;
}

