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
unsigned int a[1000001];
unsigned int s[1000001];
unsigned int bs[1000001];
int n, f;
const int P = 1331;
inline int hash(int x) {
	int ans = 0;
	bs[x] = 1;
	for(int i = 1; i <= x; i++) {
		ans = ans * P + a[i];
		bs[x] *= P;
	}
	return ans;
}
signed main() {
	freopen("weapon.in", "r", stdin);
	freopen("weapon.out", "w", stdout);
	n = read(), f = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read() + 1e9;
	}
	for(int i = 1; i <= n; i++) {
		s[i] = hash(i);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			int len = j - i + 1;
			if(j + len + f - 1 > n) {
				continue;
			}
			int l1 = i, r1 = j, l2 = j + f + 1, r2 = j + f + len;
			if(s[r2] - s[l2 - 1] * bs[len]  == s[r1] - s[l1 - 1] * bs[len]) {
				ans ++;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
