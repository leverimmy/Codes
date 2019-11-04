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
int a[100001];
int ans, n, m;
struct node {
	int l, r;
};
vector<node>q[1000001];
inline bool cmp(node a, node b) {
	return a.l < b.l;
}
inline void change(int x, int y) {
	int sz = q[x].size();
	for(int i = 0; i < sz; i++) {
		if(a[q[x][0].l - 1] == y) {
			ans--;
		}
		if(a[q[x][0].r + 1] == y) {
			ans--;
		}
	}
	while(!q[x].empty()) {
		q[y].push_back(q[x][0]);
		for(int i = q[x][0]. l; i <= q[x][0].r; i++) {
			a[i] = y;
		}
		q[x].erase(q[x].begin());
	}
}
signed main() {
	freopen("pudding.in", "r", stdin);
	freopen("pudding.out", "w", stdout);
	n = read(), m = read();
	int l = 0, r = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		if(a[i] != a[i - 1]) {
			q[a[i - 1]].push_back((node) {
				l, r
			});
			ans++;
			l = r + 1;
			r = l;
		} else {
			r++;
		}
	}
	while(m--) {
		int judge = read();
		if(judge == 1) {
			int x = read(), y = read();
			if(x == y || ans == 1) {
				continue;
			}
			change(x, y);
		} else {
			if(ans < 0) {
				ans = 1;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
