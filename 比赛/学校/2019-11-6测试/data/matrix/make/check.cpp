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

int main()
{
	int T(0);
	while (printf ("%d: ", ++ T)) {
		system ("./make");
		system ("./for");
		system ("./matrix");

		if (system ("diff for.out matrix.out"))
			{printf ("WA\n"); break;}
		printf ("AC\n");
	}
	return 0;
}
