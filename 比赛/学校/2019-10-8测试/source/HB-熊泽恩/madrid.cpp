#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const double P = acos(-1);

int n, m, l, r, siz, cnt = 1;
double _p, _q, a;

int belong[N];

struct IN {
	double x, y;
} in[N];

struct cmd {
	char opt;
	double dx, dy, da;
};

queue <struct cmd> q[N];

void Modify(int l, int r, double curp, double curq) {
	int posl = belong[l], posr = belong[r];
	if(posl == posr) {
		for(rgi i = l; i <= r; ++i) {
			in[i].x += curp;
			in[i].y += curq;
		}
	}
	for(rgi i = posl + 1; i <= posr - 1; ++i)
		q[i].push((cmd){'M', curp, curq, 0});
	for(rgi i = l; i <= min(r, posl * siz); ++i) {
		in[i].x += curp;
		in[i].y += curq;
	}
	for(rgi i = max(l, (posr - 1) * siz + 1); i <= r; ++i) {
		in[i].x += curp;
		in[i].y += curq;
	}
}

void Rotate_x(int l, int r) {
	int posl = belong[l], posr = belong[r];
	if(posl == posr)
		for(rgi i = l; i <= r; ++i)
			in[i].y = -in[i].y;
	for(rgi i = posl + 1; i <= posr - 1; ++i)
		q[i].push((cmd){'X', 0, 0, 0});
	for(rgi i = l; i <= min(r, posl * siz); ++i)
		in[i].y = -in[i].y;
	for(rgi i = max(l, (posr - 1) * siz + 1); i <= r; ++i)
		in[i].y = -in[i].y;
}

void Rotate_y(int l, int r) {
	int posl = belong[l], posr = belong[r];
	if(posl == posr)
		for(rgi i = l; i <= r; ++i)
			in[i].x = -in[i].x;
	for(rgi i = posl + 1; i <= posr - 1; ++i)
		q[i].push((cmd){'Y', 0, 0, 0});
	for(rgi i = l; i <= min(r, posl * siz); ++i)
		in[i].x = -in[i].x;
	for(rgi i = max(l, (posr - 1) * siz + 1); i <= r; ++i)
		in[i].x = -in[i].x;
}

void Rotate_xy(int l, int r) {
	int posl = belong[l], posr = belong[r];
	if(posl == posr)
		for(rgi i = l; i <= r; ++i)
			swap(in[i].x, in[i].y);
	for(rgi i = posl + 1; i <= posr - 1; ++i)
		q[i].push((cmd){'O', 0, 0, 0});
	for(rgi i = l; i <= min(r, posl * siz); ++i)
		swap(in[i].x, in[i].y);
	for(rgi i = max(l, (posr - 1) * siz + 1); i <= r; ++i)
		swap(in[i].x, in[i].y);
}

void Rotate_a(int l, int r, double a) {
	int posl = belong[l], posr = belong[r];
	if(posl == posr)
		for(rgi i = l; i <= r; ++i) {
			double curx = in[i].x, cury = in[i].y;
			in[i].x = cos(a) * curx - sin(a) * cury;
			in[i].y = sin(a) * curx + cos(a) * cury;
		}
	for(rgi i = posl + 1; i <= posr - 1; ++i)
		q[i].push((cmd){'R', 0, 0, a});
	for(rgi i = l; i <= min(r, posl * siz); ++i) {
		double curx = in[i].x, cury = in[i].y;
		in[i].x = cos(a) * curx - sin(a) * cury;
		in[i].y = sin(a) * curx + cos(a) * cury;
	}
	for(rgi i = max(l, (posr - 1) * siz + 1); i <= r; ++i) {
		double curx = in[i].x, cury = in[i].y;
		in[i].x = cos(a) * curx - sin(a) * cury;
		in[i].y = sin(a) * curx + cos(a) * cury;
	}
}

void Deal(int x) {
	int posx = belong[x];
	while(!q[posx].empty()) {
		struct cmd cur = q[posx].front(); q[posx].pop();
		if(cur.opt == 'M') {
			in[x].x += cur.dx;
			in[x].y += cur.dy;
		}
		else if(cur.opt == 'X') {
			in[x].y = -in[x].y;
		}
		else if(cur.opt == 'Y') {
			in[x].x = -in[x].x;
		}
		else if(cur.opt == 'O') {
			swap(in[x].x, in[x].y);
		}
		else if(cur.opt == 'R') {
			double curx = in[x].x, cury = in[x].y;
			in[x].x = cos(cur.da) * curx - sin(cur.da) * cury;
			in[x].y = sin(cur.da) * curx + cos(cur.da) * cury;
		}
	}
}

int main() {
	freopen("madrid.in", "r", stdin);
	freopen("madrid.out", "w", stdout);
	scanf("%d", &n); siz = sqrt(n);
	for(rgi i = 1; i <= n; ++i) {
		scanf("%lf", &in[i].x);
		scanf("%lf", &in[i].y);
		belong[i] = cnt;
		if(i % siz == 0)	cnt++;
	}
	scanf("%d", &m);
	for(rgi i = 1; i <= m; ++i) {
		char op[5];	scanf("%s", op);
		if(op[0] == 'M') {
			scanf("%d %d %lf %lf", &l, &r, &_p, &_q);
			Modify(l, r, _p, _q);
		}
		else if(op[0] == 'X') {
			scanf("%d %d", &l, &r);
			Rotate_x(l, r);
		}
		else if(op[0] == 'Y') {
			scanf("%d %d", &l, &r);
			Rotate_y(l, r);
		}
		else if(op[0] == 'O') {
			scanf("%d %d", &l, &r);
			Rotate_xy(l, r);
		}
		else if(op[0] == 'R') {
			scanf("%d %d %lf", &l, &r, &a);
			Rotate_a(l, r, a * P / 180);
		}
	}
	for(rgi i = 1; i <= n; ++i) {
		Deal(i);
		printf("%.2lf %.2lf\n", in[i].x, in[i].y);
	}
	return 0;
}
/*
3
1 2
-2 2.5
0 -3
3
X 1 3
M 1 3 3 6
R 1 3 90

*/
