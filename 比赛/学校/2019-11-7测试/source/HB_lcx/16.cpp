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
int a[21][21];
signed main() {
	freopen("16.in", "r", stdin);
	freopen("16.out", "w", stdout);
	int n = read(), s = read();
	a[1][1] = n;
	for(int i = 2; i <= s; i++) {
		a[i][1] = ++n;
	}
	for(int i = 2; i <= s; i++) {
		a[s][i] = ++n;
	}
	for(int i = s - 1; i >= 1; i--) {
		a[i][s] = ++n;
	}
	for(int i = s - 1; i >= 2; i--) {
		a[1][i] = ++n;
	}
	for(int i = 1; i <= s; i++) {
		for(int j = 1; j <= s; j++) {
			if(a[i][j] != 0) {
				printf("%lld ", a[i][j]);
			} else {
				printf("   ");
			}
		}
		printf("\n");
	}
	return 0;
} 
