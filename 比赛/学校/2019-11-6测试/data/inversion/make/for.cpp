#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define dbl double
int n, m, a[1010], x[1010], y[1010], cnt;
dbl ans;

int calc() {
	int s(0);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			s += a[i] > a[j];
	return s;
}

void dfs (int o) {
	if (o > m)
		return ans += calc(), cnt ++, void(0);
	dfs (o + 1);
	swap (a[ x[o] ], a[ y[o] ]);
	dfs (o + 1);
	swap (a[ x[o] ], a[ y[o] ]);
}

int main()
{
	freopen ("inversion2.in", "r", stdin); freopen ("for.out", "w", stdout);
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf ("%d %d", &x[i], &y[i]);
	
	dfs (1);
	
	printf ("%.8lf", ans / cnt);
	return 0;
}
