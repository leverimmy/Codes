#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 500010;
int T, n;
int f[2][N];
struct Q {
	int op, x, y;
}a[N];
int b[N], cnt;
int c[N], t;
inline void add(int w, int x, int y) {
	for(; x <= 2 * n; x += x & -x)
		f[w][x] += y;
}
inline int query(int w, int x) {
	int sum = 0;
	for(; x; x -= x & -x)
		sum += f[w][x];
	return sum;
}
int main() {
	freopen("segment.in", "r", stdin);
	freopen("segment.out", "w" ,stdout);
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d", &n);
		memset(f, 0, sizeof f);
		cnt = 0;
		t = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &a[i].op, &a[i].x);
			if(a[i].op == 0) {
				c[++t] = i;
				b[++cnt] = a[i].x;
				b[++cnt] = a[i].x + t;
				a[i].y = a[i].x + t;
			}
		}
		sort(b + 1, b + 1 + cnt);
		cnt = unique(b + 1, b + 1 + cnt) - b - 1;
		printf("Case #%d:\n", kase);
		for(int i = 1; i <= n; i++) {
			if(a[i].op == 0) {
				int x = lower_bound(b + 1, b + 1 + cnt, a[i].x) - b;
				int y = lower_bound(b + 1, b + 1 + cnt, a[i].y) - b;
				printf("%d\n", query(1, y) - query(0, x - 1));
				add(0, x, 1);
				add(1, y, 1);
			}
			else {
				int x = lower_bound(b + 1, b + 1 + cnt, a[c[a[i].x]].x) - b;
				int y = lower_bound(b + 1, b + 1 + cnt, a[c[a[i].x]].y) - b;
				add(0, x, -1);
				add(1, y, -1);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
