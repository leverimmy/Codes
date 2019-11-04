#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define rgl register long long
#define il inline
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5e5 + 10;

int n, m;
int a[N];

struct Seg_Tree {
	int lc, rc;
	int val, pre, suf, sum;
} t[N << 2];

struct node {
	int val, suf, pre;
};

il int read() {
    rgi x = 0, f = 0, ch;
    while(!isdigit(ch = getchar())) f |= ch == '-';
    while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

void Update(int p) {
	t[p].val = max(t[p << 1].val, max(t[p << 1 | 1].val, t[p << 1].suf + t[p << 1 | 1].pre));
	t[p].pre = max(t[p << 1].pre, t[p << 1].sum + t[p << 1 | 1].pre);
	t[p].suf = max(t[p << 1 | 1].suf, t[p << 1].suf + t[p << 1 | 1].sum);
	t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}

void Build(int p, int l, int r) {
	t[p].lc = l, t[p].rc = r;
	if(l == r) {
		t[p].val = t[p].pre = t[p].suf = t[p].sum = a[l];
		return;
	}
	int mid = l + r >> 1;
	Build(p << 1, l, mid);
	Build(p << 1 | 1, mid + 1, r);
	Update(p);
}

void Modify(int p, int x, int val) {
	if(t[p].lc == t[p].rc) {
		t[p].val = t[p].pre = t[p].suf = t[p].sum = val;
		return;
	}
	int mid = t[p].lc + t[p].rc >> 1;
	if(x <= mid)
		Modify(p << 1, x, val);
	else
		Modify(p << 1 | 1, x, val);
	Update(p);
}

struct node Query(int p, int l, int r) {
	if(l <= t[p].lc && t[p].rc <= r)
		return (node){t[p].val, t[p].suf, t[p].pre};
	int mid = t[p].lc + t[p].rc >> 1, res = -oo, left = -oo, right = -oo;
	struct node cur;
	if(l <= mid) {
		cur = Query(p << 1, l, r);
	}
	if(mid < r) {
		cur = Query(p << 1 | 1, l, r);
	}
	res = max(res, cur.val);
	res = max(res, cur.suf + cur.pre);
	left = max(left, cur.suf);
	right = max(right, cur.pre);
	return (node){res, left, right};
}

int main() {
//	freopen("seg.in", "r", stdin);
//	freopen("seg.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i) a[i] = read();
	Build(1, 1, n);
	for(rgi i = 1; i <= m; ++i) {
		int op = read(), l = read(), r = read();
		if(op == 1) {
			if(l > r)   swap(l, r);
			printf("%d\n", Query(1, l, r).val);
			/*puts("here:");
			for(rgi j = l; j <= r; ++j)	printf("%d ", Query(1, j, j));
			puts("end.");*/
		}
		else if(op == 2)
			Modify(1, l, r);
	}
    return 0;
}
/*
8 1
650
148
-894
-212
-820
-341
-240
-620
1 1 8

*/
