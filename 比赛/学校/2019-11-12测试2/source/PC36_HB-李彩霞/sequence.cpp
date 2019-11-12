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
const int N = 1005;
int a[N];
int s[N];
int n, k;
int sz[N * N];
signed main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	n = read(), k = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		s[i] = s[i - 1] + a[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			sz[++cnt] = s[j] - s[i - 1];
		}
	}
	sort(sz + 1, sz + 1 + cnt);
	printf("%lld\n", sz[cnt - k + 1]);
	return 0;
}
