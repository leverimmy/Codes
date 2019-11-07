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
int a[1000001];
signed main() {
	freopen("13.in", "r", stdin);
	freopen("13.out", "w", stdout);
	int n = read();
	int lll = n;
	for(int i = 2; i <= lll; i++) {
		if(n % i == 0) {
			a[i]++;
			n /= i;
			i--;
		}
	}
	printf("%lld=", lll);
	int cnt = 0;
	for(int i = 1; i <= lll; i++) {
		if(a[i] != 0) {
			cnt++;
			if(cnt == 1) {
				if(a[i] != 1) {
					printf("%lld^%lld", i, a[i]);
				} else {
					printf("%lld", i);
				}
			} else {
				if(a[i] != 1) {
					printf("*%lld^%lld", i, a[i]);
				} else {
					printf("*%lld", i);
				}
			}
		}
	}
	return 0;
} 
