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
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	int m = read(), n = read(), r = read();
	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		if(i % n == r) {
			cnt++;
			if(cnt % 10 == 1) {
				printf("%lld", i);
			} else if(cnt % 10 == 0) {
				printf(",%lld\n", i);
			} else {
				printf(",%lld", i);
			}
		}
	}
	return 0;
} 
