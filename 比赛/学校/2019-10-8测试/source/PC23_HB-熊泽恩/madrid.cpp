#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const double P = acos(-1);

int n, m, l, r;
double p, q, a;

struct IN {
	double x, y;
} in[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("madrid.in", "r", stdin);
	freopen("madrid.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i) {
		scanf("%lf", &in[i].x);
		scanf("%lf", &in[i].y);
	}
	m = read();
	for(rgi i = 1; i <= m; ++i) {
		char op[5];	scanf("%s", op);
		l = read(), r = read();
		if(op[0] == 'M') {
			scanf("%lf %lf", &p, &q);
			for(rgi j = l; j <= r; ++j) {
				in[j].x += p;
				in[j].y += q;
			}
		}
		else if(op[0] == 'X') {
			for(rgi j = l; j <= r; ++j)	in[j].y = -in[j].y;
		}
		else if(op[0] == 'Y') {
			for(rgi j = l; j <= r; ++j)	in[j].x = -in[j].x;
		}
		else if(op[0] == 'O') {
			for(rgi j = l; j <= r; ++j)	swap(in[j].x, in[j].y);
		}
		else if(op[0] == 'R') {
			scanf("%lf", &a); a = a * P / 180;
			for(rgi j = l; j <= r; ++j) {
				double curx = in[j].x, cury = in[j].y;
				in[j].x = cos(a) * curx - sin(a) * cury;
				in[j].y = sin(a) * curx + cos(a) * cury;
			}
		}
	}
	for(rgi i = 1; i <= n; ++i)	printf("%.2lf %.2lf\n", in[i].x, in[i].y);
	return 0;
}

