#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 300 + 10;

int n, m, cnt;
int first[N], f[N][N];

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

int dfs(int x, int p) {
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(y != p) {
		dfs(y, x);
		for(rgi j = m + 1; j >= 1; --j) for(rgi k = 0; k <= j - 1; ++k)
			f[x][j] = std::max(f[x][j], f[y][k] + f[x][j - k]);
	}
}

int main() {
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i) {
		int u = read(), w = read();
		f[i][1] = w;
		Add_Edge(u, i);
		Add_Edge(i, u);
	} dfs(0, -1);
	printf("%d", f[0][m + 1]);
	return 0;
}

