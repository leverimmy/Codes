#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

ll n, k, t, p, ans1, ans2;

int main() {
	scanf("%lld %lld", &n, &k);
	
	for(t = 0; (1LL << t) - 1 < k; ++t); t--;
	p = 1LL << t;
	t = p - 1;
	t = k - t;
	ans2 = (n - (t - 1)) / p;
	if(!(ans2 & 1)) ans2--;
	
	for(t = 0; (1LL << t) - 2 < k; ++t); t--;
	p = 1LL << t;
	t = p - 2;
	t = k - t;
	ans1 = (n - (t - 1LL)) / p * 2LL;
	
	printf("%lld", std::max(ans1, ans2));
	return 0;
}

