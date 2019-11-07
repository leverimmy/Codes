#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define LY(p) freopen (p".in", "r", stdin); freopen ("for.out", "w", stdout)
#define LL long long
#define dbl double
#define lf long double
#ifdef WIN32
#define L_L "%I64d"
#else
#define L_L "%lld"
#endif
int ans, ANS;
int n, m, vis[55];

void dfs (int o, int las) {
	if (o > n) return (void) (ANS += (ans == m));
	
	for (int i = 1; i <= n; i++)
		if (! vis[i])
			vis[i] = 1, ans += (o > 1? abs (i - las) : 0), dfs (o + 1, i), ans -= (o > 1? abs (i - las) : 0), vis[i] = 0;
}

int main()
{
	LY("wave");
	scanf ("%d %d", &n, &m);
	dfs (1, 0);
	printf ("%d", ANS);
	return 0;
}
