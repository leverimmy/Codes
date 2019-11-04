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
int n, m;
struct node {
	int x, val;
};
vector<node>mapa[1000001];
signed main() {
	freopen("bomb.in", "r", stdin);
	freopen("bomb.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read(), val = read();
		mapa[x].push_back((ndoe) {
			y, val
		};)
		mapa[y].push_back((ndoe) {
			x, val
		};)
	}
	return 0;
}
