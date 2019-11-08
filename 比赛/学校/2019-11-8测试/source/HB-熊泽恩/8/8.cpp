#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e5 + 10;
const int M = 1e5 + 10;

int n, m, cnt, ans;
int first[N], vis[N], match[N];

struct edge {
	int to, _next;
} e[M];

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

bool Find(int x) {
	for(rgi i = first[x]; ~i; i = e[i]._next) {
		int y = e[i].to;
		if(vis[y])	continue;	vis[y] = 1;
		if(!match[y] || Find(match[y]))
			return 1;
	}
	return 0;
}

void Hungary() {
	for(rgi i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof(vis));
		if(!match[i])
			ans += Find(i);
	}
}

int main() {
	freopen("8.in", "r", stdin);
	freopen("8.out", "w", stdout);
	while(std::cin >> n >> m) {
		memset(first, -1, sizeof(first));
		for(rgi i = 1; i <= m; ++i) {
			int u = read(), v = read();
			Add_Edge(u, v + n);
		}
		Hungary();
		printf("%d\n", ans);
		ans = 0;
	}
	return 0;
}
/*
3 4
1 1
1 2
2 3
3 1

*/
