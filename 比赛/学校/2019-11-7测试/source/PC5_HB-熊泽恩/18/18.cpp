#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 5000 + 10;

int n, m, ans, p[N];

int Find(int x) {
	return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int a, int b) {
	int pa = Find(a), pb = Find(b);
	if(pa != pb)	p[pa] = pb;
}

int main() {
	freopen("18.in", "r", stdin);
	freopen("18.out", "w", stdout);
	std::cin >> n >> m;
	for(rgi i = 1; i <= n; ++i)	p[i] = i;
	for(rgi i = 1; i <= m; ++i) {
		int u, v;
		std::cin >> u >> v;
		Union(u, v);
	}
	for(rgi i = 1; i <= n; ++i)	ans += Find(i) == i;
	std::cout << ans;
	return 0;
}

