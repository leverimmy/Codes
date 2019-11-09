#pragma GCC optimize(2)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

double x[110]; int sum, n, w;

double dfs(int left, double last_sum, int now) {
	if (n - now < left || left < 0 || now > n)
		return 1e10;
	if (!left && now == n)
		return last_sum * now;
	return min(dfs(left, last_sum + x[now], now + 1), dfs(left - 1, x[now], now + 1) + last_sum * now);
}

int main() {
	freopen("pb.in", "r", stdin);
	freopen("pb.out", "w", stdout);
	scanf("%d%d", &n, &w);
	for (int i = 0; i < n; ++i)
		scanf("%lf", x + i), sum += x[i];
	for (int i = 0; i < n; ++i)
		x[i] /= sum;
	sort(x, x + n, greater<double>());
	printf("%.4f\n", dfs(w - 1, 0.0, 0));
	return 0;
}
