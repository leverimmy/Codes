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
inline bool judge(int x) {
	for(int i = 2; i <= sqrt(x); i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}
signed main() {
	freopen("5.in", "r", stdin);
	freopen("5.out", "w", stdout);
	int n = read();
	while(1) {
		n++;
		if(judge(n)) {
			printf("%lld\n", n);
			break;
		}
	}
	return 0;
} 
