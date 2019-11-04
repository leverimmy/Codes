#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define il inline

using namespace std;

const int N = 5e5 + 10;
const int M = 5e5 + 10;

int n, m, cnt, idx, tot;
int first[N], dep[N] = {-1}, c[N], dfn[N], ext[N];

struct edge {
	int to, _next;
} e[M << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void Add(int x, int val) {
	for(; x <= n; x += x & -x)	c[x] += val;
}

int Query(int x) {
	int res = 0;
	for(; x; x -= x & -x)	res += c[x];
	return res;	
}

void dfs(int x, int p) {
	dfn[x] = ++idx;
	dep[x] = dep[p] + 1;
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)	dfs(e[i].to, x);
	ext[x] = idx;
}

int main() {
//	freopen("meg.in", "r", stdin);
//	freopen("meg.out", "w", stdout);
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	dfs(1, 0);
	m = read();
	for(rgi i = 1; i <= n + m - 1; ++i) {
		char op[5]; scanf("%s", op);
		if(op[0] == 'A') {
			int u = read(), v = read();
			if(dep[u] < dep[v])	swap(u, v);
			Add(dfn[u], 1);
			Add(ext[u] + 1, -1);
		}
		else if(op[0] == 'W') {
			int u = read();
			printf("%d\n", dep[u] - Query(dfn[u]));
		}
	}
	return 0;
}
/*
5
1 2
1 3
1 4
4 5
4
W 5
A 1 4
W 5
A 4 5
W 5
W 2
A 1 2
A 1 3

9
1 2
1 3
2 4
2 5
4 6
3 7
3 8
3 9
0
A 2 4
W 6
A 1 2
W 5

*/
