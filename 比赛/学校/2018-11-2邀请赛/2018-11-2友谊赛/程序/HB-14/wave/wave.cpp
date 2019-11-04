#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
bool wave[6000][6000] = { false };
int x = 0, y = 0, maxx = 0, maxy = 0;
long long ans = 0;
int main()
{
	freopen("wave.in", "r", stdin);
	freopen("wave.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int dat = 1; dat <= n; dat++)
	{
		scanf("%d%d", &x, &y);
		maxx = max(maxx, x);
		maxy = max(maxy, y);
		for (int i = 1; i <= x; i++)
		{
			for (int j = 1; j <= y; j++)
			{
				wave[i][j] = true;
			}
		}
	}
	for (int i = 1; i <= maxx; i++)
	{
		for (int j = 1; j <= maxy; j++)
		{
			if (wave[i][j])
			{
				ans++;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}