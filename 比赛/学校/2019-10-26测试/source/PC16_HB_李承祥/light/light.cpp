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
int a[100001];
vector<int> t[10001];
int maxx;
int Ask(int l, int r, int p, int v) {
	int ans = 0;
	for(int i = v; i <= maxx; i += p) {
		int ml = lower_bound(t[i].begin(), t[i].end(), l) - t[i].begin();
		int mr = upper_bound(t[i].begin(), t[i].end(), r) - t[i].begin();
		ans += mr - ml;
	}
	return ans;
}
inline void write(int x) {
	if(x < 10) {
		putchar(x + '0');
		return;
	}
	write(x / 10);
	putchar(x % 10 + '0');
}
signed main() {
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		t[a[i]].push_back(i);
		maxx = max(maxx, a[i]);
	}
	for(int i = 1; i <= m; i++) {
		int l = read(), r = read(), p = read(), v = read();
		write(Ask(l, r, p, v));
		puts("");
	}
	return 0;
}
