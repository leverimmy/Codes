#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 100 + 10;

int n, m, cnt1, cnt2, idx, tot;
int first1[N], first2[N], dfn[N], low[N], instk[N];
int W[N], V[N], tmpW[N], tmpV[N], col[N], E[N][N], f[N][N];

struct edge {
	int to, _next;
} e1[N << 1], e2[N << 1];

template <typename T> class stack {
	private:
		static const int MAX_SIZE = 2e5;
		int _top; T _s[MAX_SIZE + 10];
	public:
		void push(T val) {_s[++_top] = val;}
		void pop() {--_top;}
		T top() {return _s[_top];}
		bool empty() {return !_top;}
		void clear() {_top = 0;}
		stack() {clear();}
};

stack <int> stk;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge1(int u, int v) {e1[cnt1].to = v, e1[cnt1]._next = first1[u], first1[u] = cnt1++;}
void Add_Edge2(int u, int v) {e2[cnt2].to = v, e2[cnt2]._next = first2[u], first2[u] = cnt2++;}

void Tarjan(int u) {
	dfn[u] = low[u] = ++idx;
	stk.push(u), instk[u] = 1;
	for(rgi i = first1[u], v = e1[i].to; ~i; i = e1[i]._next, v = e1[i].to) {
		if(!dfn[v]) {
			Tarjan(v);
			low[u] = std::min(low[u], low[v]);
		}
		else if(instk[v])
			low[u] = std::min(low[u], dfn[v]);
	}
#define TOP stk.top()
	if(low[u] == dfn[u]) {
		++tot;
		while(TOP != u) {
			col[TOP] = tot;
			W[tot] += tmpW[TOP];
			V[tot] += tmpV[TOP];
			instk[TOP] = 0;
			stk.pop();
		}
		col[u] = tot, W[tot] += tmpW[u], V[tot] += tmpV[u], instk[u] = 0;
		stk.pop();
	}
}

void dfs(int x, int p) {
	
	for(rgi i = first2[x], y = e2[i].to; ~i; i = e2[i]._next, y = e2[i].to) if(y != x) {
		
		
	}
}

int main() {
	n = read(), m = read();
	memset(first1, -1, sizeof(first1));
	memset(first2, -1, sizeof(first2));
	for(rgi i = 1; i <= n; ++i) tmpW[i] = read();
	for(rgi i = 1; i <= n; ++i) tmpV[i] = read();
	for(rgi i = 1; i <= n; ++i) {
		int fa = read();
		Add_Edge1(fa, i);
		E[fa][i] = 1;
	}
	for(rgi i = 0; i <= n; ++i) if(!dfn[i])
		Tarjan(i);
	for(rgi i = 0; i <= n; ++i) for(rgi j = 0; j <= n; ++j) if(E[i][j] && col[i] != col[j])
		Add_Edge2(col[i], col[j]);
	dfs(0, -1);
	printf("%d", f[0]);
	return 0;
}

