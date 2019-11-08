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
int n;
int a[1000001];
signed main() {
	freopen("4.in", "r", stdin);
	freopen("4.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) {
		printf("%lld ", a[i]);
	}
	puts("");
	return 0;
}
