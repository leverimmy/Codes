#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int x, y,standred,stupid=0;
int main()
{
	freopen("lie.in", "r", stdin);
	freopen("lie.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x, &y);
		if (i == 1)
		{
			standred = x + y;
		}
		if ((x + y) < (standred/2) || (x + y) > ((standred/2)*3))
		{
			stupid++;
		}
	}
	printf("%d", stupid);
	return 0;
}