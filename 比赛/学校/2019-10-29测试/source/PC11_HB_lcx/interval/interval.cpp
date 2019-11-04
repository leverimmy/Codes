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
int n;
struct node {
	int l, r;
	int id;
	bool operator < (const node &b) const {
		if(r != b.r) {
			return r < b.r;
		}
		return id < b.id;
	}
} a[2000001];
int ans[2000001], cnt;
int sum[2000001];
void dfs(int step, int p) {
	if(step > cnt) {
		for(int i = 2; i <= cnt; i++) {
			if(a[ans[i]].l <= a[ans[i - 1]].r) {
				return;
			}
		}
		bool flag = true;
		for(int i = 1; i <= n; i++) {
			if(ans[i] > sum[i] && flag) {
				return;
			} else if(ans[i] == sum[i]) {
				continue;
			} else {
				flag = false;
				sum[i] = ans[i];
			}
		}
		return;
	}
	for(int i = p + 1; i <= n; i++) {
		ans[step] = i;
		dfs(step + 1, i);
	}
}
signed main() {
	freopen("interval.in", "r", stdin);
	freopen("interval.out", "w", stdout);
	memset(sum, 0x3f, sizeof(sum));
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i].l = read(), a[i].r = read();
		if(a[i].l > a[i].r) {
			swap(a[i].l, a[i].r);
		}
		a[i].id = i;
	}
	if(n > 3000) {
		sort(a + 1, a + 1 + n);
		int r = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i].l > r) {
				ans[++cnt] = a[i].id;
				r = a[i].r;
			}
		}
		sort(ans + 1, ans + 1 + cnt);
		printf("%lld\n", cnt);
		for(int i = 1; i <= cnt; i++) {
			printf("%lld ", ans[i]);
		}
		printf("\n");
	} else {
		sort(a + 1, a + 1 + n);
		int r = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i].l > r) {
				++cnt;
				r = a[i].r;
			}
		}
		printf("%lld\n", cnt);
		dfs(1, 0);
		for(int i = 1; i <= cnt; i++) {
			printf("%lld ", sum[i]);
		}
		printf("\n");
	}
	return 0;
}
/*
4
4 9
9 11
13 19
10 17
*/
