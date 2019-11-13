#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n, m, Q, cnt, tot;
int first[N], dis[N], vis[N];

struct edge {
	int to, _next, wt;
} e[M << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x - x / 10 * 10 + 48);
}

il void Add_Edge(int u, int v, int w) {
	e[++cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void dfs(int x, int p, int weight) {
	vis[x] = 1;
	dis[x] = dis[p] ^ weight;
	for(rgi i = first[x]; i; i = e[i]._next)
		if(e[i].to != p && !vis[e[i].to])	dfs(e[i].to, x, e[i].wt);
}

int main() {
	n = read(), m = read(), Q = read();
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	dfs(1, 0, 0);
	for(rgi i = 1; i <= Q; ++i) {
		int u = read(), v = read();
		write(dis[u] ^ dis[v]), putchar('\n');
	}
	return 0;
}
/*
3 2 3
1 2 2
2 3 3
1 3
1 2
2 3

*/
