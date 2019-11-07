#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n = 1000, m = 1000, a[5000], tim, x, y;

int main()
{
	srand ((unsigned) time (NULL));
	freopen ("inversion10.in", "w", stdout);
	printf ("%d %d\n", n, m);

	tim = n * n;
	for (int i = 1; i <= n; i++)
		a[i] = i;
	for (int i = 1; i <= tim; i++) {
		x = rand() % n + 1, y = rand() % n + 1;
		swap (a[x], a[y]);
	}
	for (int i = 1; i <= n; i++)
		printf ("%d ", a[i]);
	printf ("\n");
	for (int i = 1; i <= n; i++) {
		x = rand() % (n - 1) + 2, y = rand() % x + 1;
		printf ("%d %d\n", y, x);
	}
	return 0;
}
