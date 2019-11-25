#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 1e4 + 10;
const int M = 1e4 + 10;

int n, m, cnt, tot, SIZE, MX, root;
int first[N], dep[N], siz[N], max_part[N], vis[N], task[10000000 + 10];

struct edge {
	int to, _next, wt;
} e[M << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w) {
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void getRoot(int x, int p) {
	siz[x] = 1, max_part[x] = 0;
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(!vis[y] && y != p) {
		getRoot(y, x);
		max_part[x] = std::max(max_part[x], siz[y]); 
		siz[x] += siz[y];
	}
	max_part[x] = std::max(max_part[x], SIZE - siz[x]);
	if(max_part[x] < MX) {root = x, MX = max_part[x];}
}

void getDis(int x, int p, int w) {
	dep[++tot] = w;
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(!vis[y] && y != p)
		getDis(y, x, w + e[i].wt);
}

int Solve(int x, int len, int op) {
	tot = 0;
	getDis(x, 0, len);
	std::sort(dep + 1, dep + tot + 1);
	for(rgi i = 1; i <= tot; ++i) for(rgi j = 1; j <= tot; ++j) if(i != j)
		task[dep[i] + dep[j]] += op;
}

void Divide(int x) {
	vis[x] = 1;
	Solve(x, 0, 1);
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(!vis[y]) {
		Solve(y, e[i].wt, -1);
		MX = oo, SIZE = siz[y];
		getRoot(y, x);
		Divide(root);
	}
}

int main() {
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	SIZE = n, MX = oo;
	getRoot(1, 0);
	Divide(root);
	for(rgi i = 1; i <= m; ++i) {
		int val = read();
		puts(task[val] ? "AYE" : "NAY");
//		printf("ans:%d\n", task[val]);
	}
	return 0;
}
/*
7 9
1 2 13
1 3 15
1 4 16
4 5 12
5 6 18
4 7 5
34
7
30
45
49
31
10
10
45

*/
