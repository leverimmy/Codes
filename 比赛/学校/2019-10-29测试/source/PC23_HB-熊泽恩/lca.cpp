#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, cnt, root, LastAns;
int first[N], dep[N], f[N][20], lg2[N] = {-1};

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
	dep[x] = dep[p] + 1;
	f[x][0] = p;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; ~i ; i = e[i]._next)
		if(e[i].to != p)	dfs(e[i].to, x);
}

int lca(int u, int v) {
	if(dep[u] > dep[v])	swap(u, v);
	int tmp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(tmp & (1 << i))	v = f[v][i];
	if(u == v)	return u;
	for(rgi i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}

int main() {
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)	lg2[i] = lg2[i >> 1] + 1;
	for(rgi i = 1; i <= n; ++i) {
		int fa = read();
		if(!fa)	root = i;
		else {
			Add_Edge(fa, i);
			Add_Edge(i, fa);
		}
	}
	dfs(root, 0);
	m = read();
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read();
		int CurAns = lca(u ^ LastAns, v ^ LastAns);
		printf("%d\n", CurAns);
		LastAns = CurAns;
	}
	return 0;
}

