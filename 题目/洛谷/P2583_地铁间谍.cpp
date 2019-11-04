#include <cstdio>
#include <cstring>
#include <algorithm>
#define rgi register int
#define il inline
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

int n, kase, d, T, m1, m2;
int t[550];
int dp[550][550], has_train[550][550][2];

int main()
{
	while(scanf("%d", &n) && n)
	{
		memset(dp, 0, sizeof(dp));
		memset(has_train, 0, sizeof(has_train));
		memset(t,0,sizeof(t));
		scanf("%d", &T);
		for(int i = 1; i <= n - 1; i++)
			scanf("%d", &t[i]);
		scanf("%d", &m1);
		for (int i = 1; i <= m1; i++)
		{
			scanf("%d", &d);
			for (int j = 1; j <= n; j++)
			{
				has_train[d][j][0] = 1;
				d += t[j];
			}
		}
		scanf("%d", &m2);
		for (int i = 1; i <= m2; i++) {
			scanf("%d", &d);
			for (int j = n; j >= 1; j--) {
				has_train[d][j][1] = 1;
				d += t[j - 1];
			}
		}
		for(int i = 1; i <= n - 1; i++)
			dp[T][i] = inf;
		dp[T][n] = 0;
		for(int i = T - 1; i >= 0; i--)
			for(int j = 1; j <= n; j++)
			{
				dp[i][j] = dp[i + 1][j] + 1;
				if(j < n && has_train[i][j][0] && i + t[j] <= T)
					dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);
				if(j > 1 && has_train[i][j][1] && i + t[j - 1] <= T)
					dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]);
			}
		printf("Case Number %d: ", ++kase);
		if(dp[0][1] >= inf)
			printf("impossible\n");
		else
			printf("%d\n", dp[0][1]);
	}
	return 0;
}

