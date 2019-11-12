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
	freopen("stone.in", "w", stdout);
	int n = 4000000;
	printf("%lld\n", n);
	for(int i = 1; i <= n; i++) {
		printf("%lld ", 1000000);
	}
	return 0;
}
