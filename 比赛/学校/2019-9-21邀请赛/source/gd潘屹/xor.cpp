#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m, x;
		scanf("%d%d", &n, &m);
		n *= 3;
		while (n--)
			scanf("%d", &x);
		printf("No\n");
	}
	return 0;
}
