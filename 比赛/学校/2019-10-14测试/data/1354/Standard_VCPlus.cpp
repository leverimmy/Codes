#include <iostream>
#include<time.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string.h>
#include<assert.h>
using namespace std;
typedef __int64 lld;
const int BIT = 100;
const int MAX = 10020;
const int MOD = 1000000007;
int d[MAX], c;
int a[MAX];
int dp[MAX];
int splite(int d[], int n)
{
	int i, len = 0;
	for (i = 1; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			d[len++] = i;
			if (i*i != n)d[len++] = n / i;
		}
	}
	sort(d, d + len);
	return len;
}
int bin(lld aim, int low, int high)
{
	lld ret = -1;
	while (low <= high)
	{
		int mid = low + high >> 1;
		if (aim == d[mid])return mid;
		if (d[mid]<aim)
		{
			low = mid + 1;
		}
		else high = mid - 1;
	}
	return ret;
}
int main()
{
	int i, j, k;
	int T, n,ioflag;
	//freopen("E:/1002.in", "r", stdin);
	//freopen("E:/1002.out", "w", stdout);
	ioflag=scanf("%d", &T);
	assert(ioflag == 1);
	while (T--)
	{
		ioflag=scanf("%d%d", &n, &k);
		assert(ioflag == 2);
		assert(1 <= n&&n <= 1000);
		assert(2 <= k&&k <= 100000000);
		c = 0;
		for (i = 0; i<n; i++)
		{
			ioflag=scanf("%d", &a[c]);
			assert(ioflag == 1);
			assert(1 <= a[c] && a[c] <= k);
			if (k%a[c] == 0)c++;
		}
		n = c;
		//for (i = 0; i < n; i++)printf("a[%d]=%d\n", i, a[i]);
		c = splite(d, k);
		for (i = 0; i < c; i++)dp[i] = 0;
		dp[0] = 1;
		//for (i = 0; i < c; i++)printf("d[%d]=%d\n", i, d[i]);
		for (i = 0; i<n; i++)
		{
			for (j = c - 1; j >= 0; j--)
			{
				if (dp[j] == 0)continue;
				int id = bin((lld)d[j] * (lld)a[i], 0, c - 1);
				if (id != -1)
				{
					dp[id] += dp[j];
					if (dp[id] >= MOD)dp[id] -= MOD;
				}
			}
			//printf("i=%d a[%d]=%d\n", i, i,a[i]);
			//for (j = 0; j < c; j++)printf("dp[%d]=%d\n", j, dp[j]);
		}
		//for (i = 0; i < c; i++)printf("dp[%d]=%d\n", i, dp[i]);

		printf("%d\n", dp[c - 1]);
	}
	ioflag = scanf("%d", &T);
	assert(ioflag != 1);
	return 0;
}
/*

fc E:\1002.out E:\1002brt.out /n
*/
