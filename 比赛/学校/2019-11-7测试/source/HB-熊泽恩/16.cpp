#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 10 + 10;

int n, s, a[N][N];

void dfs(int x, int y, int w) {
	if(w == n + 4 * (s - 1))
		return;
	a[x][y] = w;
	if(x == 1 && y > 1)
		dfs(x, y - 1, w + 1);
	if(x == s && y < s)
		dfs(x, y + 1, w + 1);
	if(y == 1 && x < s)
		dfs(x + 1, y, w + 1);
	if(y == s && x > 1)
		dfs(x - 1, y, w + 1);
}

int main() {
	freopen("16.in", "r", stdin);
	freopen("16.out", "w", stdout);
	std::cin >> n >> s;
	if(s == 1)	printf("%d\n", n);
	else {
		dfs(1, 1, n);
		for(rgi i = 1; i <= s; ++i) {
			for(rgi j = 1; j <= s; ++j) {
				if(a[i][j])
					std::cout << a[i][j] << " ";
				else
					std::cout << "   ";
			}
			puts("");
		}
	}
	return 0;
}

