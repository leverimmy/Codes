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
int a[1000001];
char s[1000001];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n = read();
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	int l = 1, r = 1, num = 0;
	for(int i = 1; i <= n;) {
		if(s[i] == ')') {
			i++;
			continue;
		}
		l = i, r = i;
		while(r <= n + 1) {
			if(num == 0 && r != l) {
				r--;
				break;
			}
			if(s[r] == '(') {
				num++;
			} else {
				num--;
			}
			r++;
		}
		if(r > n) {
			i++;
			continue;
		}
		a[l] = r;
		a[r] = r;
		i = r + 1;
		l = r + 1;
		r = r + 1;
	}
	int maxa = 0, pp = 0;
	num = 0;
	int p = 1;
	while(p <= n) {
		if(a[p] != 0) {
			pp += a[p] - p + 1;
			p = a[p];
		} else {
			if(maxa < pp) {
				maxa = pp;
				num = 1;
			} else if(maxa == pp) {
				num++;
			}
			pp = 0;
		}
		p++;
	}
	if(maxa < pp) {
		maxa = pp;
		num = 1;
	} else if(maxa == pp) {
		num++;
	}
	if(maxa == 0) {
		num = 0;
	}
	printf("%lld %lld\n", maxa, num);
	return 0;
}
