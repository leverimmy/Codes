#pragma GCC optimize(3)
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <numeric>
#include <algorithm>
using namespace std;

int read() {
	int x, c;
	while (!isdigit(c = getchar())); x = c - 48;
	while (isdigit(c = getchar())) x = x * 10 + c - 48;
	return x;
}

const int N = 100010;
double k[N];

int find_max(int r) {
	double mx = 0, mX = 0;
	for (int i = 1; i < r; ++i)
		if (mx < k[i])
			mx = k[i], mX = i;
	return mX;
}

int main() {
	freopen("noon.in", "r", stdin);
	freopen("noon.out", "w", stdout);
	int n = read(), m = read();
	fill(k + 1, k + n + 1, -1);
	if (n <= 1000 && m <= 1000) {
		for (int a, b, ans = 0; m--; printf("%d\n", ans), ans = 0) {
			a = read(); b = read();
			k[a] = b / double(a);
			double mx = 0;
			for (int i = 1; i <= n; ++i)
				if (mx < k[i])
					mx = k[i], ++ans;
		}
		return 0;
	}
	//assume strictly increasing
	double mx = 0;
	for (int a, b, ans = 0; m--; printf("%d\n", ans)) {
		a = read(); b = read();
		k[a] = b / double(a);
		if (mx < k[a])
			mx = k[a], ++ans;
	}
	return 0;
}
