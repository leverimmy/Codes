#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 2e5 + 10;

int n;

struct node {
	int x, y;
} s, tar, p[N];

struct point {
	int x, y, dat;
	bool operator < (const struct point &rhs) const {
		return dat > rhs.dat;
	}
} tmp[10];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool Range(int _l, int _r, int val) { // val \in [x, y]
	return (_l <= val && val <= _r) || (_r <= val && val <= _l);
}

int main() {
	n = read(), s.x = read(), s.y = read();
	for(rgi i = 1; i <= n; ++i) {
		p[i].x = read();
		p[i].y = read();
	}
	if(s.x < 1e9) { // right
		tar.x = s.x + 1, tar.y = s.y;
		for(rgi i = 1; i <= n; ++i) {
			if(Range(p[i].x, s.x, tar.x) && Range(p[i].y, s.y, tar.y))
				tmp[1].dat++;
		}
		tmp[1].x = tar.x, tmp[1].y = tar.y;
	}
	if(s.x > 0) { // left
		tar.x = s.x - 1, tar.y = s.y;
		for(rgi i = 1; i <= n; ++i) {
			if(Range(p[i].x, s.x, tar.x) && Range(p[i].y, s.y, tar.y))
				tmp[2].dat++;
		}
		tmp[2].x = tar.x, tmp[2].y = tar.y;
	}
	if(s.y < 1e9) { // down
		tar.x = s.x, tar.y = s.y + 1;
		for(rgi i = 1; i <= n; ++i) {
			if(Range(p[i].x, s.x, tar.x) && Range(p[i].y, s.y, tar.y))
				tmp[3].dat++;
		}
		tmp[3].x = tar.x, tmp[3].y = tar.y;
	}
	if(s.y > 0) { // up
		tar.x = s.x, tar.y = s.y - 1;
		for(rgi i = 1; i <= n; ++i) {
			if(Range(p[i].x, s.x, tar.x) && Range(p[i].y, s.y, tar.y))
				tmp[4].dat++;
		}
		tmp[4].x = tar.x, tmp[4].y = tar.y;
	}
	std::sort(tmp + 1, tmp + 4 + 1);
	printf("%d\n%d %d", tmp[1].dat, tmp[1].x, tmp[1].y);
	return 0;
}
/*
3 100 100
0 0
0 0
100 200

*/
