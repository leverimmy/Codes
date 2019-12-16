#include <cstdio>
#include <cstring>

const int N = 25;

int n, s, a[N], f[N][8300]; 

bool DFS(int k, int rest) {
	if(rest == 1) {
		return 0;
	}
	if(k > n) {
		k = 1;
	}
	if(f[k][rest] != -1) {
		return f[k][rest];
	}
	int ans = 0;
	for(int i = 1; i <= rest - 1 && i <= a[k]; i++) {
		int t = DFS(k + 1, rest - i);
		if(!t) {
			ans = 1;
		}
	}
	return f[k][rest] = ans;
}

inline void solve() {
	scanf("%d", &s);
	n <<= 1;
	memset(f, -1, sizeof(f));
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	printf("%d\n", DFS(1, s));
	return;
}

int main() {
	
//	freopen("game.in", "r", stdin);
//	freopen("game.out", "w", stdout);
	
	while(scanf("%d", &n), n) {
		solve();
	}
	return 0;
}
