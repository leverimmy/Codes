#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long

using namespace std;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void bfs(int x, int y)
{
	if(vis[x][y])
		return;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
			scanf("%1d", &e[i][j]);
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		bfs(u, v);
		printf("%d", ans);
	}
	return 0;
}

