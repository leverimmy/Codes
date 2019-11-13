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
int v[N];
inline bool judge(int x) {
	int t = x;
	while(t != 0) {
		if(t % 10 == 4 || t % 10 == 7) {
			t /= 10;
		} else {
			break;
		}
	}
	if(t == 0) {
		return true;
	} else {
		return false;
	}
}
vector<int>a;
inline bool judge2(int x) {
	int t = x;
	for(int i = 0; i < a.size(); i++) {
		if(t == 1) {
			break;
		}
		if(t % a[i] == 0) {
			t /= a[i];
			i--;
		}
	}
	if(t == 1) {
		return true;
	} else {
		return false;
	}
}
signed main() {
	freopen("prd.in", "r", stdin);
	freopen("prd.out", "w", stdout);
	int T = read();
	for(int i = 1; i <= 1000; i++) {
		if(judge(i)) {
			v[i] = 1;
			a.push_back(i);
		}
	}
	for(int i = 4; i <= 1000; i++) {
		if(judge2(i)) {
			v[i] = 1;
		}
	}
	while(T--) {
		int l = read(), r = read();
		int ans = 0;
		for(int i = l; i <= r; i++) {
			if(v[i]) {
				ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
