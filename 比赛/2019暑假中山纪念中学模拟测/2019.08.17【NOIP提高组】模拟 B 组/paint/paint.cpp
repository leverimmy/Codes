#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 15 + 10;
const int M = 15 + 10;

int n, m, r, c, ans = oo;
char tmp[N][M];
int e[N][M];
int R[N], C[M];

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int left_r, int left_c, int cur_ans)
{
	/*if(left_r <= 0 && left_c <= 0)
	{
		ans = min(ans, cur_ans);
		return;
	}
	if(left_r == 1)
	{
		int flag = 0;
		for(rgi i = 1; i <= n; ++i)
		{
			if(R[i])
				continue;
			for(rgi j = 1; j <= m; ++j)
				if(e[i][j])
				{
					flag = 1;
					break;
				}
			break;
		}
		if(flag)
			ans = min(ans, cur_ans + 1);
		else
			ans = min(ans, cur_ans);
		return;
	}
	if(left_c == 1)
	{
		int flag = 0;
		for(rgi i = 1; i <= m; ++i)
		{
			if(C[i])
				continue;
			for(rgi j = 1; j <= n; ++j)
				if(e[j][i])
				{
					flag = 1;
					break;
				}
			break;
		}
		if(flag)
			ans = min(ans, cur_ans + 1);
		else
			ans = min(ans, cur_ans);
		return;
	}*/
	int fflag = 0;
	for(rgi i = 1; i <= n; ++i)
	{
		int flag = 0;
		if(R[i])
			continue;
		for(rgi j = 1; j <= m; ++j)
		{
			if(C[j])
				continue;
			if(e[i][j])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			fflag = 1;
			break;
		}
	}
	if(!fflag)
		ans = min(ans, cur_ans);
	for(rgi i = 1; i <= n; ++i)
	{
		if(R[i])
			continue;
		int flag = 1;
		for(rgi j = 1; j <= m; ++j)
		{
			if(C[j])
				continue;
			if(e[i][j])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			continue;
		R[i] = 1;
		dfs(left_r - 1, left_c, cur_ans + 1);
		R[i] = 0;
	}
	for(rgi i = 1; i <= m; ++i)
	{
		if(C[i])
			continue;
		int flag = 1;
		for(rgi j = 1; j <= n; ++j)
		{
			if(R[j])
				continue;
			if(e[j][i])
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			continue;
		C[i] = 1;
		dfs(left_r, left_c - 1, cur_ans + 1);
		C[i] = 0;
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
			if(tmp[i][j] == '.')
				e[i][j] = 0;
			else if(tmp[i][j] == 'X')
				e[i][j] = 1;
		}
	r = read(), c = read();
	dfs(n, m, 0);
	printf("%d", ans);
	return 0;
}
