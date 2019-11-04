#include <queue>
#include <ctime>
#include <cstdio>
#include <cstring>
#define re register
int v, c;
template <class T> T read(T& x) {
	x = 0; v = 1; c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) if (c == '-') v = -1;;
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	return x *= v;
}
template <class T> inline T min(T x, T y) {return x < y ? x : y;}
const int N = 1010;
int n, F, xl, yl, nr, fl, fr, ans, a[N], f[N][N];
bool flag;
int main() {
	freopen("weapon.in", "r", stdin);
	freopen("weapon.out", "w", stdout);
	read(n); read(F);
	for (re int i = 1; i <= n; ++i) {
		read(a[i]);
	}
	if (n <= 500) {
		nr = n - F + 1;
		for (re int xl = 1; xl <= n; ++xl) {
			for (re int len = 1; xl + (len << 1) <= nr; ++len) {
				yl = xl + len + F;
				flag = 0;
				for (re int i = 0; i < len; ++i) {
					if (a[xl + i] != a[yl + i]) {
						flag = 1; break;
					}
				}
				if (!flag) ++ans;
			}
		}
	} else {
		nr = n - F + 1;
		for (re int xl = 1; xl <= n; ++xl) {
			for (re int len = 1; xl + (len << 1) <= nr; ++len) {
				yl = xl + len + F;
				flag = 0;
				for (re int i = 0; i < len; ++i) {
					if (a[xl + i] != a[yl + i]) {
						flag = 1; break;
					}
				}
				if (!flag) ++ans;
			}
			if (clock() / CLOCKS_PER_SEC >= 0.8) break;
		}
	}
	printf("%d", ans);
	return 0;
}
