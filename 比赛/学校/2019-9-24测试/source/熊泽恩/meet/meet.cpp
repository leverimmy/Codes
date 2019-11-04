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
const int N = 50 + 10;

int n, T, c_i = 1, h_i = 1, ans;
int c[N], h[N], vis[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int cur, int cur_ans, int cur_life)
{
	if(cur_life < 0)	return;
	ans = max(ans, cur_ans + 1);
	for(rgi i = 1; i <= n; ++i)
	{
		if(vis[i])	continue;
		vis[i] = 1;
		dfs(i, cur_ans + 1, cur_life - c[i] - abs(h[i] - h[cur]));
		vis[i] = 0;
	}
}

int main()
{
//	freopen("meet.in", "r", stdin);
//	freopen("meet.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		c[i] = read();
		if(c[i] != 0)	c_i = 0;
	}
	for(rgi i = 1; i <= n; ++i)
	{
		h[i] = read();
		if(h[i] != h[i - 1] && i != 1)	h_i = 0;
	}
	T = read();
	if(n <= 5)
	{
		for(rgi i = 1; i <= n; ++i)
		{
			memset(vis, 0, sizeof(vis));
			vis[i] = 1;
			dfs(i, 0, T - c[i]);
		}
		printf("%d", ans); 
	}
	else if(h_i)
	{
		sort(c + 1, c + n + 1);
		for(rgi i = 1; i <= n; ++i)
		{
			if(T >= c[i])
				T -= c[i], ans = max(ans, i);
			else
				break;
		}
		printf("%d", ans);
	}
	else if(c_i)
	{
		sort(h + 1, h + n + 1);
		for(rgi i = 1; i <= n - 1; ++i)
		{
			if(T >= h[i + 1] - h[i])
				T -= h[i + 1] - h[i];
			else
				break;
			ans = max(ans, i);
		}
		printf("%d", ans + 1);
	}
	return 0;
}
/*
4
3 5 4 11
2 1 3 1
17

4
4 3 5 6
3 3 3 3
17

4
0 0 0 0
5 11 18 26
21

*/
