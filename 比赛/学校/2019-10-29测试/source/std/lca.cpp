#include <cstdio>
#include <cstdlib>
#include <algorithm>
const int dE = 20;
using namespace std;

typedef int arr32[200010];

arr32 c, next, g, d;
int f[200010][21];
int n, m, x, y, ap, lta, root;

void link(int x, int y)
{
	c[++ap] = y, next[ap] = g[x], g[x] = ap;
	c[++ap] = x, next[ap] = g[y], g[y] = ap;
}
void dfs(int z, int ft)
{
	d[z] = d[ft] + 1;  f[z][0] = ft;
	for (int i = 0; f[z][i]; ++i)
		f[z][i + 1] = f[f[z][i]][i];

	for (int x = g[z]; x; x = next[x])
		if (c[x] != ft)
			dfs(c[x], z);
}
int lca(int x, int y)
{
	if (x == y)  return x;
	if (d[x] < d[y])  swap(x, y);
	for (int i = dE; i >= 0; --i)
		if (((d[x] - d[y]) >> i) & 1)
			x = f[x][i];

	if (x == y)  return x;
	for (int i = dE; i >= 0; --i)
		if (f[x][i] != f[y][i])
			x = f[x][i], y = f[y][i];

	return f[x][0];
}
int main()
{
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)  {
		scanf("%d", &x);
		if (x)  link(i, x);
		else  root = i;
	}

	dfs(root, 0);
	
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)  {
		scanf("%d %d", &x, &y);
		x ^= lta, y ^= lta;
		
		printf("%d\n", lta = lca(x, y));
	}
}
