#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e6 + 10;
const int mod = 19930726;

int n, id, p[N], a[N];
ll k, ans = 1LL, sum;

char str[N];

ll ksm(ll a, ll b) {
	ll res = 1 % mod;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	} return res;
}

void Manacher() {
	for(rgi i = 1; i <= n; ++i) {
#define MX id + p[id]
		p[i] = MX > i ? std::min(p[(id << 1) - i], MX - i) : 1;
		while(str[i - p[i]] == str[i + p[i]] && i - p[i] >= 1 && i + p[i] <= n) p[i]++;
		if(i + p[i] > MX) id = i;
		a[(p[i] << 1) - 1]++;
	}
}

int main() {
	scanf("%d %lld", &n, &k);
	scanf("%s", str + 1);
	
	Manacher();
	
	for(rgi i = n; i; --i) if(i & 1) {
		sum += a[i];
		if(k >= sum) {
			ans = ans * ksm(i, sum), ans %= mod;
			k -= sum;
		}
		else {
			ans = ans * ksm(i, k), ans %= mod;
			break;
		}
	}
	printf("%lld", sum < k ? -1 : ans);
	return 0;
}

