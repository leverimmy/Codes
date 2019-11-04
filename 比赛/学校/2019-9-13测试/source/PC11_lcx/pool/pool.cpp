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
int f[1000001][2];
signed main() {
	freopen("pool.in", "r", stdin);
	freopen("pool.out", "w", stdout);
	int T = read(), k = read();
	for(int i = 1; i < k; i ++) {
		f[i][0] = 1;
	}
	while(T--) {
		int l = read(), r = read();
		for(int i = k; i <= r; i ++) {
			f[i][0] = f[i - 1][0];
			f[i][1] = f[i - k][0] + f[i - k][1] + 1;
		}
		int ans = 0;
		for(int i = l; i <= r; i++) {
			ans += f[i][0] + f[i][1];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
