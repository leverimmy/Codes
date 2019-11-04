#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
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
int n, m1, m2;
int b[1000001];
struct node {
	int val, id;
	bool operator < (const node &b) const {
		return val > b.val;
	}
} a[1000001];
priority_queue<node>q;
int vis[1000001];
signed main() {
	freopen("robot.in", "r", stdin);
	freopen("robot.out", "w", stdout);
	n = read(), m1 = read(), m2 = read();
	for(int i = 1; i <= n; i++) {
		a[i].val = read();
		a[i].id = i;
	}
	memset(vis, 0, sizeof(vis));
	int ans = 0;
	q.push(a[n]);
	for(int i = n - 1; i >= 1; i--) {
		if(a[i].val > q.top().val) {
			ans += m1;
			if(vis[q.top().id] != 0) {
				ans -= m1;
				ans += m2;
			} else {
				vis[q.top().id] = 1;
			}
			q.pop();
			q.push(a[i]);
		}
		q.push(a[i]);
	}
	int sum = 0;
	while(!q.empty()) {
		q.pop();
	}
	memset(vis, 0, sizeof(vis));
	q.push(a[1]);
	for(int i = 2; i <= n; i++) {
		if(a[i].val > q.top().val) {
			sum += m2;
			if(vis[q.top().id] != 0) {
				sum -= m2;
				sum += m1;
			} else {
				vis[q.top().id] = 1;
			}
			q.pop();
			q.push(a[i]);
		}
		q.push(a[i]);
	}
	printf("%lld\n", min(ans, sum));
	return 0;
}
