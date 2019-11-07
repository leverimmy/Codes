#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 20 + 2;

int n, a[N][N];

int main() {
	freopen("7.in", "r", stdin);
	freopen("7.out", "w", stdout);
	std::cin >> n;
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
			std::cin >> a[i][j];
	for(rgi state = 0; state < 1 << n; ++state) {
		int flag = 1, ans = 0, vis[N] = {0};
		for(rgi i = 1; i <= n; ++i)	if((1 << i - 1) & state)
			vis[i] = 1;
		for(rgi i = 1; i <= n && flag; ++i)	for(rgi j = 1; j <= n && flag; ++j)
			if(vis[i] == 1 && a[i][j] != vis[j])
				flag = 0;
		if(flag) {
			for(rgi i = 1; i <= n; ++i)	if(vis[i])	ans++;
			if(ans * 2 >= n)
			for(rgi i = 1; i <= n; ++i)	if(vis[i])	std::cout << i << " ";
		}
	}
	return 0;
}

