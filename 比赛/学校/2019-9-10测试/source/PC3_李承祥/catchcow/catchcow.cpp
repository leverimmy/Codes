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
	int x, stepa;
};
queue<node> q;
bool judge[20000001];
signed main() {
	freopen("catchcow.in", "r", stdin);
	freopen("catchcow.out", "w", stdout);
	memset(judge, true, sizeof(judge));
	int n = read(), m = read();
	q.push((node) {
		n, 0
	});
	judge[n] = false;
	while(!q.empty()) {
		node t = q.front();
		q.pop();
		if(t.x == m) {
			printf("%lld\n", t.stepa);
			break;
		}
		if(t.x + 1 <= 2 * m && judge[t.x + 1]) {
			judge[t.x + 1] = false;
			q.push((node) {
				t.x + 1, t.stepa + 1
			});
		}
		if(t.x - 1 >= 0 && judge[t.x - 1]) {
			judge[t.x - 1] = false;
			q.push((node) {
				t.x - 1, t.stepa + 1
			});
		}
		if(t.x * 2 <= 2 * m && judge[t.x * 2]) {
			judge[t.x * 2] = false;
			q.push((node) {
				t.x * 2, t.stepa + 1
			});
		}
	}
	return 0;
}
