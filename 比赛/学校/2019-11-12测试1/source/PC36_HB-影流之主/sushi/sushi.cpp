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
const int N = 1000005;
int a[N];
signed main() {
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);
	int T = read();
	while(T--) {
		string x;
		cin >> x;
		int n = x.length();
		for(int i = 0; i < n; i++) {
			if(x[i] == 'R') {
				a[i + 1] = 1;
			} 
		}
		int ll = 1, rr = n;
		while(a[ll]) {
			ll++;
		}
		while(a[rr]) {
			rr--;
		}
		int ans1 = 0;
		int l = 0, r = 0;
		for(int i = ll; i <= rr; i++) {
			if(a[i] == 1) {
				if(i - ll - l < rr - i - r) {
					ans1 += i - ll - l;
//					ll++;
					l++;
				} else{
					ans1 += rr - i - r;
//					rr--;
					r++;
				}
			}
		}
		int ans2 = 0;
		ll = 1, rr = n;
		while(!a[ll]) {
			ll++;
		}
		while(!a[rr]) {
			rr--;
		}
		l = 0, r = 0;
		for(int i = ll; i <= rr; i++) {
			if(!a[i]) {
				if(i - ll - l < rr - i - r) {
					ans2 += i - ll - l;
//					ll++;
					l++;
				} else{
					ans2 += rr - i - r;
//					rr--;
					r++;
				}
			}
		}
		printf("%lld\n", min(ans1, ans2));
	}
	return 0;
}
