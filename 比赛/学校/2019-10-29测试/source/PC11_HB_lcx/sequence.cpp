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
int n, k, l, r;
int a[5000001];
int b[5000001];
int c[5000001], cnt;
inline bool cmp(int x, int y) {
	return x > y;
}
signed main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n = read(), k = read(), l = read(), r = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for(int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + l - 1; j <= i + r - 1; j++) {
			c[++cnt] = b[j] - b[i - 1];
		}
	}
	sort(c + 1, c + 1 + cnt, cmp);
	int ans = 0;
	for(int i = 1; i <= k; i++) {
		ans += c[i];
	}
	printf("%lld\n", ans);
	return 0;
}
/*
4 3 2 3
3
2
-6
8
*/
