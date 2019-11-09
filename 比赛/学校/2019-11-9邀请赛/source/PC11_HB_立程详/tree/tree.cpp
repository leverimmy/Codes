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
int n, cntt;
int root[100001];
int a[100001];
int t[100001];
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}
bool vis[10000001];
void sss(int n) {
	memset(vis, false, sizeof(vis));
	for(int i = 2; i <= n; i++) {
		if(vis[i]) {
			continue;
		}
		for(int j = 2; j * i <= n; j++) {
			vis[i * j] = true;
		}
	}
}
void devi(int l1, int r1, int root, int l2, int r2) {
	
}
signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int T = read();
	sss(10000000);
	while(T--) {
		n = read();
		cntt = 0;
		for(int i = 1; i <= n; i++) {
			a[i] = read();
			root[++cntt] = i;
		}
		for(int i = 1; i <= cntt; i++) {
			devi(1, root[i] - 1, root[i], root[i] + 1, n);
		}
	}
	return 0;
}
