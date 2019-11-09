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
int n;
int a[2000001];
inline int judge(int l, int r) {
	int sum = 1, ans = 0;
	for(int i = 1; i <= n; i++) {
		if(i == l) {
			i = r + 1;
			if(a[i] <= a[l - 1]) {
				ans = max(ans, sum);
				sum = 1;
			} else {
				sum++;
			}
		} else {
			if(a[i] <= a[i - 1]) {
				ans = max(ans, sum);
				sum = 1;
			} else {
				sum++;
			}
		}
	}
	return ans;
}
signed main() {
	freopen("gfw.in", "r", stdin);
	freopen("gfw.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	int ans = 0;
	for(int l = 1; l <= n; l++) {
		for(int r = l; r <= n; r++) {
			ans = max(ans, judge(l, r));
		}
	}
	ans = max(ans, judge(0, 0));
	printf("%lld\n", ans);
	return 0;
}
