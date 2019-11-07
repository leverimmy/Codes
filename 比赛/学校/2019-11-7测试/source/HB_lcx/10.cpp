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
int a[1001][1001];
signed main() {
	freopen("10.in", "r", stdin);
	freopen("10.out", "w", stdout);
	int n = read(), m = read();
	int x = 1, y = 1;
	for(int i = n; i <= m; i++) {
		a[x][y] = i;
		if(x % 2 == 1) {
			if(y == 5) {
				x++;
			} else {
				y++;
			}
		} else {
			if(y == 1) {
				x++;
			} else {
				y--;
			}
		}
	}
	while(a[x][1] == 0) {
		for(int i = 1; i <= 5; i++) {
			a[x][i] = a[x][i + 1];
		}
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= 5; j++) {
			if(a[i][j] == 0) {
				return 0;
			}
			printf("%lld ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
