#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 1e4 + 10;
const int M = 1e4 + 10;

int n, m, root, cnt;
int first[N], sum[N], siz[N], ans[N];

struct edge {
	int to, _next;
} e[M << 1];

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
	siz[x] = 1;
	for(rgi i = first[x]; ~i; i = e[i]._next) if(e[i].to != p) {
		dfs(e[i].to, x);
		sum[x] += siz[e[i].to] * siz[e[i].to];
		siz[x] += siz[e[i].to];
	}
	ans[x] = siz[x] * siz[x] - sum[x];
}

int main() {
	n = read(), root = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	
	dfs(root, 0);
	
	for(rgi i = 1; i <= m; ++i) {
		int k = read();
		printf("%d\n", ans[k]);
	}
	
	return 0;
}

