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
const int N = 201;
int n;
char a[N];
inline bool judge() {
	for(int i = 1; i <= n / 2; i++) {
		if(a[i] != a[n - i + 1]) {
			return false;
		}
	}
	return true;
}
bool vis[N];
void dfs(int z, int step) {
	if(step == z) {
		if(judge()) {
			printf("%lld\n", z);
			exit(0);
		}
		return;
	}
	for(int i = 1; i < n; i++) {
		if(!vis[i] && a[i] != a[i + 1]) {
			swap(a[i], a[i + 1]);
			vis[i] = true;
			dfs(z, step + 1);
			vis[i] = false;
			swap(a[i], a[i + 1]);
		}
	}
}
signed main() {
	freopen("reference.in", "r", stdin);
	freopen("reference.out", "w", stdout);
	n = read();
	cin >> a + 1;
	int x = 0;
	memset(vis, false, sizeof(false));
	while(1) {
		dfs(x, 0);
		x++;
		if(x > n) {
			printf("Impossible\n");
			break;
		}
	}
	return 0;
}
