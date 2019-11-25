#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 4e4 + 10;
const int M = 4e4 + 10;

int n, W, cnt, tot, SIZE, MX, root, ans;
int first[N], dep[N], siz[N], max_part[N], vis[N];

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

int Solve(int x, int len, int w) {
	tot = 0;
//	memset(dep, 0, sizeof(dep));
	getDis(x, 0, len);
	std::sort(dep + 1, dep + tot + 1);
	int L = 1, R = tot, cur_ans = 0;
	while(L <= R) {
		if(dep[L] + dep[R] <= w) {
			cur_ans += R - L;
			L++;
		}
		else
			R--;
	}
	return cur_ans;
}

void Divide(int x, int w) {
	vis[x] = 1;
	ans += Solve(x, 0, w);
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(!vis[y]) {
		ans -= Solve(y, e[i].wt, w);
		MX = oo, SIZE = siz[y];
		getRoot(y, x);
		Divide(root, w);
	}
}

int main() {
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	W = read();
	SIZE = n, MX = oo;
	getRoot(1, 0);
	Divide(root, W);
	printf("%d", ans);
	return 0;
}
/*
7
1 6 13
6 3 9
3 5 7
4 1 3
2 4 20
4 7 2
10

*/
