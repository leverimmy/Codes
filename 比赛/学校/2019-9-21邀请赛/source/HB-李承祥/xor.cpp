#include<bits/stdc++.h>
#define int long long
#define INF 0x7ffffff
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
int a[100001];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int T = read();
	while(T--) {
		int n = read(), m = read();
		for(int i = 1; i <= n; i++) {
			a[i] = 0;
		}
		for(int i = 1; i <= m; i++) {
			int x = read(), y = read(), k = read();
		}
	}
	return 0;
}
