#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const int N = 5e4 + 10;
const int M = 5e4 + 10;

int n, cnt, tot, SIZE, root;
int first[N], siz[N], max_part[N], vis[N];

ll W, MX, ans, dep[N];

struct edge {
	int to, _next;
} e[M << 1];

void Add_Edge(int u, int v) {
	e[cnt].to = v;
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

void getDis(int x, int p, ll w) {
	dep[++tot] = w;
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(!vis[y] && y != p)
		getDis(y, x, w + 1);
}

int Solve(int x, int len, ll w) {
	tot = 0;
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
	L = 1, R = tot;
	while(L <= R) {
		if(dep[L] + dep[R] < w) {
			cur_ans -= R - L;
			L++;
		}
		else
			R--;
	}
	return cur_ans;
}

void Divide(int x, ll w) {
	vis[x] = 1;
	ans += Solve(x, 0, w);
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(!vis[y]) {
		ans -= Solve(y, 1, w);
		MX = oo, SIZE = siz[y];
		getRoot(y, x);
		Divide(root, w);
	}
}

int main() {
	scanf("%d %lld", &n, &W);
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n - 1; ++i) {
		int u, v; ll w;
		scanf("%d %d", &u, &v);
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	SIZE = n, MX = oo;
	getRoot(1, 0);
	Divide(root, W);
	printf("%I64d", ans);
	return 0;
}
/*
5 2
1 2
2 3
3 4
2 5

*/
