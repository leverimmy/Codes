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
int f[1000001][4][2];
int a[1000001];
signed main() {
//	freopen("jx.in", "r", stdin);
//	freopen("jx.out", "w", stdout);
	int n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1]);
			f[i][j][1] = max(max(f[i - 1][j - 1][1], f[i - 1][j - 1][0]), f[i - 1][j][1]) + a[i];
		}
	}
	printf("%lld\n", max(f[n][3][0], f[n][3][1]));
	return 0;
}
