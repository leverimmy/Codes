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
const int N = 805;
int n, m;
int jz1[N][N], jz2[N][N], jz3[N][N];
int s1[N][N], s2[N][N], s3[N][N];
signed main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	n = read(), m = read();
	for(int j = 1; j <= n; j++) {
		for(int k = 1; k <= n; k++) {
			jz1[j][k] = read();
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			s1[i][j] = s1[i - 1][j] + jz1[i][j];
		}
	}
	for(int j = 1; j <= n; j++) {
		for(int k = 1; k <= n; k++) {
			jz2[j][k] = read();
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			s2[i][j] = s2[i][j - 1] + jz2[i][j];
		}
	}
	for(int i = 1; i <= m; i++) {
		int a = read(), b = read(), c = read(), d = read();
		int ans = 0;
		if(a > c) {
 			swap(a, c);
		}
		if(b > d) {
			swap(b, d);
		}
		for(int k = 1; k <= n; k++) {
			ans += (s1[c][k] - s1[a - 1][k]) * (s2[k][d] - s2[k][b - 1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
