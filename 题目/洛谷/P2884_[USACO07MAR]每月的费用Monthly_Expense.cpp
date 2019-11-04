#include <cstdio>

using namespace std;

int n, m, sum, maxn = -9999;
int a[100010];
int left, right, mid;

bool judge(int x)
{
	int tot = 0, cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(tot + a[i] <= x)
			tot += a[i];
		else
		{
			tot = a[i];
			cnt++;
		}
	}
	return cnt >= m;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
		maxn = maxn < a[i] ? a[i] : maxn;
	}
	left = maxn;
	right = sum;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(judge(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	printf("%d", left);
	return 0;
}
