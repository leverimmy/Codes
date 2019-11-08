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
int ksm(int x, int y, int z) {
	if(y == 1) {
		return x;
	}
	int t = ksm(x, y / 2, z);
	if(y & 1) {
		t = ((t % z) * (t % z) * x) % z;
	} else {
		t = ((t % z) * (t % z)) % z;
	}
	return t;
}
signed main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int a, b, c;
	while(cin >> a >> b >> c) {
		printf("%lld\n", ksm(a, b, c));
	}
	return 0;
}
