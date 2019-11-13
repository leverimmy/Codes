#include <algorithm>
#include <cstring>
#include <cstdio>

inline void read(int &x) {
	x = 0;
	char c = getchar();
	bool f = 0;
	while(c < '0' || c > '9') {
		if(c == '-') {
			f = 1;	
		}
		c = getchar();	
	}
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();	
	}
	if(f) {
		x = (~x) + 1;	
	}
	return;
}

typedef long long LL;
const int N = 5010;

struct Node {
	int x, y, id;	
	inline bool operator <(const Node &w) const {
		return id < w.id;	
	}
}a[N], p[N]; int top;

int h[N], vis[N], rt[N], vis_p[N], n;

inline void solve() {
	LL ans = 0;
	do {
		memset(vis + 1, 0, n * sizeof(int));
		LL t = 0;
		for(int i = 1; i <= top; i++) {
			LL now = 0;
			for(int j = a[i].x; j <= a[i].y; j++) {
				if(vis[j]) {
					t += now * now;
					now = 0;
				}
				else {
					now += h[j];
					vis[j] = 1;
				}
			}
			t += now * now;
		}
		//ans = std::max(ans, t);
		if(t > ans) {
			ans = t;
		}
	} while(std::next_permutation(a + 1, a + top + 1));
	
	printf("%lld\n", ans);
	return;
}

int main() {
	
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout); 
	
	int m;
	read(n);
	read(m);
	for(int i = 1; i <= n; i++) {
		read(h[i]);
	}
	for(int i = 1, x, y; i <= m; i++) {
		read(x);
		read(y);
		rt[x] = std::max(rt[x], y);
	}
	for(int i = 1; i <= n; i++) {
		if(rt[i] > a[top].y) {
			a[++top].x = i;
			a[top].y = rt[i];
			a[top].id = top;
		}
	}
	
	if(top < 9) {
		solve();
		return 0;
	}
	
	LL ans = 0;
	for(int k = 1; k <= n; k++) {
		LL large = 0, p = 0;
		for(int i = 1; i <= top; i++) {
			if(vis_p[i]) {
				continue;	
			}
			LL now = 0, t = 0;
			for(int j = a[i].x; j <= a[i].y; j++) {
				if(vis[j]) {
					t += now * now;
					now = 0;
				}
				else {
					now += h[j];
				}
			}
			t += now * now;
			if(t > large) {
				large = t;
				p = i;
			}
			if(!t) {
				vis_p[i] = 1;
			}
		}
		vis_p[p] = 1;
		ans += large;
		for(int i = a[p].x; i <= a[p].y; i++) {
			vis[i] = 1;
		}
	}
	
	printf("%lld\n", ans);
	return 0;
}

