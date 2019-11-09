#pragma GCC optimize(2)
#include <set>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

int read() {
	int x, c;
	while (!isdigit(c = getchar())); x = c - 48;
	while (isdigit(c = getchar())) x = x * 10 + c - 48;
	return x;
}

long long d[200010];
double r[200010];
struct v {
	int d; double r;
	bool operator<(const v& t) const { return d * d / r < t.d * t.d / t.r; }
	v(int a = 0, double b = 0): d(a), r(b) {}
};
set<v> k;

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	int n = read();
	if (n <= 5000) {
		for (int i = 0; i < n; ++i) {
			d[i] = read(); r[i] = read();
			if (!i) { printf("%.3f\n", r[i]); continue; }
			for (int j = 0; j < i; ++j)
				r[i] = min(r[i], (d[i] - d[j]) * (d[i] - d[j]) / 4.0 / r[j]);
			printf("%.3f\n", r[i]);
		}
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		d[i] = read(); r[i] = read();
		if (!i) { printf("%.3f\n", r[i]); k.insert(v(d[i], r[i])); continue; }
		if (i <= 200) {
			for (int j = 0; j < i; ++j)
				r[i] = min(r[i], (d[i] - d[j]) * (d[i] - d[j]) / 4.0 / r[j]);
			printf("%.3f\n", r[i]);
			k.insert(v(d[i], r[i]));
			continue;
		}
		int step = 100;
		for (set<v>::iterator it = k.begin(); step--; ++it)
			r[i] = min(r[i], (d[i] - it->d) * (d[i] - it->d) / 4.0 / it->r);
		for (int j = i - 100; j < i; ++j)
			r[i] = min(r[i], (d[i] - d[j]) * (d[i] - d[j]) / 4.0 / r[j]);
		k.insert(v(d[i], r[i]));
		printf("%.3f\n", r[i]);
	}
	return 0;
}
