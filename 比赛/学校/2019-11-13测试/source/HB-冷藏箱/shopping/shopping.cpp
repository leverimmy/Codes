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
const int N = 5005, M = 1000005;
int n, m;
int a[N], s[M];
int sa[N];
struct node {
	int l, r;
}q[M];
int vis[M];
int v[N];
int ans = 0;
inline int judge() {
	memset(v, 0, sizeof(v));
	int sum = 0;
	for(int i = 1; i <= m; i++) {
		int ls = 0;
		for(int j = q[s[i]].l; j <= q[s[i]].r; j++) {
			if(!v[j]) {
				v[j] = 1;
				ls += a[j];
			} else {
				sum += ls * ls;
				ls = 0;
			}
		}
		sum += ls * ls;
	}
	return sum;
}
void dfs(int step) {
	if(step > m) {
		ans = max(ans, judge());	
		return ;
	}
	for(int i = 1; i <= m; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			s[step] = i;
			dfs(step + 1);
			s[step] = 0;
			vis[i] = 0;
		}
	}
}
signed main() {
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	for(int j = 1; j <= m; j++) {
		q[j].l = read(), q[j].r = read();
	}
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}
