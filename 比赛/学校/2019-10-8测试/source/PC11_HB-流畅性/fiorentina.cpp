#include<bits/stdc++.h>
#define int long long
#define mod 998244353
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
int n, p;
int ans;
void dfs(int step, int sum) {
	if(step > n) {
		if(sum == p) {
			ans ++;
		}
		return;
	}
	dfs(step + 1, sum + step);
	dfs(step + 1, sum);
}
int f[10000001];
signed main() {
	freopen("fiorentina.in", "r", stdin);
	freopen("fiorentina.out", "w", stdout);
//	for(int i = 1; i <= 20; i++) {
//		for(int j = 1; j <= 100; j ++) {
//			ans = 0;
//			n = i, p = j;
//			dfs(1, 0);
//			cout << setw(6) << ans;
//		}
//		printf("\n");
//	}
	n = read(), p = read();
	f[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = p; j >= i; j--) {
			f[j] += f[j - i];
			f[j] %= mod;
		}
	}
	printf("%lld\n", f[p]);
	return 0;
}
