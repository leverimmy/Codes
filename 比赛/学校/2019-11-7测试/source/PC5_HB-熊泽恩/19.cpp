#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

ll s, t, _1, _2, _3, _4, mod;

ll f[10010] = {0, 1};

int main() {
	freopen("19.in", "r", stdin);
	freopen("19.out", "w", stdout);
	std::cin >> s >> t;
	std::cin >> _1 >> _2 >> _3 >> _4;
	mod = _1 * _2 * _3 * _4;
	for(rgi i = 2; i <= 10000; ++i)
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	for(rgi i = s; i <= t; ++i) {
		ll k = f[i];
		if(k % _1 != 0 && k % _2 != 0 && k % _3 != 0 && k % _4 != 0)
			printf("%lld ", i);
	}
	return 0;
}

