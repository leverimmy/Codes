#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;

int n, d, ans; double pos = -oo;

struct inv {
	double l, r;
	bool operator < (const struct inv &rhs)	const {
		return l < rhs.l;
	}
} t[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), d = read();
	for(rgi i = 1; i <= n; ++i) {
		int x = read(), y = read();
		if(y > d) {
			puts("-1");
			return 0;
		}
		t[i].l = (double)(x - sqrt(d * d - y * y));
		t[i].r = (double)(x + sqrt(d * d - y * y));
	}
	
	std::sort(t + 1, t + n + 1);
	
	for(rgi i = 1; i <= n; ++i) {
		if(t[i].l > pos)	pos = t[i].r, ans++;
		else	pos = std::min(pos, t[i].r);
	}
	
	printf("%d ", ans);
	return 0;
}
