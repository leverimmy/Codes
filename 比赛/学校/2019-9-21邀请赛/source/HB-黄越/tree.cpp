#include <algorithm>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <cctype>
#include <vector>
#include <queue>
using namespace std;

const int N = 100003, M = 1000015;
struct E { int fr, to, w; E(int a=0, int b=0, int c=0): fr(a), to(b), w(c) {} };
bool operator<(const E& a, const E& b) { return a.w < b.w; }
int f[N], g[N];
vector<E> v[N]; E d[M];
int _(int x) { return x == f[x] ? x : f[x] = _(f[x]); }

int read() {
	int x, c;
	while (!isdigit(c = getchar())); x = c - 48;
	while (isdigit(c = getchar())) x = x * 10 + c - 48;
	return x;
}

void dfs(int x = 1, int fa = 0) {
	for (int i = 0; i < v[x].size(); ++i)
		if (v[x][i].to != fa)
			g[v[x][i].to] = max(g[x], v[x][i].w),
			dfs(v[x][i].to, x);
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int n = read(), m = read(), cnt = 1;
	for (int i = 0, a, b, w; i < m; ++i)
		a = read(), b = read(), w = read(),
		d[i] = E(a, b, w);
	sort(d, d + m);
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 0; i < m && cnt < n; ++i) {
		if (_(d[i].fr) != _(d[i].to))
			f[_(d[i].fr)] = _(d[i].to),
			v[d[i].fr].push_back(E(d[i].fr, d[i].to, d[i].w)),
			v[d[i].to].push_back(E(d[i].to, d[i].fr, d[i].w)),
			++cnt;
	}
	dfs();
	printf("%d\n", accumulate(g + 2, g + n + 1, 0));
	return 0;
}
