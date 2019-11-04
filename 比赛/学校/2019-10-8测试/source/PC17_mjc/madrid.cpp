#include<bits/stdc++.h>
#define int long long
#define pi 3.141592653589793238462
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
struct node {
	double x, y;
} a[1000001];
int n, m;
signed main() {
	freopen("madrid.in", "r", stdin);
	freopen("madrid.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	m = read();
	while(m--) {
		char judge;
		cin >> judge;
		int l = read(), r = read();
		if(judge == 'M') {
			double p, q;
			cin >> p >> q;
			for(int i = l; i <= r; i++) {
				a[i].x += p;
				a[i].y += q;
			}
		}
		if(judge == 'X') {
			for(int i = l; i <= r; i++) {
				a[i].y = -a[i].y;
			}
		}
		if(judge == 'Y') {
			for(int i = l; i <= r; i++) {
				a[i].x = -a[i].x;
			}
		}
		if(judge == 'O') {
			for(int i = l; i <= r; i++) {
				double t = a[i].x;
				a[i].x = a[i].y;
				a[i].y = t;
			}
		}
		if(judge == 'R') {
			double aa;
			cin >> aa;
			aa = aa / (double)180 * pi;
			for(int i = l; i <= r; i++) {
				double xx = a[i].x, yy = a[i].y;
				a[i].x = cos(aa) * xx - sin(aa) * yy;
				a[i].y = sin(aa) * xx + cos(aa) * yy;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		printf("%.2f %.2f\n", a[i].x, a[i].y);
	}
	return 0;
}
