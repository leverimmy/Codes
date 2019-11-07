#include <cstdio>
#include <algorithm>
#include <cstring>

const int N = 40;

int a[N], ans, cnt, n, m, l[N], r[N];
int ta[N];

inline void add(int i) {
	for(; i <= n; i += i & (-i)) {
		ta[i]++;
	}
	return;
}

inline int getsum(int i) {
	int t = 0;
	for(; i > 0; i -= i & (-i)) {
		t += ta[i];
	}
	return t;
}

inline int cal() {
	memset(ta + 1, 0, n * sizeof(int));
	int t = 0;
	for(int i = n; i >= 1; i--) {
		t += getsum(a[i]);
		add(a[i]);
	}
	return t;
}

void DFS(int k) {
	if(k > m) {
		ans += cal();
		cnt++;
		return;
	}
	DFS(k + 1);
	std::swap(a[l[k]], a[r[k]]);
	DFS(k + 1);
	std::swap(a[l[k]], a[r[k]]);
	return;
}

int main() {

	freopen("inversion.in", "r", stdin);
	freopen("inversion.out", "w", stdout);

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &l[i], &r[i]);
	}
	
	DFS(1);
	
	printf("%.8f", (double)(ans) / cnt);
	return 0;
}
