#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

ll a, b, c;

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
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	while(std::cin >> a >> b >> c) {
		std::cout << qmod(a, b, c) << std::endl;
	}
	return 0;
}

