#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define il inline

using namespace std;

int n, m, L, cnt, tot;
int first[N], dep[N], lg2[N] = {-1}, f[N][20];

struct edge {
	int to, _next, wt;
} e[M << 1];

struct EDGE {
	int u, v, w;
} E[M];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w) {
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int p) {
	dep[x] = dep[p] + 1;
	f[x][0] = 1;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
		f[x][i] = f[f[x][i - 1]][i - 1];
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)	dfs(e[i].to, x);
}

int lca(int u, int v) {
	if(dep[u] > dep[v])	swap(u, v);
	int tmp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(tmp & (1 << i))
			v = f[v][i];
	if(u == v)	return u;
	for(rgi i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}

void spfa(int s) {
	memset(inq, 0, sizeof(inq));
	memset(dis, 0x3f, sizeof(dis));
	q.push(s), inq[s] = 1, dis[s] = 0;
	while(!q.empty()) {
		int x = q.front(); q.pop();	inq[x] = 0; 
		for(rgi i = first[x]; ~i; i = e[i]._next) {
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt) {
				dis[y] = dis[x] + e[i].wt;
				if(!inq[y]) {
					inq[y] = 1;
					q.push(y);
				}
			}
		}
	}
}

int main() {
	n = read(), m = read(), L = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
		if(w > L)	continue;
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	q =	read();
	for(rgi i = 1; i <= q; ++i) {
		int s = read(), t = read();
		spfa(s);
			
	}
	return 0;
}

