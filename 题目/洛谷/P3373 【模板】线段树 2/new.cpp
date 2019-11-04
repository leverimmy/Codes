#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, m, p;
int a[N];

struct Seg_Tree {
	int lc, rc;
	ll add, mul, dat;
	Seg_Tree() {add = 0, mul = 1;}
} t[N << 2];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Pushup(int o) {
	t[o].dat = t[o << 1].dat + t[o << 1 | 1].dat, t[o].dat %= p;
}

void Build(int o, int l, int r) {
	t[o].lc = l, t[o].rc = r;
	if(l == r) {
		t[o].dat = a[l];
		return;
	}
	int mid = l + r >> 1;
	Build(o << 1, l, mid);
	Build(o << 1 | 1, mid + 1, r);
	Pushup(o);
}

void Spread(int o) {
	if(t[o].mul != 1) {
		t[o << 1].mul *= t[o].mul, t[o << 1].mul %= p;
		t[o << 1 | 1].mul *= t[o].mul, t[o << 1 | 1].mul %= p;
		t[o << 1].add *= t[o].mul, t[o << 1].add %= p;
		t[o << 1 | 1].add *= t[o].mul, t[o << 1 | 1].add %= p;
		t[o << 1].dat *= t[o].mul, t[o << 1].dat %= p;
		t[o << 1 | 1].dat *= t[o].mul, t[o << 1 | 1].dat %= p;
		t[o].mul = 1; 
	}
	if(t[o].add != 0) {
		t[o << 1].add += t[o].add %= p;
		t[o << 1 | 1].add += t[o].add %= p;
		t[o << 1].dat += t[o].add * (t[o << 1].rc - t[o << 1].lc + 1), t[o << 1].dat %= p;
		t[o << 1 | 1].dat += t[o].add * (t[o << 1 | 1].rc - t[o << 1 | 1].lc + 1), t[o << 1 | 1].dat %= p;
		t[o].add = 0;
	}
}

void Add(int o, int l, int r, ll w) {
	if(l <= t[o].lc && t[o].rc <= r) {
		t[o].add += w;
		t[o].dat += (t[o].rc - t[o].lc + 1) * w, t[o].dat %= p;
		return;
	}
	Spread(o);
	int mid = t[o].lc + t[o].rc >> 1;
	if(l <= mid)
		Add(o << 1, l, r, w);
	if(mid < r)
		Add(o << 1 | 1, l, r, w);
	Pushup(o);
}

void Mul(int o, int l, int r, ll w) {
	if(l <= t[o].lc && t[o].rc <= r) {
		t[o].dat *= w, t[o].dat %= p;
		t[o].mul *= w, t[o].mul %= p;
		t[o].add *= w, t[o].add %= p;
		return;
	}
	Spread(o);
	int mid = t[o].lc + t[o].rc >> 1;
	if(l <= mid)
		Mul(o << 1, l, r, w);
	if(mid < r)
		Mul(o << 1 | 1, l, r, w);
	Pushup(o);
}

ll Query(int o, int l, int r) {
	if(t[o].lc == t[o].rc)
		return t[o].dat;
	Spread(o);
	int mid = t[o].lc + t[o].rc >> 1;
	ll res = 0;
	if(l <= mid)
		res += Query(o << 1, l, r) % p, res %= p;
	if(mid < r)
		res += Query(o << 1 | 1, l, r) % p, res %= p;
	return res;
}

int main() {
	freopen("new.in", "r", stdin);
	freopen("new.out", "w", stdout);
	n = read(), m = read(), p = read();
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	Build(1, 1, n);
	for(rgi i = 1; i <= m; ++i) {
		int opt = read(), l = read(), r = read();
		if(opt == 1) {
			int w = read();
			Mul(1, l, r, w);
		}
		if(opt == 2) {
			int w = read();
			Add(1, l, r, w);
		}
		if(opt == 3) {
			printf("%lld\n", Query(1, l, r));
		}
	}
	return 0;
}

