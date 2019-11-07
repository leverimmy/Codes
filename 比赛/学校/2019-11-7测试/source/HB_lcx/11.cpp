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
signed main() {
	freopen("11.in", "r", stdin);
	freopen("11.out", "w", stdout);
	double x = 0;
	while(cin >> x) {
		if(x == 0.00) {
			break;
		}
		int cnt = 0;
		double ans = 0;
		while(ans < x) {
			ans += (double)(1 / (double)((++cnt) + 1));
		}
		printf("%lld card(s)\n", cnt);
	}
	return 0;
} 
