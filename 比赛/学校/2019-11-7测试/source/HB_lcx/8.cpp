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
	freopen("8.in", "r", stdin);
	freopen("8.out", "w", stdout);
	int a1 = read(), a2 = read(), m = read();
	for(int i = 1; i <= m; i++) {
		for(int j = i; j <= m; j++) {
			if(a1 * i + a2 * j <= m) {
				printf("%lld,%lld\n", i, j);
			}
		}
	}
	return 0;
} 
