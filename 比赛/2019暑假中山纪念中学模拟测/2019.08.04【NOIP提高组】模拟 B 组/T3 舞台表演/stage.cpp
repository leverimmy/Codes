#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 200 + 10;

int n, m, x, y, k, ans = -oo, last;
char a[N][N];
int d[N], e[N][N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int cur_x, int cur_y, int cur_times, int step, int dist)
{
	if(e[cur_x][cur_y])
		return;
	if(step == last + 1)
	{
		ans = max(ans, dist);
		return;
	}
	if(cur_x == 1 && d[step] == 1)
		return;
	if(cur_x == n && d[step] == 2)
		return;
	if(cur_y == 1 && d[step] == 3)
		return;
	if(cur_y == n && d[step] == 4)
		return;
	//±ß½ç
	if(last - step + dist <= ans)
		return;
	//cut1
	dfs(cur_x, cur_y, cur_times + 1, step + 1, dist);
	if(d[step] == 1)
		dfs(cur_x - 1, cur_y, cur_times, step + 1, dist + 1);
	if(d[step] == 2)
		dfs(cur_x + 1, cur_y, cur_times, step + 1, dist + 1);
	if(d[step] == 3)
		dfs(cur_x, cur_y - 1, cur_times, step + 1, dist + 1);
	if(d[step] == 4)
		dfs(cur_x, cur_y + 1, cur_times, step + 1, dist + 1);
}

int main()
{
	n = read(), m = read(), x = read(), y = read(), k = read();
	for(rgi i = 1; i <= n; ++i)
		scanf("%s", a[i] + 1);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
			e[i][j] = a[i][j] == '.' ? 0 : 1;
	for(rgi i = 1; i <= k; ++i)
	{
		int l = read(), r = read(), dir = read();
		for(rgi j = l; j <= r; ++j)
			d[j] = dir;
		last = r;
	}
	dfs(x, y, 0, 0, 0);
	printf("%d", ans);
	return 0;
}

