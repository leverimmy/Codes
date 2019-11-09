#include <cstdio>
#include <algorithm>

const int N = 200010, INF = 0x3f3f3f3f;

int n, a[N], f[N], g[N], ta[N], x[N];

inline void add(int i, int v) {
	for(; i <= n; i += i & (-i)) {
		ta[i] = std::max(ta[i], v);
	}
	return;
}

inline int ask(int i) {
	int ans = 0;
	for(; i > 0; i -= i & (-i)) {
		ans = std::max(ans, ta[i]);
	}
	return ans;
}

int main() {

	freopen("gfw.in", "r", stdin);
	freopen("gfw.out", "w", stdout);

	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		x[i] = a[i];
	}
	std::sort(x + 1, x + n + 1);
	int X = std::unique(x + 1, x + n + 1) - x - 1;
	
	a[0] = -INF;
	a[n + 1] = INF;
	for(int i = 1; i <= n; i++) {
		if(a[i] > a[i - 1]) {
			f[i] = f[i - 1] + 1;
		}
		else {
			f[i] = 1;
		}
	}
	for(int i = n; i >= 1; i--) {
		if(a[i] < a[i + 1]) {
			g[i] = g[i + 1] + 1;
		}
		else {
			g[i] = 1;
		}
	}
	int ans = -INF;
	for(int i = 1; i <= n; i++) {
		int p = std::lower_bound(x + 1, x + X + 1, a[i]) - x;
		add(p, f[i]);
		p = ask(p - 1);
		ans = std::max(ans, p + g[i]);
		//printf("%d : %d + %d \n", i, p, g[i]);
	}
	
	printf("%d", ans);
	return 0;
}
