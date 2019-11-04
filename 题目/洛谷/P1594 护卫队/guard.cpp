#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define il inline
#define ll long long
#define rgi register ll
#define maxn 1010

using namespace std;

int max_w, len, n;
int lg2[maxn] = { -1, 0}, w[maxn], v[maxn];
ll sum_w[maxn];
double f[maxn][50], dp[maxn];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

double RMQ(int l, int r)
{
	int len = lg2[r - l + 1];
	return max(f[l][len], f[r - (1 << len) + 1][len]);
}

int main()
{
	max_w = read(), len = read(), n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		w[i] = read();
		sum_w[i] = sum_w[i - 1] + w[i];
		v[i] = read();
		dp[i] = f[i][0] = (double)len / v[i];
		lg2[i] = lg2[i >> 1] + 1;
	}
	for(rgi j = 1; j <= lg2[n]; ++j)
		for(rgi i = 1; i + (1 << j) - 1 <= n; ++i)
			f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
	for(rgi i = 1; i <= n; ++i)
	{
		dp[i] += dp[i - 1];
		for(rgi j = i - 1; j >= 1; --j)
		{
			if(sum_w[i] - sum_w[j - 1] <= max_w)//[j,i] -> on the bridge
				dp[i] = min(dp[i], dp[j - 1] + RMQ(j, i));
			else
				break;
		}
	}
	printf("%.1f", 60 * dp[n]);
	return 0;
}

