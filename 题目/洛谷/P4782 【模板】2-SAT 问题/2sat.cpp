#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n, m, cnt, idx, tot, flag;
int first[N << 1], instk[N << 1], dfn[N << 1], low[N << 1], belong[N << 1];

struct edge {
	int to, _next;
} e[M << 1];

struct STACK {
	static const int MAX_SIZE = 2e6 + 10;
	int _top, _stk[MAX_SIZE];
	void push(int val) {_stk[++_top] = val;}
	void pop() {_top--;}
	int top() {return _stk[_top];}
	bool empty() {return !_top;}
	void clear() {_top = 0;}
	STACK() {clear();}
} stk;

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

void Tarjan(int u) {
	
	dfn[u] = low[u] = ++idx;
	stk.push(u);	instk[u] = 1;
	
	for(rgi i = first[u]; ~i; i = e[i]._next) {
		int v = e[i].to;
		if(!dfn[v])	{
			Tarjan(v);
			low[u] = std::min(low[u], low[v]);
		}
		else if(instk[v])
			low[u] = std::min(low[u], dfn[v]);
	}
	
	if(dfn[u] == low[u]) {
		++tot;
		while(1) {
			int v = stk.top();	stk.pop();
			belong[v] = tot;
			instk[v] = 0;
			if(v == u)	break;
		}
	}
}

void solve() {
	for(rgi i = 1; i <= n && !flag; ++i)	flag |= belong[i] == belong[i + n];
}

int main() {
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	
	for(rgi i = 1; i <= m; ++i) {
		int a = read(), val1 = read(), b = read(), val2 = read();
		Add_Edge(a + (val1 ^ 1) * n, b + val2 * n);
		Add_Edge(b + (val2 ^ 1) * n, a + val1 * n);
	}
	
	for(rgi i = 1; i <= n << 1; ++i)	if(!dfn[i])	Tarjan(i);
	
	solve();
	
	if(!flag) {
		puts("POSSIBLE");
		for(rgi i = 1; i <= n; ++i)
			printf("%d ", belong[i] > belong[i + n]);
	}
	else
		puts("IMPOSSIBLE");
	return 0;
}
/*
3 1
1 1 3 0

10 10
3 0 2 0
10 1 9 0
2 1 4 0
10 1 2 1
2 1 2 0
10 1 9 1
2 1 4 0
10 0 9 1
1 1 8 1
8 0 2 1

*/
