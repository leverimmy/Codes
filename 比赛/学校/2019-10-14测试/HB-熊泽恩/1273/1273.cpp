#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5e4 + 10;
const int M = 5e4 + 10;

int n, k, cnt, last, _left, ans, id;
int first[N], dep[N], vis[N], pre[N];

struct edge {
	int to, _next;
} e[M << 1];

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

void dfs(int x, int p) {
	pre[x] = p;
	for(rgi i = first[x]; ~i; i = e[i]._next) {
		int y = e[i].to;
		if(y == p)	continue;
		if(!vis[y])	dep[y] = dep[x] + 1;
		else		dep[y] = dep[x];
		dfs(y, x);
	}
	if(dep[x] > ans || dep[x] == ans && x < id) {
		ans = dep[x];
		id = x;
	}
}

int main() {
//	freopen("1273.in", "r", stdin);
//	freopen("1273.out", "w", stdout);
	n = read(), k = read() + 1; last = k, _left = n - 1;
	
	memset(first, -1, sizeof(first));
	for(rgi i = 2; i <= n; ++i) {
		int j = read() + 1;
		Add_Edge(i, j);
		Add_Edge(j, i);
	}
//	dfs(k, 0);
//	for(rgi i = 1; i <= n; ++i)	printf("%d ", dep[i]);
	printf("%d\n", k - 1);
	while(_left + 1) {
//		memset(dep, 0, sizeof(dep));
//		memset(pre, -1, sizeof(pre));
		dfs(last, 0); ans = 0;
		printf("%d\n", id - 1);
		last = id;
		
		for(rgi i = id; i; i = pre[i]) {
			if(vis[i])	continue;
			vis[i] = 1;	_left--;
		}
	}
	return 0;
}
/*
7 2
0
1
2
2
1
4

*/
