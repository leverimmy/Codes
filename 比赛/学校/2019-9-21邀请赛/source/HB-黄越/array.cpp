#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cmath>
using namespace std;

const int N = 100010, SQRTN = 317;
int a[N];
int f[N][SQRTN];

int read() {
	int x, c;
	while (!isdigit(c = getchar())); x = c - 48;
	while (isdigit(c = getchar())) x = x * 10 + c - 48;
	return x;
}

int main() {
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	if (n <= 100) {
		for (int m = read(); m--;) {
			int p = read(), k = read(), w = 1;
			while ((p += a[p] + k) <= n) ++w;
			printf("%d\n", w); fflush(stdin);
		}
		return 0;
	}
	int sqrtn = sqrt(n) + 1;
	for (int m = read(); m--;) {
		int p = read(), k = read();
		if (k < sqrtn) {
			if (!f[n][k])
				for (int i = n; i > 0; --i)
					f[i][k] = i + a[i] + k > n ? 1 : f[i + a[i] + k][k] + 1;
			printf("%d\n", f[p][k]);
		} else {
			int w = 1;
			while ((p += a[p] + k) <= n) ++w;
			printf("%d\n", w);
		}
	}
	return 0;
}
