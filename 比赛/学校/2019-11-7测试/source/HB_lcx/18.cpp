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
int f[3001];
int t[3001];
int gf(int x) {
	if(f[x] == x) {
		return x;
	}
	return f[x] = gf(f[x]);
}
signed main() {
	freopen("18.in", "r", stdin);
	freopen("18.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for(int i = 1; i <= m; i++) {
		int a = read(), b = read();
		int f1 = gf(a), f2 = gf(b);
		f[f1] = f2;
	}
	for(int i = 1; i <= n; i++) {
		t[gf(i)]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(t[i] != 0) {
			ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
} 
/*
6 4
1 2
2 3
3 6
4 5
*/
