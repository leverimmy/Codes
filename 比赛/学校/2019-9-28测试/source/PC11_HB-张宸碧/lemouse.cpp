#include<bits/stdc++.h>
#define int long long
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
int a[1001][1001];
int b[1001][1001];
int xx[4] = { 0, 0, 1, -1};
int yy[4] = { -1, 1, 0, 0};
int f[1001][1001];
int vis[1001][1001];
int fx[1001][1001];
signed main() {
	freopen("lemouse.in", "r", stdin);
	freopen("lemouse.out", "w", stdout);
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			a[i][j] = read();
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			for(int k = 0; k < 4; k++) {
				b[i][j] += a[i + xx[k]][j + yy[k]];
			}
		}
	}
	memset(vis, false, sizeof(vis));
	for(int i = 1; i <= n; i++) {
		f[i][0] = 0x7ffffff;
	}
	for(int i = 1; i <= m; i++) {
		f[0][i] = 0x7ffffff;
	}
	f[1][1] = a[1][1] + b[1][1];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(i == 1 && j == 1) {
				continue;
			}
			if(f[i - 1][j] > f[i][j - 1]) {
				f[i][j] = f[i][j - 1] + b[i][j] - a[i][j - 1];
				if(fx[i][j - 1] == 1 && fx[i - 1][j] != 1) {
					f[i][j] -= a[i - 1][j];
				}
				fx[i][j] = 2;
			} else {
				f[i][j] = f[i - 1][j] + b[i][j] - a[i - 1][j];
				if(fx[i - 1][j] == 2 && fx[i][j - 1] != 2) {
					f[i][j] -= a[i][j - 1];
				}
				fx[i][j] = 1;
			}
		}
	}
	printf("%lld\n", f[n][m]);
	return 0;
}
