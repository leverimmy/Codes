#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define il inline

const int oo = 0x3f3f3f3f;

ll n, m, p;

ll qmod(ll base, ll power, ll mod) {
	ll res = 1LL % mod;
	while(power) {
		if(power & 1)
			res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}

int main() {
	scanf("%lld %lld %lld", &n, &m, &p);
	printf("%lld\n", qmod(n, p, m));
	return 0;
} 
