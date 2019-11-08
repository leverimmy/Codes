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
int n, m;
struct edge {
	int x, val;
};
vector<edge> a[100001];
inline void addedge(int x, int y, int val) {
	a[x].push_back((edge) {y, val});
}
signed main() {
	freopen("16.in", "r", stdin);
	freopen("16.out", "w", stdout);
	while(cin >> n >> m) {
		for(int i = 1; i <= n; i++) {
			a[i].clear();
		}
		for(int i = 1; i <= m; i++) {
			int x = read(), y = read(), val = read();
			addedge(x, y, val);
		}
		SPFA(1);
		
	}
	return 0;
}
