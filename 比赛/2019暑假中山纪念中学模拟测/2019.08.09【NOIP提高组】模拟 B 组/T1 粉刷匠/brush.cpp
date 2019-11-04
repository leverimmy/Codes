#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 50 + 10;
const int M = 50 + 10;

int n, m, T, ans;
int a[N][M];
char e[N][M];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int x, int y, int step, int cur_ans)
{
	if(x == n && y == m + 1 && step <= T)
	{
		ans = max(ans, cur_ans);
		return;
	}
	if(step >= T)
		return;
	if(y == m + 1)
		dfs(x + 1, 1, step, cur_ans);
	for(rgi len = 1; len <= m - y + 1; ++len)
	{
		int tmp = 0;
		for(rgi i = y; i <= min(m, y + len - 1); ++i)
			tmp += a[x][i] == 1;
		dfs(x, min(m, y + len - 1) + 1, step + 1, cur_ans + tmp);
		tmp = 0;
		for(rgi i = y; i <= min(m, y + len - 1); ++i)
			tmp += a[x][i] == 0;
		dfs(x, min(m, y + len - 1) + 1, step + 1, cur_ans + tmp);
	}
}

int main()
{
	n = read(), m = read(), T = read();
	for(rgi i = 1; i <= n; ++i)
		scanf("%s", e[i] + 1);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
			a[i][j] = e[i][j] - '0';
	dfs(1, 1, 0, 0);
	printf("%d", ans);
	return 0;
}

