#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 6e3 + 10;

int n, cnt, root;
int first[N], fa[N], f[N][2], w[N];

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
	f[x][0] = 0;
	f[x][1] = w[x];
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(y != p) {
		dfs(y, x);
		f[x][0] += std::max(f[y][0], f[y][1]);
		f[x][1] += f[y][0];
	}
}

int main() {
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i) w[i] = read();
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		fa[u] = v;
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	for(rgi i = 1; i <= n; ++i) if(!fa[i]) root = i;
	dfs(root, 0);
	printf("%d", std::max(f[root][0], f[root][1]));
	return 0;
}

