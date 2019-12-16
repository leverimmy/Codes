#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int mod = 1e9 + 7;
const int N = 100 + 10;

int n, m, k, c[N], vis[N];
ll ans, fac[N] = {1LL};

std::set <ll> s;
std::set <int> NUM;

ll qmod(ll a, ll b) {
	ll res = 1LL;
	while(b) {
		if(b & 1) res = res * a, res %= mod;
		a = a * a % mod;
		b >>= 1;
	} return res % mod;
}

ll C(ll a, ll b) {
	ll res = 1LL;
	for(rgi i = a; i >= a - b + 1; --i) res = res * i % mod;
	res *= qmod(fac[b], mod - 2), res %= mod;
	return res;
}

void dfs(int x, int color) {
	if(x == n) {
		int l = 1, r = 1;
		for(rgi l = 1; l <= n; ++l) {
			ll num = 0LL;
			for(rgi r = l; r <= n; ++r) {
				num = num * 10 + c[r];
				s.insert(num);
			}
		}
		
		if(s.size() == m) {
			ll tmp = 1LL, now = 0LL;
			bool Continue = 1;
			for(rgi i = 1; i <= n; ++i) vis[i] = 0;
			for(rgi i = 1; i <= n; ++i) vis[c[i]]++;
			for(rgi i = 1; i <= n && Continue; ++i) {
				if(vis[i]) now++;
//				if(vis[i] > vis[i - 1] && i > 1) Continue = 0;
			}
			ans += Continue * C(k, now), ans %= mod;
		}
		
		s.clear();
		NUM.clear();
		return;
	}
	
	for(rgi i = 1; i <= n; ++i) {
		c[x + 1] = i;
		dfs(x + 1, i);
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for(rgi i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
	dfs(0, 1);
	printf("%lld", ans);
	return 0;
}
/*
5 14 5

*/
