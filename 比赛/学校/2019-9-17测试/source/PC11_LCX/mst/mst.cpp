#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
struct node {
	int x, y, a, b;
} c[1000001];
int f[1000001];
inline bool cmp(node x, node y) {
	if(x.a * y.b != x.b * y.a) {
		return x.a * y.b < x.b * y.a;
	} else if(x.b != y.b) {
		return x.b > y.b;
	}
	return x.a < y.a;
}
inline int fa(int x) {
	if(f[x] != x) {
		f[x] = fa(f[x]);
	}
	return f[x];
}
signed main() {
	freopen("mst.in", "r", stdin);
	freopen("mst.out", "w", stdout);
	int n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read(), aa = read(), bb = read();
		node t1;
		t1.y = y, t1.x = x, t1.a = aa, t1.b = bb;
		c[i] = t1;
	}
	for(int i = 1; i <= n; i++) {
		f[i] = i;
	}
	sort(c + 1, c + 1 + m, cmp);
	double ansa = 0, ansb = 0;
	int j = 0;
	for(int i = 1; i <= m; i++) {
		int q1 = fa(c[i].x);
		int q2 = fa(c[i].y);
		if(q1 != q2) {
			f[q1] = q2, ansa += c[i].a, ansb += c[i].b;
			j++;
		}
		if(j == n - 1) {
			break;
		}
	}
	printf("%.6f\n", ansa / ansb);
	return 0;
}
