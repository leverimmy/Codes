#include<bits/stdc++.h>
#define int long long
#define INF 0x7ffffff
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
int a[100001];
int f[110001][101];
signed main() {
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	int n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	int m = read();
	if(n <= 100) {
		for(int i = 1; i <= m; i++) {
			int ans = 0;
			int p = read(), k = read();
			while(p <= n) {
				p += a[p] + k;
				ans ++;
			}
			printf("%lld\n", ans);
		}
	} else {
		for(int k = 0; k <= 100; k++){
			f[n][k] = 1;
			for(int i = n - 1; i >= 1; i--) {
				f[i][k] = f[i + a[i] + k][k] + 1;
			}
		}
		for(int i = 1; i <= m; i++) {
			int ans = 0;
			int p = read(), k = read();
			if(k == 0) {
				printf("%lld\n", f[p][0]);
			} else if(k <= 100) {
				printf("%lld\n", f[p][k]);
			} else {
				while(p <= n) {
					p += a[p] + k;
					ans ++;
				}
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}
