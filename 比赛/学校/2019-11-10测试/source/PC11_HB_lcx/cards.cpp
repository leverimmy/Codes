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
const int N = 50;
int a[N];
int ans[N];
int sum = -0x7fffff2;
inline int check(int n) {
	int l = 1, ans = 0;
	a[n + 1] = a[n] ^ 1;
	for(int i = 2; i <= n + 1; i++) {
		if(a[i] == -1) {
			return -0x7fffff;
		}
		if(a[i] != a[i - 1]) {
			if(a[i - 1]) {
				ans += (i - l) * (i - l);
			} else {
				ans -= (i - l) * (i - l);
			}
			l = i;
		}
	}
	return ans;
}
void dfs(int x, int y, int bz, int hz, int step) {
	if(step > x + y) {
		int judge = check(x + y);
		if(judge > sum) {
			sum = judge;
			for(int i = 1; i <= x + y; i++) {
				ans[i] = a[i];
			}
		}
		return;
	}
	if(bz < x) {
		a[step] = 1;
		dfs(x, y, bz + 1, hz, step + 1);
		a[step] = -1;
	}
	if(hz < y) {
		a[step] = 0;
		dfs(x, y, bz, hz + 1, step + 1);
		a[step] = -1;
	}
}
signed main() {
	freopen("cards.in", "r", stdin);
	freopen("cards.out", "w", stdout);
	memset(a, -1, sizeof(a));
	int aa = read(), ba = read();
	dfs(aa, ba, 0, 0, 1);
	printf("%lld\n", sum);
	for(int i = 1; i <= aa + ba; i++) {
		if(ans[i] == 1) {
			printf("o");
		} else if(ans[i] == 0) {
			printf("x");
		}
	}
	cout << endl;
}
