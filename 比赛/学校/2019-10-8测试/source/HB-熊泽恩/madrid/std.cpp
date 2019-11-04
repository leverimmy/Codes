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
const double PI = 3.1415926535897932384626;

int n, m;

struct IN {
	double x, y;
} in[N];

struct Matrix {
	double a[3][3];
	void init() {for(rgi i = 0; i < 3; ++i)	a[i][i] = 1;}
	void clear() {memset(a, 0, sizeof(a));}
	struct Matrix operator * (struct Matrix &rhs)	const {
		struct Matrix res; res.clear();
		
		for(rgi i = 0; i < 3; ++i)
			for(rgi j = 0; j < 3; ++j)
				for(rgi k = 0; k < 3; ++k)
					res.a[i][j] += a[i][k] * rhs.a[k][j];
		return res;
	}
	Matrix() {clear(); init();}
} dt, base;

struct node {
	int lc, rc;
	struct Matrix mat;
};

class Segment_Tree {
	private:
		static const int MAX_SIZE = 1e5 + 10;
		struct node t[MAX_SIZE << 2];
	public:
		void pushdown(int p) {
//			t[p << 1].mat = t[p << 1].mat * t[p].mat;
			t[p << 1].mat = t[p].mat * t[p << 1].mat;
//			t[p << 1 | 1].mat = t[p << 1 | 1].mat * t[p].mat;
			t[p << 1 | 1].mat = t[p].mat * t[p << 1 | 1].mat;
			t[p].mat.clear();	t[p].mat.init();
		}
		
		void build(int p, int l, int r) {
			t[p].lc = l, t[p].rc = r;
			if(l == r)	return;
			int mid = l + r >> 1;
			build(p << 1, l, mid);
			build(p << 1 | 1, mid + 1, r);
		}
		
		void modify(int p, int l, int r) {	
			if(l <= t[p].lc && t[p].rc <= r) {
				t[p].mat = dt * t[p].mat;
				return;
			}
			pushdown(p);
			int mid = t[p].lc + t[p].rc >> 1;
			if(l <= mid)
				modify(p << 1, l, r);
			if(mid < r)
				modify(p << 1 | 1, l, r);
		}
		
		void query(int p, struct Matrix M) {
			M = M * t[p].mat;
			if(t[p].lc == t[p].rc)
			{
				printf("%.2lf %.2lf\n", in[t[p].lc].x * M.a[0][0] + in[t[p].lc].y * M.a[0][1] + M.a[0][2], 
										in[t[p].lc].x * M.a[1][0] + in[t[p].lc].y * M.a[1][1] + M.a[1][2]);
				return;
			}
			query(p << 1, M);
			query(p << 1 | 1, M);
		}
} tree;

int main() {
//	freopen("madrid.in", "r", stdin);
//	freopen("madrid.out", "w", stdout);
	scanf("%d", &n);
	for(rgi i = 1; i <= n; ++i) {
		scanf("%lf", &in[i].x);
		scanf("%lf", &in[i].y);
	}
	tree.build(1, 1, n);
	scanf("%d", &m);
	for(rgi i = 1; i <= m; ++i) {
		char op[5];	scanf("%s", op);
		int l, r; double p, q, a;
		if(op[0] == 'M') {
			scanf("%d %d %lf %lf", &l, &r, &p, &q);
			dt.a[0][0] = 1;	dt.a[0][1] = 0;	dt.a[0][2] = p;
			dt.a[1][0] = 0;	dt.a[1][1] = 1;	dt.a[1][2] = q;
			dt.a[2][0] = 0;	dt.a[2][1] = 0;	dt.a[2][2] = 1;
		}
		else if(op[0] == 'X') {
			scanf("%d %d", &l, &r);
			dt.a[0][0] = 1;	dt.a[0][1] = 0;		dt.a[0][2] = 0;
			dt.a[1][0] = 0;	dt.a[1][1] = -1;	dt.a[1][2] = 0;
			dt.a[2][0] = 0;	dt.a[2][1] = 0;		dt.a[2][2] = 1;
		}
		else if(op[0] == 'Y') {
			scanf("%d %d", &l, &r);
			dt.a[0][0] = -1;	dt.a[0][1] = 0;	dt.a[0][2] = 0;
			dt.a[1][0] = 0;		dt.a[1][1] = 1;	dt.a[1][2] = 0;
			dt.a[2][0] = 0;		dt.a[2][1] = 0;	dt.a[2][2] = 1;
		}
		else if(op[0] == 'O') {
			scanf("%d %d", &l, &r);
			dt.a[0][0] = 0;	dt.a[0][1] = 1;	dt.a[0][2] = 0;
			dt.a[1][0] = 1;	dt.a[1][1] = 0;	dt.a[1][2] = 0;
			dt.a[2][0] = 0;	dt.a[2][1] = 0;	dt.a[2][2] = 1;
		}
		else if(op[0] == 'R') {
			scanf("%d %d %lf", &l, &r, &a);	a = a * PI / 180;
			dt.a[0][0] = cos(a);	dt.a[0][1] = -sin(a);	dt.a[0][2] = 0;
			dt.a[1][0] = sin(a);	dt.a[1][1] = cos(a);	dt.a[1][2] = 0;
			dt.a[2][0] = 0;			dt.a[2][1] = 0;			dt.a[2][2] = 1;
		}
		tree.modify(1, l, r);
	}
	tree.query(1, base);
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
