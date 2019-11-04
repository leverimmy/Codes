#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <string>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int mod = 1e9 + 7;

int n, m, ans;

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int step, int pos, int cur_time)
{
	if(cur_time > m)
		return;
	if(cur_time + abs(pos) > m)
		return;
	if(step == n)
	{
		if(pos == 0)
			ans = (ans + 1) % mod;
		return;
	}
	if(pos == 0)
		cur_time = 0;
	dfs(step + 1, pos + 1, cur_time + 1);
	dfs(step + 1, pos - 1, cur_time + 1);
}

int main()
{
	n = read(), m = read();
	dfs(0, 0, 0);
	printf("%d", ans);
	return 0;
}

