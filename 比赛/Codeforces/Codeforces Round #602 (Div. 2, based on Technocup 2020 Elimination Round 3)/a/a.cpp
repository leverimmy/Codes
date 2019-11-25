#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int T, n;

struct INTERVAL {
	int l, r;
} bet[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	T = read();
	while(T--) {
		n = read();
		int let = oo, rit = 0;
		for(rgi i = 1; i <= n; ++i) {
			bet[i].l = read();
			bet[i].r = read();
			rit = std::max(rit, bet[i].l);
			let = std::min(let, bet[i].r);
		}
		printf("%d\n", std::max(rit - let, 0));
	}
	return 0;
}
/*
4
3
4 5
5 9
7 7
5
11 19
4 17
16 16
3 12
14 17
1
1 10
1
1 1

*/
