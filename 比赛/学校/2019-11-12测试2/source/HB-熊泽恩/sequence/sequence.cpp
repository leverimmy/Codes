#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const ll N = 1e5 + 10;

ll n, k, ans, l, r, tot;
ll a[N], c[N], sum[N], arr[N];

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add(ll x, ll w) {for(; x < N; x += x & -x)	c[x] += w;}
ll Query(ll x) {ll res = 0; for(; x; x -= x & -x)	res += c[x];	return res;}

bool Check(ll x) {
	
	ll res = 0;
	memset(c, 0, sizeof(c));
	Add(std::lower_bound(arr + 1, arr + tot + 1, 0) - (arr + 1) + 1, 1);
	
	for(rgi i = 1; i <= n; ++i) {
		
		res += Query(std::upper_bound(arr + 1, arr + tot + 1, sum[i] - x) - (arr + 1));
		
		Add(std::lower_bound(arr + 1, arr + tot + 1, sum[i]) - (arr + 1) + 1, 1);
		
	}
	
	return res >= k;
}

int main() {
//	freopen("sequence.in", "r", stdin);
//	freopen("sequence.out", "w", stdout);
	n = read(), k = read();
	for(rgl i = 1; i <= n; ++i)	{
		a[i] = read();
		sum[i] = sum[i - 1] + a[i];
		arr[i] = sum[i];
	}
	
	std::sort(arr + 1, arr + n + 2);
	tot = std::unique(arr + 1, arr + n + 2) - (arr + 1);
	
	l = -(1LL << 50); r = 1LL << 50;
	while(l < r) {
		ll mid = l + r + 1 >> 1;
		if(Check(mid))
			l = mid, ans = mid;
		else
			r = mid - 1;
	}
	
	printf("%lld", ans);
	
	return 0;
}
/*
10 4
-81 90 -76 66 -47 59 37 -60 97 60

*/
