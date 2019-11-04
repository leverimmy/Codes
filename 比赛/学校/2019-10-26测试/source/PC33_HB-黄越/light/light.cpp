#include <cstdio>
#include <cctype>
#include <map>
using namespace std;

int read() {
	int x, c;
	while (!isdigit(c = getchar())); x = c - 48;
	while (isdigit(c = getchar())) x = x * 10 + c - 48;
	return x;
}

namespace f {
	int a[100010];
	
	int solve(int n, int m) {
		for (int i = 1; i <= n; ++i)
			a[i] = read();
		for (int ans = 0; m--; printf("%d\n", ans), ans = 0)
			for (int l = read(), r = read(), p = read(), v = read(), i = l; i <= r; ++i)
				if (a[i] % p == v)
					++ans;
		return 0;
	}
}

namespace s {
	const int N = 330;
	//map<int, int> b[N];
	int b[N][10001];
	int a[100010];
	
	int solve(int n, int m) {
		for (int i = 0; i < n; ++i)
			a[i] = read();
		bool init = false;
		for (int ans = 0; m--; printf("%d\n", ans), ans = 0) {
			int l = read(), r = read(), p = read(), v = read();
			if (!init)
				for (int i = 1; i <= n; ++i)
					++b[i / N][a[i] % p];
			init = true;
			for (int i = l / N + 1; i < r / N; ++i)
				ans += b[i][v];
			for (int i = l; i < l / N * N + N; ++i)
				ans += (a[i] % p == v);
			for (int i = r / N * N; i <= r; ++i)
				ans += (a[i] % p == v);
		}
	}
}

int main() {
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
	int n = read(), m = read();
	if (n <= 1000)
		return f::solve(n, m);
	else return s::solve(n, m);
	return 0;
}
