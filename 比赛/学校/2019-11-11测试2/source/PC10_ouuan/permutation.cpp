#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<int> ans, cnt;

int main()
{
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	
	scanf("%d", &n);
	ans.resize(n + 1);
	cnt.resize(n + 1, 0);
	
	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		ans[i] = ++cnt[x];
	}
	
	for (int i = 2; i <= n; ++i)
	{
		if (cnt[i] > cnt[i - 1])
		{
			puts("-1");
			return 0;
		}
	}
	
	printf("%d\n", cnt[1]);
	for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
	
	return 0;
}
