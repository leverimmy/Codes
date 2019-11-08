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
struct node{
	int x, y, val;
	bool operator < (const node &b) const {
		return val < b.val;
	}
} q[100001];
int f[10001];
int gf(int x) {
	return f[x] == x ? x : f[x] = gf(f[x]);
}
signed main() {
	freopen("5.in", "r", stdin);
	freopen("5.out", "w", stdout);
	int n, m;
	while(cin >> n >> m) {
		for(int i = 1; i <= n; i++) {
			f[i] = i;
		}
		for(int i = 1; i <= m; i++) {
			q[i].x = read(), q[i].y = read(), q[i].val = read();
		}
		sort(q + 1, q + 1 + m);
		int cnt = 0, ans = 0;
		for(int i = 1; i <= m; i++) {
			if(cnt == n - 1) {
				break;
			}
			int q1 = gf(q[i].x);
			int q2 = gf(q[i].y);
			if(q1 != q2) {
				f[q1] = q2;
				ans += q[i].val;
				cnt++;
			} else {
				continue;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
