#include <cstdio>
#include <cctype>
#include <vector>
#include <cstring>
#include <algorithm>
#define do(i, x) for (int i = 1; i <= x; ++i)
using namespace std;
typedef long long ll;

int read() {
	int x, c, f = 1;
	while (!isdigit(c = getchar())) if (c == '-') f = -1; x = c - 48;
	while (isdigit(c = getchar())) x = x * 10 + c - 48;
	return x * f;
}

const int N = 100010;
int x[N];

int main() {
	freopen("weapon.in", "r", stdin);
	freopen("weapon.out", "w", stdout);
	int n = read(), f = read(), tot = 0;
	do (i, n)
		x[i] = read();
	do (len, n)
		do (a, n - f + 1 - (len << 1)) {
			for (int i = a; i < a + len; ++i)
				if (x[i] != x[i + len + f])
					goto out;
			++tot;
			out:;
		}
	printf("%d\n", tot);
	return 0;
}

