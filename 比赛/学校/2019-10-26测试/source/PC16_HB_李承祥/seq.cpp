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
int ans = 1;
void gcd(int x, int y) {
	if(y == 0) {
		return;
	}
	ans += x / y;
	gcd(y, x % y);
}
signed main() {
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	int n = read(), m = read();
	gcd(n, m);
	printf("%lld", ans);
	return 0;
}
