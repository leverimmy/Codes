#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int jc[1000001];
inline int ksm(int x, int b) {
	if(b == 0) {
		return 1;
	}
	int t = ksm(x, b / 2);
	t *= t;
	t %= mod;
	if(b & 1) {
		t *= x;
		t %= mod;
	}
	return t;
}
signed main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	int n = read(), m = read(), k = read();
	jc[1] = 1;
	for(int i = 2; i <= n; i++) {
		jc[i] = (jc[i - 1] * i) % mod;
	}
	int ks = ksm(jc[m - 1], mod - 2);
	int ans = ((jc[n - k] * ksm(jc[n - k - m + 1], mod - 2)) % mod * ks) % mod;
	printf("%lld\n", ans);
	return 0;
}
