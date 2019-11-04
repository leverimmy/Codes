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
const int N = 1000 + 10;
const int M = 1000 + 10;

int n, m;
int a[N][M], vis[N][M], f[N][M];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cansee(int x, int y)
{
	return !(vis[x][y] || x > n || y > m);
}

int dfs(int x, int y)
{
	if(f[x][y])	return f[x][y];
	int res = oo;
	if(x == n && y == m)	return a[x - 1][y] + a[x][y - 1] + a[x][y];
	
	if(x < n)
	{
		res = min(res, dfs(x + 1, y) + (x + 2 <= n) * a[x + 2][y] + (y - 1 >= 1) * a[x + 1][y - 1] + (y + 1 <= m) * a[x + 1][y + 1]);
	}
	if(y < m)
	{
		res = min(res, dfs(x, y + 1) + (y + 2 <= m) * a[x][y + 2] + (x - 1 >= 1) * a[x - 1][y + 1] + (x + 1 <= n) * a[x + 1][y + 1]); 
	}
	
	return f[x][y] = res;
}

int main()
{
	freopen("lemouse.in", "r", stdin);
	freopen("lemouse.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
			a[i][j] = read();
	printf("%d", dfs(1, 1));
	/*puts("");for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= m; ++j)
			printf("%3d", f[i][j]);
		puts("");
	}*/
	return 0;
}
/*
3 9
0 0 1 0 0 0 0 0 1
1 1 1 1 1 1 0 1 0
1 0 0 1 0 0 1 0 0

*/
