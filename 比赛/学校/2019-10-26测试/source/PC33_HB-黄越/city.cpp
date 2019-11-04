#include <cstdio>
#include <algorithm>
using namespace std;

int a[10000], v[5][100];

int main() {
	freopen("city.in", "r", stdin);
	freopen("city.out", "w", stdout);
	int n; scanf("%d", &n);
	for (int i = 0, ed = n * (n - 1) / 2; i < ed; ++i)
		scanf("%d", a + i);
	sort(a, a + n * (n - 1) / 2);
	int ans = 0;
	if (n == 2) {
		printf("%d\n", a[0] / 2);
		for (int i = a[0] / 2; i > 0; --i)
			printf("%d %d\n", i, a[0] - i);
	}
	if (n == 3) {
		for (int i = 1; i <= 10; ++i)
			for (int j = i; j <= 10; ++j)
				for (int k = j; k <= 10; ++k) {
					int x[3] = { i + j, i + k, j + k };
					sort(x, x + 3);
					for (int i = 0; i < 3; ++i)
						if (x[i] != a[i])
							goto next3;
					v[0][ans] = i, v[1][ans] = j, v[2][ans] = k;
					++ans;
					next3:;
				}
		printf("%d\n", ans);
		for (int i = ans - 1; i >= 0; --i, puts(""))
			for (int j = 0; j < 3; ++j)
				printf("%d ", v[j][i]);
	}
	if (n == 4) {
		for (int i = 1; i <= 10; ++i)
			for (int j = i; j <= 10; ++j)
				for (int k = j; k <= 10; ++k)
					for (int l = k; l <= 10; ++l) {
						int x[6] = { i + j, i + k, i + l, j + k, j + l, k + l };
						sort(x, x + 6);
						for (int i = 0; i < 6; ++i)
							if (x[i] != a[i])
								goto next4;
						v[0][ans] = i, v[1][ans] = j, v[2][ans] = k, v[3][ans] = l;
						++ans;
						next4:;
					}
		printf("%d\n", ans);
		for (int i = ans - 1; i >= 0; --i, puts(""))
			for (int j = 0; j < 4; ++j)
				printf("%d ", v[j][i]);
	}
	if (n == 5) {
		for (int i = 1; i <= 10; ++i)
			for (int j = i; j <= 10; ++j)
				for (int k = j; k <= 10; ++k)
					for (int l = k; l <= 10; ++l)
						for (int m = l; m <= 10; ++m) {
							int x[10] = { i + j, i + k, i + l, i + m, j + k, j + l, j + m, k + l, k + m, l + m };
							sort(x, x + 10);
							for (int i = 0; i < 10; ++i)
								if (x[i] != a[i])
									goto next;
							v[0][ans] = i, v[1][ans] = j, v[2][ans] = k, v[3][ans] = l, v[4][ans] = m;
							++ans;
							next:;
						}
		printf("%d\n", ans);
		for (int i = ans - 1; i >= 0; --i, puts(""))
			for (int j = 0; j < 5; ++j)
				printf("%d ", v[j][i]);
	}
	return 0;
}
