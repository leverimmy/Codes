#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int n, m;
struct node {
	int x, y;
} a[501];
int dis(int x0, int y0, int x2, int y2) {
	return abs(y2 - y0) + abs(x2 - x0);
}
int f[501][501];
signed main() {
	freopen("transport.in", "r", stdin);
	freopen("transport.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		a[i].x = read(), a[i].y = read();
	}
	memset(f, 0x3f, sizeof(f));
	for(int j = 0; j <= m; j++) {
		f[1][j] = 0;
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			for(int k = 2; k <= m + 1; k++) {
				if(i > k && j >= k - 1) {
					int disa = dis(a[i].x, a[i].y, a[i - k].x, a[i - k].y);
					int disb = dis(a[i].x, a[i].y, a[i - 1].x, a[i - 1].y);
					f[i][j] = min(f[i][j], min(f[i - 1][j] + disb, f[i - k][j - k + 1] + disa));
				} else {
					int disb = dis(a[i].x, a[i].y, a[i - 1].x, a[i - 1].y);
					f[i][j] = min(f[i][j], f[i - 1][j] + disb);
				}
			}
		}
	}
//	for(int i = 1; i <= n; i++) {
//		for(int j = 0; j <= m; j++) {
//			cout << f[i][j] << ' ';
//		}
//		cout << endl;
//	}
	int ans = 0x7ffffff;
	for(int i = 1; i <= m; i++) {
		ans = min(ans, f[n][i]);
	}
	printf("%d\n", f[n][m]);
	return 0;
}
