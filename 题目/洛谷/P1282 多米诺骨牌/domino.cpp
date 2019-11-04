#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1000 + 10;
const int K = 5000;

int n, ans, dis[N];
int f[N][N + K * 2];

int main() {
	std::cin >> n;
	memset(f, 0x3f, sizeof(f)); f[0][K] = 0;
	for(rgi i = 1; i <= n; ++i) {
		int up, down;
		std::cin >> up >> down;
		dis[i] = up - down;
	}
	for(rgi i = 1; i <= n; ++i)	for(rgi j = -K; j <= K; ++j)
		f[i][j + K] = std::min(f[i - 1][j - dis[i] + K], f[i - 1][j + dis[i] + K] + 1);
	
	for(rgi i = 0; i <= K; ++i) {
		ans = std::min(f[n][K + i], f[n][K - i]);
		if(ans <= 1000) {
			printf("%d", ans);
			break;
		}
	}
	return 0;
}

