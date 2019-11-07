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
	freopen("15.in", "r", stdin);
	freopen("15.out", "w", stdout);
	int n = read();
	int maxx = 0, nnn = 0;
	for(int i = 1; i <= n; i++) {
		int x = read();
		if(x > maxx) {
			maxx = x;
			nnn = i - 1;
		}
	}
	printf("%lld %lld", maxx, nnn);
	return 0;
} 
