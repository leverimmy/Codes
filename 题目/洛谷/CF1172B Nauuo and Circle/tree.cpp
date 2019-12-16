#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int mod = 998244353;
const int N = 2e5 + 10;

int n, cnt, first[N], son[N];
ll fac[N] = {1}, f[N];

struct edge {
	int to, _next;
} e[N << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int p) {
	f[x] = 1LL;
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(y != p) {
		dfs(y, x);
		f[x] = f[x] * f[y] % mod;
		son[x]++;
	}
	f[x] = f[x] * fac[son[x] + (x != 1)] % mod;
}

int main() {
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	dfs(1, 0);
	printf("%lld", n * f[1] % mod);
	return 0;
}

