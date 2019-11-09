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
int n;
struct node {
	double x, r;
	double y;
	int id;
	bool operator < (const node &b) const {
		if(x != b.x) {
			return x < b.x;
		}
		return id < b.id;
	}
}a[2000001];
inline double jl(int x, int y, int x1, int y1) {
	return sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
}
signed main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		a[i].x = read(), a[i].r = read();
		a[i].y = 99999999.0;
		a[i].id = i;
	} 
	sort(a + 1, a + 1 + n);
	if(n <= 2000) {
		for(int i = 1; i <= n; i++) {
			a[i].y = a[i].r;
			for(int j = 1; j < i; j++) {
				if(jl(a[i].x, a[i].r, a[j].x, a[j].y) >= a[j].y + a[i].x) {
					a[i].y = min(a[i].r, a[i].y);
				} else {
					a[i].y = a[i].r = min((a[i].x - a[j].x) * (a[i].x - a[j].x) / (4.0 * a[j].y), a[i].y);
				}
			}
			printf("%.3f\n", a[i].y);
		}
	} else {
		for(int i = 1; i <= n; i++) {
			a[i].y = a[i].r;
			for(int j = max(1ll, i - 500ll); j < i; j++) {
				if(jl(a[i].x, a[i].r, a[j].x, a[j].y) >= a[j].y + a[i].x) {
					a[i].y = min(a[i].r, a[i].y);
				} else {
					a[i].y = a[i].r = min((a[i].x - a[j].x) * (a[i].x - a[j].x) / (4.0 * a[j].y), a[i].y);
				}
			}
			printf("%.3f\n", a[i].y);
		}
	}
	return 0;
}
