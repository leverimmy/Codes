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
double a[1000001];
signed main() {
	freopen("noon.in", "r", stdin);
	freopen("noon.out", "w", stdout);
	int n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), k = read();
		a[x] = (double)k / (double)x;
		double zg = 0;
		int ans = 0;
		for(int j = 1; j <= n; j++) {
			if(a[j] > zg) {
				zg = a[j];
				ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
