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
const int N = 200 + 10;
const int M = 200 + 10;

int n, m, ans;
int e[M][N], f[M][N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int dfs(int x, int y)
{
	if(f[x][y] != -oo)	return f[x][y];
	if(x == 1)	return f[x][y] = e[x][y];
	int res = -oo;

	if(y >= 3)	res = max(res, dfs(x - 1, y - 2));
	if(y >= 2)	res = max(res, dfs(x - 1, y - 1));
	if(y >= 1)	res = max(res, dfs(x - 1, y));
	if(y <= n - 1)	res = max(res, dfs(x - 1, y + 1));
	if(y <= n - 2)	res = max(res, dfs(x - 1, y + 2));
	
	return f[x][y] = res + e[x][y];	
}

int main()
{
//	freopen("moneyleft.in", "r", stdin);
//	freopen("moneyleft.out", "w", stdout);
	m = read(), n = read();
	for(rgi i = 0; i < M; ++i)
		for(rgi j = 0; j < N; ++j)
			f[i][j] = -oo;
	for(rgi i = 1; i <= m; ++i)
		for(rgi j = 1; j <= n; ++j)
			e[i][j] = read();
	int mid = n + 1 >> 1;
	if(n == 1)
	{
		ans = max(ans, dfs(m, mid));
	}
	if(n == 3)
	{
		ans = max(ans, dfs(m, mid - 1));
		ans = max(ans, dfs(m, mid));
		ans = max(ans, dfs(m, mid + 1));
	}
	if(n >= 5)
	{
		ans = max(ans, dfs(m, mid - 2));
		ans = max(ans, dfs(m, mid - 1));
		ans = max(ans, dfs(m, mid));
		ans = max(ans, dfs(m, mid + 1));
		ans = max(ans, dfs(m, mid + 2));
	}
	printf("%d", ans);
	/*puts("");
	for(rgi i = 1; i <= m; ++i)
	{
		for(rgi j = 1; j <= n; ++j)
			printf("%5d", dfs(i, j));
		puts("");
	}*/
	return 0;
}
/*
6 7
16 4 3 12 6 0 3
4 -5 6 7 0 0 2
6 0 -1 -2 3 6 8
5 3 4 0 0 -2 7
-1 7 4 0 7 -5 6
0 -1 3 4 12 4 2

*/
