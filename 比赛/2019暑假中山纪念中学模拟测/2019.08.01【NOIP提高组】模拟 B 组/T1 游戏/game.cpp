#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int
#define maxn 1010

using namespace std;

int T, ans;
bool e[maxn][maxn];
bool hang[maxn], lie[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int x, int y, int step)
{
	if(x == 1 && hang[x] == 0 || y == 1 && lie[y] == 0)//边界
	{
		if(step & 1)
			ans = 0;
		else
			ans = -1;
		return;
	}
	if(x == 1 && hang[x] == 1 || y == 1 && lie[y] == 1)
	{
		if(step & 1)
			ans = -1;
		else
			ans = 0;
		return;
	}
	if(hang[x] == 1 && lie[y] == 1)
	{
		if(step & 1)
			ans = -1;
		else
			ans = 0;
		return;
	}
	if(hang[x] == 1 && lie[y] == 0)
	{
		for(rgi i = 1; i <= x; ++i)
			hang[i] = hang[i] ^ e[i][y];
		dfs(x, y - 1, step + 1);
		for(rgi i = 1; i <= x; ++i)
			hang[i] = hang[i] ^ e[i][y];
	}
	if(hang[x] == 0 && lie[y] == 1)
	{
		for(rgi i = 1; i <= y; ++i)
			lie[i] = lie[i] ^ e[x][i];
		dfs(x - 1, y, step + 1);
		for(rgi i = 1; i <= y; ++i)
			lie[i] = lie[i] ^ e[x][i];
	}
	if(hang[x] == 0 && hang[y] == 0)
	{
		if(hang[x - 1] == 0 && lie[y - 1] == 1)
		{
			for(rgi i = 1; i <= x; ++i)
				hang[i] = hang[i] ^ e[i][y];
			dfs(x, y - 1, step + 1);
			for(rgi i = 1; i <= x; ++i)
				hang[i] = hang[i] ^ e[i][y];
		}
		else if(hang[x - 1] == 1 && lie[y - 1] == 0)
		{
			for(rgi i = 1; i <= y; ++i)
				lie[i] = lie[i] ^ e[x][i];
			dfs(x - 1, y, step + 1);
			for(rgi i = 1; i <= y; ++i)
				lie[i] = lie[i] ^ e[x][i];
		}
		else
		{
			for(rgi i = 1; i <= x; ++i)
				hang[i] = hang[i] ^ e[i][y];//修改
			dfs(x, y - 1, step + 1);
			for(rgi i = 1; i <= x; ++i)
				hang[i] = hang[i] ^ e[i][y];//还原
			for(rgi i = 1; i <= y; ++i)
				lie[i] = lie[i] ^ e[x][i];//修改
			dfs(x - 1, y, step + 1);
			for(rgi i = 1; i <= y; ++i)
				lie[i] = lie[i] ^ e[x][i];//还原
		}
	}
}

int main()
{
	freopen("game8.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	T = read();
	for(; T; T--)
	{
		int n = read();
		ans = 0;
		memset(hang, 0, sizeof(hang));
		memset(lie, 0, sizeof(lie));
		for(rgi i = 1; i <= n; ++i)
			for(rgi j = 1; j <= n; ++j)
				e[i][j] = read() & 1;
		for(rgi i = 1; i <= n; ++i)
			for(rgi j = 1; j <= n; ++j)
				hang[i] = hang[i] ^ e[i][j];
		for(rgi j = 1; j <= n; ++j)
			for(rgi i = 1; i <= n; ++i)
				lie[j] = lie[j] ^ e[i][j];
		dfs(n, n, 1);
		if(ans == -1)
			puts("L");
		else
			puts("W");
	}
	return 0;
}
