#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define LY(p) freopen (p".in", "r", stdin); freopen (p".out", "w", stdout)
#define LL long long
#define dbl double
#define lf long double
#ifdef WIN32
#define L_L "%I64d"
#else
#define L_L "%lld"
#endif
int _n[] = {3, 4, 5, 5, 6, 7, 80, 90, 95, 98, 99, 100, 350, 380, 385, 390, 395, 399, 398, 400};
int _m[] = {3, 2, 4, 5, 4, 7, 85, 85, 96, 100, 100, 100, 360, 390, 400, 385, 400, 400, 400, 400};
int _v[] = {20, 50, 50, 100, 100, 100, 150, 180, 200, 200, 200, 200, 400, 400, 400, 400, 400, 400, 400, 400};
int _c[] = {5, 10, 10, 10, 10, 10, 20, 20, 20, 10, 10, 10, 20, 20, 20, 20, 20, 20, 20, 20};
int n = 3, m = 3, v = 50, C = 10, W = 1000;

#define F(p) freopen ("matrix"p".in", "w", stdout)
int main()
{
	srand ((unsigned) time (NULL));
	int T = 20;
	F("20");
	n = _n[T - 1], m = _m[T - 1], v = _v[T - 1], C = _c[T - 1];
	printf ("%d %d %d\n", n, m, v);
	for (int i = 1; i <= n; i++, printf ("\n"))
		for (int j = 1; j <= m; j++)
			printf ("%d ", rand() % C);

	for (int i = 1; i <= n; i++, printf ("\n"))
		for (int j = 1; j <= m; j++)
			printf ("%d ", rand() % W);
	return 0;
}
