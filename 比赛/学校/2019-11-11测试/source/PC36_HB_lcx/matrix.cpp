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
const int N = 5001, M = 5001;
int a[N][M];
int s[N][M];
signed main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			char x;
			cin >> x;
			a[i][j] = x - '0';
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			s[i][j] = s[i][j - 1] + a[i][j];
		}
	}	
	int ans = 0;
	for(int l = 1; l <= m; l++) {
		for(int r = l; r <= m; r++) {
			int len = 0;
			for(int i = 1; i <= n; i++) {
				if(s[i][r] - s[i][l - 1] == r - l + 1) {
					len++;
				}
			}
			ans = max(ans, len * (r - l + 1));
		}
	}
	printf("%lld\n", ans);
	return 0;
}
