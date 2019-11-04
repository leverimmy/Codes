#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

using namespace std;

const int N = 2e5 + 10;
const int M = 2e5 + 10;

int n, m, cnt;
int a[N], ans[N], first[N], vis[N];

struct djs {
	int p[N], siz[N];
	int find(int x) {return x == p[x] ? x : p[x] = find(p[x]);}
	void _union(int a, int b) {
		int pa = find(a), pb = find(b);
		if(pa != pb) {
			p[pa] = pb;
			siz[pb] += siz[pa];
		}
	}
	int size(int x) {return siz[find(x)];}
	void init() {for(rgi i = 1; i < N; ++i)	p[i] = i, siz[i] = 1;}
	djs() {init();}
} d;

struct edge {
	int to, _next;
} e[M << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

int main() {
	freopen("migration.in", "r", stdin);
	freopen("migration.out", "w", stdout);
	n = read(), m = read();
	memset(first, -1, sizeof(first));
#define t 0
	for(rgi i = 1; i <= m; ++i)	{
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	
	for(rgi i = n; i >= 1; --i) {
		for(rgi j = first[a[i]]; ~j; j = e[j]._next) {
			int k = e[j].to;
			if(!vis[k])	continue;
			d._union(a[i], k);
		}
		ans[i] = d.size(a[i]) == n - i + 1;
		vis[a[i]] = 1;
	}
	for(rgi i = 1; i <= n; ++i)	ans[i] ? puts("YES") : puts("NO");
	return 0;
}
/*
4 3
1 2
2 3
3 4
3
4
1
2

*/
