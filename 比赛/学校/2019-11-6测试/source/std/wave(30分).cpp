#include <cstdio>
#include <algorithm>

const int N = 60;

int a[N], n;

inline int abs(int x) {
	return x < 0 ? -x : x;
}

inline int cal() {
	int ans = 0;
	for(int i = 2; i <= n; i++) {
		ans += abs(a[i] - a[i - 1]);
	}
	return ans;
}

int main() {

	freopen("wave.in", "r", stdin);
	freopen("wave.out", "w", stdout);

	int m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		a[i] = i;
	}
	int ans = 0;
	do {
		ans += cal() == m;
	} while(std::next_permutation(a + 1, a + n + 1));
	
	printf("%d", ans);
	return 0;
}
