#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 100 + 10;

int n, m, ans;
int a[N][N], f[N][N];

int main() {
	std::cin >> n >> m;
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1; j <= m; ++j)
		std::cin >> a[i][j];
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1; j <= m; ++j)	if(a[i][j]) {
		int pre = std::min(f[i - 1][j], f[i][j - 1]);
		f[i][j] = std::min(pre, f[i - 1][j - 1]) + 1;
		ans = std::max(ans, f[i][j]);
	}
	std::cout << ans;
	return 0;
}

