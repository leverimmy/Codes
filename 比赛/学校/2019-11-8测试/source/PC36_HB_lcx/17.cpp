#include<bits/stdc++.h>
#define int long long
#define INF 0x7ffffff
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
struct node {
	int x, y;
	bool operator < (const node &b) const  {
		if(y != b.y) {
			return y < b.y;
		} 
		return x < b.x;
	}
}a[15005];
struct SegTree {
	int val, seg;
}tree[600001];
inline void pushdown(int v, int l, int r) {
	if(tree[v].seg != 0) {
		int t = tree[v].seg, mid = (l + r) >> 1;
		tree[v << 1].seg += t;
		tree[v << 1 | 1].seg += t;
		tree[v << 1].val += (mid - l + 1) * t;
		tree[v << 1 | 1].val += (r - mid) * t;
		tree[v].seg = 0;
	}
}
void add(int v, int l, int r, int nl, int nr, int val) {
	if(l <= nl && nr <= r) {
		tree[v].val += val * (nr - nl + 1);
		tree[v].seg += val;
		return;
	}
	if(nl > r || nr < l) {
		return;
	}
	pushdown(v, nl, nr);
	int mid = (nl + nr) >> 1;
	add(v << 1, l, r, nl, mid, val);
	add(v << 1 | 1, l, r, mid + 1, nr, val);
	tree[v].val = tree[v << 1].val + tree[v << 1 | 1].val;
}
int query(int v, int l, int r, int nl, int nr) {
	if(nl >= l && nr <= r) {
		return tree[v].val;
	}
	if(nl > r || nr < l) {
		return 0;
	}
	pushdown(v, nl, nr);
	int mid = (nl + nr) >> 1;
	return query(v << 1, l, r, nl, mid) + query(v << 1 | 1, l, r, mid + 1, nr);
}
int t[150001];
signed main() {
	freopen("17.in", "r", stdin);
	freopen("17.out", "w", stdout);
	int n = read();
	for(int i = 1; i <= n; i++) {
		a[i].x = read(), a[i].y = read();
	}
	sort(a + 1, a + 1 + n);
	int l = 1, r = 1;
	while(r <= n) {
		if(a[r].x == a[l].x) {
			r++;
		} else {
			
		}
	}
	for(int i = 1; i <= n; i++) {
		t[query(1, i, i, 1, n)]++;
	}
	for(int i = 0; i < n; i++) {
		printf("%lld\n", t[i]);
	}
	return 0;
}
/*
5
1 1
5 1
7 1
3 3
5 5
*/
