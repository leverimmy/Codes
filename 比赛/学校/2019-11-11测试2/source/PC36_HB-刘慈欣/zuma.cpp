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
const int N = 105;
int n, k;
int a[N];
signed main() {
	freopen("zuma.in", "r", stdin);
	freopen("zuma.out", "w", stdout);
	n = read(), k = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
	} 
	dfs() 
	return 0;
} 
