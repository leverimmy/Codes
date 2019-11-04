#include <cstdio>
#include <cctype>
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
bool x[N], y[N];

int main() {
	freopen("rush.in", "r", stdin);
	freopen("rush.out", "w", stdout);
	int n = read(), m = read();
	for (int a, b; m--; x[a] = y[b] = 1)
		a = read(), b = read();
	int ans = count(x + 1, x + n + 1, 0) + count(y + 1, y + n + 1, 0);
	printf("%d\n", ans);
	return 0;
}
