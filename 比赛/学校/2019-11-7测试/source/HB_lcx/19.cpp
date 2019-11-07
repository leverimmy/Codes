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
int f[1000001];
signed main() {
	freopen("19.in", "r", stdin);
	freopen("19.out", "w", stdout);
	int s = read(), t = read();
	f[1] = 1;
	f[2] = 1;
	for(int i = 3; i <= t; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	int a = read(), b = read(), c = read(), d = read();
	for(int i = s; i <= t; i++) {
		if(f[i] % a != 0 && f[i] % b != 0 && f[i] % c != 0 && f[i] % d != 0) {
			printf("%lld ", i);
		}
	}
	return 0;
} 
