#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

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
	fa[x] = p;
	dis[x] = dis[p] + w[x];
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)	dfs(e[i].to, x);
}

int main() {
//	freopen("attack.in", "r", stdin);
//	freopen("attack.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)	w[i] = read();
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	dfs(1, 0);
	
	for(rgi i = 1; i <= n; ++i)
		if(dis[i] > max_depth) {
			max_depth = dis[i];
			root1 = i;
		}
	
	dfs(root1, 0);	max_depth = -1;
	
	for(rgi i = 1; i <= n; ++i)
		if(dis[i] > max_depth) {
			max_depth = dis[i];
			root2 = i;
		}
	
	return 0;
}

