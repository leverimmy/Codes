#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

int n, ans;

int main() {
	freopen("12.in", "r", stdin);
	freopen("12.out", "w", stdout);
	std::cin >> n;
	for(rgi i = 1; i <= n; ++i)
		ans += n % i == 0;
	std::cout << ans;
	return 0;
}

