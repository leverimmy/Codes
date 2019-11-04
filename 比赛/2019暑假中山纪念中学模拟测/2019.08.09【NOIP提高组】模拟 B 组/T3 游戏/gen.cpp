#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>

int prime[1123], end;
void init()
{
	for (int i(2); i <= 1000; ++i)
	{
		bool fail(false);
		for (int j(2); j < i; ++j) if (i % j == 0) fail = true;
		if (!fail) prime[end++] = i;
	}
}
int n;
bool vis[1123][212];
long long dp[1123][212];
long long dfs(int n, int now)
{
	if (n < 0)
	{
		n = 0;
	}
	if (vis[n][now]) return dp[n][now];
	if (n == 0 || prime[now] > n || now == end) return 1;
	vis[n][now] = true;
	dp[n][now] = dfs(n, now + 1);
	long long mul(1);
	for (int i(1); mul * prime[now] <= n; ++i)
	{
		mul *= prime[now];
		dp[n][now] += dfs(n - mul, now + 1);
	}
	return dp[n][now];
}
int main()
{
	freopen("table.out", "w", stdout);
	init();
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		printf("%lld,", dfs(i, 0));
	return 0;
}
