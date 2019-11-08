#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, m, cnt, tot, idx;
int first[N], instk[N], dfn[N], low[N], color[N];

struct edge {
	int to, _next, wt;
} e[M];

std::stack <int> stk;

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

void Tarjan(int u) {
	
	dfn[u] = low[u] = ++idx;
	stk.push(u), instk[u] = 1;
	
	for(rgi i = first[u]; ~i; i = e[i]._next) {
		int v = e[i].to;
		
		if(!dfn[v]) {
			Tarjan(v);
			low[u] = std::min(low[u], low[v]);
		}
		else if(instk[v])
			low[u] = std::min(low[u], dfn[v]);
	}
	
	if(dfn[u] == low[u]) {
		++tot;
		while(stk.top() != u) {
			instk[stk.top()] = 0;
			color[stk.top()] = tot;
			stk.pop();
		}
		instk[u] = 0;
		color[u] = tot;
		stk.pop();
	}
}

int main() {
	freopen("10.in", "r", stdin);
	freopen("10.out", "w", stdout);
	while(std::cin >> n >> m) {
		memset(first, -1, sizeof(first));
		for(rgi i = 1; i <= m; ++i) {
			int u = read(), v = read();
			Add_Edge(u, v);
		}
		for(rgi i = 1; i <= n; ++i)
			if(!dfn[i])	Tarjan(i);
		printf("%d\n", tot);
		tot = cnt = 0;
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
	}
	return 0;
}
/*
3 3
1 2
2 3
3 1
2 1
1 2

*/

