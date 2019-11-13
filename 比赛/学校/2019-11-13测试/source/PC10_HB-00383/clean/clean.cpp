#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m, ans;
vector<int> a;

int main()
{
	freopen("clean.in", "r", stdin);
	freopen("clean.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	a.resize(n + 2);
	
	for (int i = 1; i <= m; ++i)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		++a[l];
		--a[r + 1];
	}
	
	for (int i = 1; i <= n; ++i)
	{
		a[i] += a[i - 1];
		ans += a[i] == 0;
	}
	
	cout << ans;
	
	return 0;
}
