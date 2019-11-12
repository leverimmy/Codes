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
const int mod = 1000000000;
const int N = 4000004;
int n;
int len = 1;
priority_queue<int>q;
int ans[1000001];
inline void add(int x, int y) {
	int cnt = 1;
	ans[cnt] += x * y;
	while(ans[cnt] > mod) {
		ans[cnt + 1] += ans[cnt] / mod;
		ans[cnt] %= mod;
		cnt++;
		len = max(len, cnt);
	}
}
int a[N];
signed main() {
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for(int i = 1; i <= n; i++) {
		add(a[i], a[i + 1]);
		a[i + 1] = a[i] + a[i + 1];
	}
	for(int i = len; i >= 1; i--) {
		printf("%lld", ans[i]);
	}
	return 0;
}
