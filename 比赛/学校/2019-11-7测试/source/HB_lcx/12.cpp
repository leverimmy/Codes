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
signed main() {
	freopen("12.in", "r", stdin);
	freopen("12.out", "w", stdout);
	int n = read();
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(n % i == 0) {
			ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
} 
