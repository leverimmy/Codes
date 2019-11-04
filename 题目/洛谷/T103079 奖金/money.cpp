#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e4 + 10;
const int M = 2e4 + 10;

int n, m, cnt, cost, tot, ans;
int first[N], deg[N], vis[N], w[N];

queue <int> q;

struct edge {
	int to, _next;
} e[M];

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

void toposort() {
	while(1) {
		int ok = 1;
		for(rgi i = 1; i <= n; ++i) {
			if(!vis[i] && !deg[i]) {
				q.push(i);
				vis[i] = 1;
				ok = 0;
			}
		} 
		while(!q.empty()) {
			int x = q.front();	q.pop();
			tot++;	w[x] += cost;
			for(rgi i = first[x]; ~i; i = e[i]._next)	deg[e[i].to]--;
		}
		if(ok)	break;
		cost++;
	}
}

int main() {
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read();
		Add_Edge(v, u);	deg[u]++;
	}
	toposort();
	if(tot == n) {
		for(rgi i = 1; i <= n; ++i)	ans += w[i];
		printf("%d", ans + 100 * n);
	}
	else
		puts("Poor Xed");
	return 0;
}

