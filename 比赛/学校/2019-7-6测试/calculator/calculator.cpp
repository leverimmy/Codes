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
#define MOD 1000000007

using namespace std;

int s, t, k, ans;
int dp[3030][1010];//dp[i][j]->current number is i, and have used j steps, 's total ways

//dp[i][j] = dp[i + 1][j - 1] + dp[i - 1][j + 1];

//dp[i][j] = c[(i + j) >> 1][j]

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	s = read(), t = read(), k = read();
	dp[s][0] = 1;
	for(rgi j = 1; j <= k; ++j)
		for(rgi i = 0; i <= 2020; ++i)
		{
			if(i == 0)
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = (ll)(dp[i - 1][j - 1] + dp[i + 1][j - 1]) % MOD;
		}
	for(rgi i = 1; i <= k; ++i)
		ans = (ll)(ans + dp[t][i]) % MOD;
	printf("%d", ans);
	return 0;
}

