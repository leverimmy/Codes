#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5e5 + 10;

int n, m, w, l;

struct REC {
	int x_1, y_1;
	int x_2, y_2;
} rec[N], cur;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int mix(struct REC a, struct REC b) {
	int _a = max(a.x_1, b.x_1);
	int _b = min(a.x_2, b.x_2);
	int _c = max(a.y_1, b.y_1);
	int _d = min(a.y_2, b.y_2);
	return abs(_a - _b) * abs(_c - _d);
}

int main() {
	n = read(), m = read();
	w = read(), l = read();
	for(rgi i = 1; i <= n; ++i) {
		rec[i].x_1 = read();
		rec[i].y_1 = read();
		rec[i].x_2 = read();
		rec[i].y_2 = read();
	}
	for(rgi i = 1; i <= m; ++i) {
		int ans = 0;
		cur.x_1 = read();
		cur.y_1 = read();
		cur.x_2 = read();
		cur.y_2 = read();
		for(rgi j = 1; j <= n; ++j)	ans += mix(cur, rec[j]);
		printf("%d\n", ans);
	}
	return 0;
}

