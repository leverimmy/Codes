#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N = 100010, M = 1000010;
#define LL long long
int n, m, w[N];
struct E {
	int x, y, l;
}a[M];
int f[N], sz[N];
LL ans;
inline bool cmp(const E &x, const E &y) {
	return x.l > y.l;
}
int find(int x) {
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}
int main() {
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].l = min(w[a[i].x], w[a[i].y]);
	}
	sort(a + 1, a + 1 + m, cmp);
	for(int i = 1; i <= n; i++) {
		f[i] = i;
		sz[i] = 1;
	}
	for(int i = 1; i <= m; i++)
		if(find(a[i].x) != find(a[i].y)) {
			ans += (LL)(sz[find(a[i].x)]) * sz[find(a[i].y)] * a[i].l;
			sz[find(a[i].y)] += sz[find(a[i].x)];
			f[find(a[i].x)] = find(a[i].y);
		}
	cout << 2 * ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
