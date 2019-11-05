#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 100 + 10;

ll T, n, f[(int)1e5 + 10], ans;

struct node {
	ll a, b, c;
	bool operator < (const struct node &rhs)	const {
		return b * rhs.c > c * rhs.b;
	}
} p[N];

int main() {
	std::cin >> T >> n;
	for(rgl i = 1; i <= n; ++i)	std::cin >> p[i].a;
	for(rgl i = 1; i <= n; ++i)	std::cin >> p[i].b;
	for(rgl i = 1; i <= n; ++i)	std::cin >> p[i].c;
	std::sort(p + 1, p + n + 1);
	
	for(rgl i = 1; i <= n; ++i)
		for(rgl j = T; j >= p[i].c; --j) {
			f[j] = std::max(f[j], f[j - p[i].c] + p[i].a - j * p[i].b);
			ans = std::max(ans, f[j]);
		}
	
	std::cout << ans;
	return 0;
}

