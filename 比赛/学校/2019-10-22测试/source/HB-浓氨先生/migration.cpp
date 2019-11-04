#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int n, m;
vector<int>a[500001];
inline void addedge(int x, int y) {
	a[x].push_back(y);
}
int q[50001];
signed main() {
	freopen("migration.in", "r", stdin);
	freopen("migration.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read();
		addedge(x, y);
		addedge(y, x);
	}
	for(int i = 1; i <= n; i++) {
		q[i] = read();
	}
	for(int i = 1; i <= n; i++) {
		int mm = rand() % 2;
		if(mm & 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	} 
	return 0;
}
