#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <set>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, cnt1, cnt2, ans;
int first1[N], first2[N], dep1[N], dep2[N], lg2[N] = {-1};
int f1[N][50], f2[N][50];

struct edge {
	int to, _next;
} e1[M << 1], e2[M << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge1(int u, int v) {
	e1[cnt1].to = v;
	e1[cnt1]._next = first1[u];
	first1[u] = cnt1++;
}

void Add_Edge2(int u, int v) {
	e2[cnt2].to = v;
	e2[cnt2]._next = first2[u];
	first2[u] = cnt2++;
}

void dfs1(int x, int p) {
	dep1[x] = dep1[p] + 1;
	f1[x][0] = p;
	for(rgi i = 1; i <= lg2[dep1[x]]; ++i)
		f1[x][i] = f1[f1[x][i - 1]][i - 1];
	for(rgi i = first1[x]; ~i; i = e1[i]._next) {
		if(e1[i].to != p) {
			dfs1(e1[i].to, x);
		}
	}
}

void dfs2(int x, int p) {
	dep2[x] = dep2[p] + 1;
	f2[x][0] = p;
	for(rgi i = 1; i <= lg2[dep2[x]]; ++i)
		f2[x][i] = f2[f2[x][i - 1]][i - 1];
	for(rgi i = first2[x]; ~i; i = e2[i]._next) {
		if(e2[i].to != p)
			dfs2(e2[i].to, x);
	}
}

int lca1(int u, int v) {
	if(dep1[u] >dep1[v])	swap(u, v);
	int tmp = dep1[v] - dep1[u];
	for(rgi i = 0; i <= lg2[dep1[v]]; ++i)
		if(tmp & (1 << i))
			v = f1[v][i];
	if(u == v)	return u;
	for(rgi i = lg2[dep1[v]]; i >= 0; --i)
		if(f1[u][i] != f1[v][i]) {
			u = f1[u][i];
			v = f1[v][i];
		}
	return f1[u][0];
}

int lca2(int u, int v) {
	if(dep2[u] >dep2[v])	swap(u, v);
	int tmp = dep2[v] - dep2[u];
	for(rgi i = 0; i <= lg2[dep2[v]]; ++i)
		if(tmp & (1 << i))
			v = f2[v][i];
	if(u == v)	return u;
	for(rgi i = lg2[dep2[v]]; i >= 0; --i)
		if(f2[u][i] != f2[v][i]) {
			u = f2[u][i];
			v = f2[v][i];
		}
	return f2[u][0];
}

int main() {
//	freopen("2553.in", "r", stdin);
//	freopen("2553.out", "w", stdout);
	n = read();
	memset(first1, -1, sizeof(first1));
	memset(first2, -1, sizeof(first2));
	for(rgi i = 1; i <= n; ++i)	lg2[i] = lg2[i >> 1] + 1;
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		Add_Edge1(u, v);
		Add_Edge1(v, u);
	}
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		Add_Edge2(u, v);
		Add_Edge2(v, u);
	}
	
	dfs1(1, 0);
	dfs2(1, 0);
	
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1; j <= n; ++j)	if(i != j)
		ans += lca1(i, j) == i && lca2(i, j) == i;
	
	printf("%d", ans);
	return 0;
}
/*
4
1 2
2 3
3 4
1 2
2 3
2 4

*/
