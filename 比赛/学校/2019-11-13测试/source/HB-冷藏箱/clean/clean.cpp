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
const int N = 5000004;
struct node {
	int l, r;
	bool operator < (const node &b) const {
		if(l != b.l) {
			return l < b.l;
		}
		return r > b.r;
	}
}q[N];
signed main() {
	freopen("clean.in", "r", stdin);
	freopen("clean.out", "w", stdout);
	int len = read(), n = read();
	for(int i = 1; i <= n; i++) {
		q[i].l = read(), q[i].r = read();
	}
	sort(q + 1, q + 1 + n);
	int r = 0, ans = 0;
	for(int i = 1; i <= n;) {
		int l = i;
		if(r < q[i].l) {
			ans += q[i].l - r - 1;
		}
		r = max(q[i].r, r);
		while(q[i].l == q[i - 1].l) {
			i++;
		}
		if(l == i) {
			i++;
		}
	}
	if(r < len) {
		ans += len - r;
	}
	printf("%lld\n", ans);
	return 0;
}
