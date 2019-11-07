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
int a[10001];
signed main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int n = read(), m = read();
	int pp = n / m;
	if(n % m != 0) {
		pp++;
	}
	printf("%lld\n", (1 << pp) - 1);
	return 0;
} 
