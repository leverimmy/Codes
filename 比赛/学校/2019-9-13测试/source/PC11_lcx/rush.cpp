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
int xx[1000001], yy[1000001];
int xa, ya;
signed main() {
	freopen("rush.in", "r", stdin);
	freopen("rush.out", "w", stdout);
	int n = read(), m = read();
	for(int i = 1; i <= m; i ++) {
		int x = read(), y = read();
		xx[x]++;
		if(xx[x] == 1) {
			xa++;
		}
		yy[y]++;
		if(yy[y] == 1) {
			ya++;
		}
	}
	int ans = 0;
	if(xa > ya) {
		for(int i = 1; i <= n; i++) {
			if(yy[i] == 0) {
				yy[i] = 1;
				ans++;
			} else {
				yy[i] = 0;
			}
		}
		for(int i = 1; i <= n; i ++) {
			if(xx[i] == 0) {
				if(yy[i] == 2) {
					if(yy[n - i + 1] == 0) {
						ans++;
						xx[i] == 3;
					} else if(yy[n - i + 1] == 1) {
						yy[n - i + 1] == 2;
						ans++;
						xx[i] == 3;
					} else if(yy[n - i + 1] == 2) {
						ans++;
						xx[i] == 2;
					} else {
						ans++;
						xx[i] = 3;
					}
				} else if(yy[i] == 0) {
					if(yy[n - i + 1] == 0) {
						ans++;
						xx[i] = 2;
					} else if(yy[n - i + 1] == 1) {
						yy[n - i + 1] = 2;
						ans++;
						xx[i] = 2;
					} else if(yy[n - i + 1] == 2) {
						ans++;
						xx[i] = 2;
					} else {
						ans++;
						xx[i] = 3;
					}
				} else if(yy[i] == 1) {
					if(yy[n - i + 1] == 0) {
						yy[i] = 3;
						ans++;
						xx[i] = 2;
					} else if(yy[n - i + 1] == 1) {
						yy[i] = 3;
						yy[n - i + 1] = 2;
						ans++;
						xx[i] = 2;
					} else if(yy[n - i + 1] == 2) {
						yy[i] = 3;
						ans++;
						xx[i] = 2;
					} else {
						yy[i] = 2;
						ans++;
						xx[i] = 3;
					}
				} else {
					if(yy[n - i + 1] == 0) {
						ans++;
						xx[i] = 2;
					} else if(yy[n - i + 1] == 1) {
						yy[n - i + 1] = 2;
						ans++;
						xx[i] = 2;
					} else if(yy[n - i + 1] == 2) {
						ans++;
						xx[i] = 2;
					} else {
						xx[i] = 0;
					}
				}
			}
		}
	} else {
		for(int i = 1; i <= n; i++) {
			if(xx[i] == 0) {
				xx[i] = 1;
				ans++;
			} else {
				xx[i] = 0;
			}
		}
		for(int i = 1; i <= n; i ++) {
			if(yy[i] == 0) {
				if(xx[i] == 2) {
					if(xx[n - i + 1] == 0) {
						ans++;
						yy[i] == 3;
					} else if(xx[n - i + 1] == 1) {
						xx[n - i + 1] == 2;
						ans++;
						yy[i] == 3;
					} else if(xx[n - i + 1] == 2) {
						ans++;
						yy[i] == 2;
					} else {
						ans++;
						yy[i] = 3;
					}
				} else if(xx[i] == 0) {
					if(xx[n - i + 1] == 0) {
						ans++;
						yy[i] = 2;
					} else if(xx[n - i + 1] == 1) {
						xx[n - i + 1] = 2;
						ans++;
						yy[i] = 2;
					} else if(xx[n - i + 1] == 2) {
						ans++;
						yy[i] = 2;
					} else {
						ans++;
						yy[i] = 3;
					}
				} else if(xx[i] == 1) {
					if(xx[n - i + 1] == 0) {
						xx[i] = 3;
						ans++;
						yy[i] = 2;
					} else if(xx[n - i + 1] == 1) {
						xx[i] = 3;
						xx[n - i + 1] = 2;
						ans++;
						yy[i] = 2;
					} else if(xx[n - i + 1] == 2) {
						xx[i] = 3;
						ans++;
						yy[i] = 2;
					} else {
						xx[i] = 2;
						ans++;
						yy[i] = 3;
					}
				} else {
					if(xx[n - i + 1] == 0) {
						ans++;
						yy[i] = 2;
					} else if(xx[n - i + 1] == 1) {
						xx[n - i + 1] = 2;
						ans++;
						yy[i] = 2;
					} else if(xx[n - i + 1] == 2) {
						ans++;
						yy[i] = 2;
					} else {
						yy[i] = 0;
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
