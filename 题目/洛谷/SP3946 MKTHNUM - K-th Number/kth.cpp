#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 2e6 + 10;

int n, m, cntNode, totNum;
int root[N], a[N], num[N], to[N];

struct segNode {
	int lc, rc, dat;
} t[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Build(int &p, int l, int r) {
	if(!p) p = ++cntNode;
	if(l == r) return;
	int mid = l + r >> 1;
	Build(t[p].lc, l, mid);
	Build(t[p].rc, mid + 1, r);
}

void Insert(int &p, int pre, int val, int L, int R) {
	p = ++cntNode;
	t[p].lc = t[pre].lc, t[p].rc = t[pre].rc, t[p].dat = t[pre].dat + 1;
	if(L == R) return;
	int mid = L + R >> 1;
	if(val <= mid)
		Insert(t[p].lc, t[pre].lc, val, L, mid);
	else
		Insert(t[p].rc, t[pre].rc, val, mid + 1, R);
}

int Query(int p, int pre, int val, int L, int R) {
	
	if(L == R) return L;
	int mid = L + R >> 1;
	int delta = t[t[p].lc].dat - t[t[pre].lc].dat;
	if(val <= delta)
		return Query(t[p].lc, t[pre].lc, val, L, mid);
	else
		return Query(t[p].rc, t[pre].rc, val - delta, mid + 1, R);
}

int main() {
	n = read(), m = read();
	Build(root[0], 1, n);
	for(rgi i = 1; i <= n; ++i) {
		a[i] = read();
		num[++totNum] = a[i];
	}
	std::sort(num + 1, num + totNum + 1);
	totNum = std::unique(num + 1, num + totNum + 1) - (num + 1);
	for(rgi i = 1; i <= n; ++i) {
		int pos = std::lower_bound(num + 1, num + totNum + 1, a[i]) - (num + 1) + 1;
		to[pos] = a[i];
		a[i] = pos;
	}
	for(rgi i = 1; i <= n; ++i) Insert(root[i], root[i - 1], a[i], 1, n);
	for(rgi i = 1; i <= m; ++i) {
		int l = read(), r = read(), k = read();
		printf("%d\n", to[Query(root[r], root[l - 1], k, 1, n)]);
	}
	return 0;
}

