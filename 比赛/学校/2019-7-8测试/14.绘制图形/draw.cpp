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
#define maxn 110
using namespace std;
int n, flag = 0;
int e[maxn][maxn];
il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}
//d:
//0 up
//1 right
//2 down
//3 left
void dfs(int curx, int cury, int step, int d)
{
	if(flag)
		return;
	e[curx][cury] = step;
	if(step == n * n)
	{
		flag = 1;
		return;
	}
	if(d == 0)
	{
		if(e[curx][cury - 1] || cury == 1)
			dfs(curx + 1, cury, step + 1, 1);
		else
			dfs(curx, cury - 1, step + 1, 0);
	}
	else if(d == 1)
	{
		if(e[curx + 1][cury] || curx == n)
			dfs(curx, cury + 1, step + 1, 2);
		else
			dfs(curx + 1, cury, step + 1, 1);
	}
	else if(d == 2)
	{
		if(e[curx][cury + 1] || cury == n)
			dfs(curx - 1, cury, step + 1, 3);
		else
			dfs(curx, cury + 1, step + 1, 2);
	}
	else if(d == 3)
	{
		if(e[curx - 1][cury] || curx == 1)
			dfs(curx, cury - 1, step + 1, 0);
		else
			dfs(curx - 1, cury, step + 1, 3);
	}
}

int main()
{
//	freopen("test.out", "w", stdout);
	n = read();
	dfs(1, 1, 1, 1);
	if(n * n < 10)
	{
		for(rgi i = 1; i <= n; ++i)
		{
			for(rgi j = 1; j <= n; ++j)
				printf("%2d", e[j][i]);
			puts("");
		}
	}
	else if(10 <= n * n && n * n < 100)
	{
		for(rgi i = 1; i <= n; ++i)
		{
			for(rgi j = 1; j <= n; ++j)
				printf("%3d", e[j][i]);
			puts("");
		}
	}
	else if(100 <= n * n && n * n < 1000)
	{
		for(rgi i = 1; i <= n; ++i)
		{
			for(rgi j = 1; j <= n; ++j)
				printf("%4d", e[j][i]);
			puts("");
		}
	}
	return 0;
}
