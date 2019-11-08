#include<bits/stdc++.h>
#define int long long
#define INF 0x7ffffff
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
	int x, y;
	bool operator < (const node &b) const {
		return x < b.x;
	}
};
priority_queue<node> q;
signed main() {
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	int n = read();
	for(int i = 1; i <= n; i++) {
		int judge = read();
		if(judge == 1) {
			int x = read();
			q.push((node){x});
		} else {
			if(!q.empty()) {
				printf("%lld\n", q.top().x);
			} else {
				printf("-1\n");
			}
		}
	}
	return 0;
}
