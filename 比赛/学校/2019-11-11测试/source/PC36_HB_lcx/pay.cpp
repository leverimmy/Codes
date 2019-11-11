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
const int N = 203, M = 50003;
int n, m;
int a, b;
int f[N];
struct node {
	int x, y, val1, val2;
}q[M];
int gf(int x) {
	return x == f[x] ? x : f[x] = gf(f[x]);
}
inline bool judge(int x, int y) {
	for(int i = 1; i <= n; i++) {
		f[i] = i;
	}
	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		if(q[i].val1 > x || q[i].val2 > y) {
			continue;
		}
		if(cnt == n - 1) {
			break;
		}
		int q1 = gf(q[i].x);
		int q2 = gf(q[i].y);
		if(q1 != q2) {
			cnt++;
			f[q1] = q2;
		}
	}
	if(cnt == n - 1) {
		return true;
	}
	return false;
}
signed main() {
	freopen("pay.in", "r", stdin);
	freopen("pay.out", "w", stdout);
	n = read(), m = read();
	a = read(), b = read();
	int max1 = 0, max2 = 0;
	for(int i = 1; i <= m; i++) {
		q[i].x = read(), q[i].y = read(), q[i].val1 = read(), q[i].val2 = read();
		max1 = max(max1, q[i].val1);
		max2 = max(max2, q[i].val2);
	}
	if(!judge(max1, max2)) {
		printf("-1");
		return 0;
	}
	int ans = 0x7ffffff;
	for(int i = 1; i <= max1; i++) {
		int l = 1, r = max2;
		int mid = (l + r) >> 1;
		while(l < mid) {
			if(judge(i, mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
			mid = (l + r) >> 1; 
		}
		if(judge(i, r)) {
			ans = min(ans, r * b + i * a);
		} else if(judge(i, l)) {
			ans = min(ans, l * b + i * a);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
