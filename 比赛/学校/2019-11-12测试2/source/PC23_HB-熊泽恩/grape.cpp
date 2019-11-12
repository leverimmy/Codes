#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 2e5 + 10;
const int M = 4e5 + 10;

int n, m, T, cnt, flag = 1;
int first[N], color[N];

struct edge {
	int to, _next;
	int st, ed;
	// (start, end]
} e[M << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int st, int ed) {
	e[cnt].to = v;
	e[cnt].st = st;
	e[cnt].ed = ed;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int c, int tim) {
	
	color[x] = c;
	for(rgi i = first[x]; ~i && flag; i = e[i]._next) {
		if(tim <= e[i].st || tim > e[i].ed || color[e[i].to] == -c)
			continue;
		else if(color[e[i].to] == c) {
			flag = 0;
			return;
		}
		else if(flag)
			dfs(e[i].to, -c, tim);
	}
}

int main() {
	freopen("grape.in", "r", stdin);
	freopen("grape.out", "w", stdout);
	n = read(), m = read(), T = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read();
		int st = read(), ed = read();
		Add_Edge(u, v, st, ed);
		Add_Edge(v, u, st, ed);
	}
	for(rgi i = 1; i <= T; ++i, flag = 1) {
		for(rgi j = 1; j <= n && flag; ++j) {
			memset(color, 0, sizeof(color));
			dfs(j, 1, i);
		}
		puts(flag ? "Yes" : "No");
	}
	return 0;
}
/*
3 3 3
1 2 0 2
2 3 0 3
1 3 1 2

*/
