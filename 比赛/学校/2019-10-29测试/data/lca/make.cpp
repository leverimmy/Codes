#include <ctime>
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
	freopen("lca.in", "w", stdout);
	FILE *out = fopen("lca.out", "w");
	srand((unsigned)time(NULL));
	
  n = 10;
	printf("%d\n", n);
	printf("0 ");
	root = 1;
	for (int i = 2; i <= n; ++i)  {
		x = i - (rand() * rand() % 5 + 1);
		if (x <= 0)  x = 1;
		link(i, x);
		printf("%d ", x);
	}
	
	printf("\n");
	dfs(root, 0);
	
	m = 10;
	printf("%d\n", m);
	for (int i = 1; i <= m; ++i)  {
    x = rand() % n + 1;
    y = rand() % n + 1;
		printf("%d %d\n", x ^ lta, y ^ lta); 
		fprintf(out, "%d\n", lta = lca(x, y));
	}
}
