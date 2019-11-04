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
map<string, int>ma;
signed main() {
	freopen("liverpool.in", "r", stdin);
	freopen("liverpool.out", "w", stdout);
//	ios::sync_with_stdio(0);
	int n = read();
	for(int i = 1; i <= n; i++) {
		string x;
		int val;
		cin >> x;
		val = read();
		if(val != 0) {
			ma[x] = val;
		} else {
			ma[x] = -1;
		}
	}
	int m = read();
	while(m--) {
		int x = read();
		int sum = 0;
		bool judge = false;
		for(int i = 1; i <= x; i++) {
			string u;
			cin >> u;
			int mmm = ma[u];
			if(!mmm) {
				judge = true;
			} else {
				if(mmm == -1) {
					continue;
				}
				sum += mmm;
			}
		}
		if(judge) {
			printf("-1\n");
			continue;
		}
		printf("%lld\n", sum);
	}
	return 0;
}
