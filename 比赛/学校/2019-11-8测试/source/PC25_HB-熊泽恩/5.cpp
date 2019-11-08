#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e4 + 10;
const int M = 1e5 + 10;

int n, m, p[N];

struct edge {
	int u, v, w;
	bool operator < (const struct edge &rhs) const {
		return w < rhs.w;
	}
} E[M];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int Find(int x) {
	return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int a, int b) {
	int pa = Find(a), pb = Find(b);
	if(pa != pb)	p[pa] = pb;
}

bool Check(int a, int b) {
	return Find(a) == Find(b);
}

int main() {
	freopen("5.in", "r", stdin);
	freopen("5.out", "w", stdout);
	while(std::cin >> n >> m) {
		int sum = 0;
		for(rgi i = 1; i <= n; ++i)
			p[i] = i;
		for(rgi i = 1; i <= m; ++i)
			E[i].u = read(), E[i].v = read(), E[i].w = read();
		std::sort(E + 1, E + m + 1);
		for(rgi i = 1, tot = 0; i <= m && tot <= n - 1; ++i) {
			if(Check(E[i].u, E[i].v))
				continue;
			sum += E[i].w;
			Union(E[i].u, E[i].v);
			tot++;
		}
		printf("%d\n", sum);
	}
	return 0;
}

