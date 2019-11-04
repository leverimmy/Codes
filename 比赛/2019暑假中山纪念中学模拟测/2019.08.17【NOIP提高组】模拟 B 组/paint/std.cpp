#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 15 + 10;
const int M = 15 + 10;

int n, m, r, c, ans = oo;
int R[N], C[M], e[N][M];
char tmp[N][M];

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int cur_r, int cur_ans)
{
	if(cur_r >= n + 1)
	{
		memset(C, 0, sizeof(C));
		int tmp_ans = cur_ans;
		for(rgi i = 1; i <= m; ++i)
		{
			int flag = 0;
			if(C[i])
				continue;
			for(rgi j = 1; j <= n; ++j)
			{
				if(R[j])
					continue;
				if(e[j][i])
				{
					flag = 1;
					break;
				}
			}
			if(flag == 1)
			{
				for(rgi j = 1; j <= c; ++j)
					C[min(m, j + i - 1)] = 1;
				tmp_ans++;
			}
		}
		ans = min(ans, tmp_ans);
		return;
	}
	if(!R[cur_r])
	{
		for(rgi i = 1; i <= r; ++i)
			R[min(n, cur_r + i - 1)] = 1;
		dfs(cur_r + 1, cur_ans + 1);
		for(rgi i = 1; i <= r; ++i)
			R[min(n, cur_r + i - 1)] = 0;
	}
	dfs(cur_r + 1, cur_ans);
}

void Debug()
{
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= m; ++j)
			printf("%2d", e[i][j]);
		puts("");
	}
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
		scanf("%s", tmp[i] + 1);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j)
		{
			if(tmp[i][j] == 'X')
				e[i][j] = 1;
			else if(tmp[i][j] == '.')
				e[i][j] = 0;
		}
	r = read(), c = read();
//	Debug();
	dfs(1, 0);
	printf("%d", ans);
	return 0;
}
