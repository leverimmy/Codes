#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 5000 + 10;
const int M = 1e6 + 10;

ll n, m, ans;
ll a[N], arr[M], tmp[N];

struct QUERY {
	ll l, r;
} q[M];

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);
	n = read(), m = read();
	for(rgl i = 1; i <= m; ++i)	arr[i] = i;
	for(rgl i = 1; i <= n; ++i)	a[i] = read();
	for(rgl i = 1; i <= m; ++i) {
		q[i].l = read();
		q[i].r = read();
	}
	
	do {
		for(rgl i = 1; i <= n; ++i)	tmp[i] = a[i];
		ll res = 0;
		for(rgl i = 1; i <= m; ++i)	{
			ll cur = 0;
			for(rgl j = q[arr[i]].l; j <= q[arr[i]].r; ++j)
				cur += tmp[j], tmp[j] = 0;
			res += cur * cur;
		}
		
		ans = std::max(ans, res);
		
	} while(std::next_permutation(arr + 1, arr + m + 1));
	
	printf("%lld", ans);
	
	return 0;
}

