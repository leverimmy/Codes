#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, cnt;
int first[N], dis[N];

struct edge {
	int to, _next, wt;
} e[M << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w) {
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int p, int w) {
	dis[x] = dis[p] ^ w;
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(y != p)
		dfs(y, x, e[i].wt);
}

int main() {
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	} dfs(1, 0, 0);
	m = read();
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read();
		printf("%d\n", dis[u] ^ dis[v]);
	}
	return 0;
}

