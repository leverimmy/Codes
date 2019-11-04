#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

using namespace std;

const int N = 1e5 + 10;

ll n, ans;
ll a[N], l[N], r[N];

struct BIT {
	ll c1[N], c2[N];
	void add1(int x, int val) {for(; x <= N; x += x & -x)	c1[x] += val;}
	ll query1(int x) {ll res = 0;for(; x; x -= x & -x)	res += c1[x];return res;}
	void add2(int x, int val) {for(; x; x -= x & -x)	c2[x] += val;}
	ll query2(int x) {ll res = 0;for(; x <= N; x += x & -x)	res += c2[x];return res;}
	void clear() {memset(c1, 0, sizeof(c1));memset(c2, 0, sizeof(c2));}
	BIT() {clear();}
} t;

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read();
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	for(rgi i = 1; i <= n; ++i)	l[i] = t.query1(a[i]), t.add1(a[i] + 1, 1);
	for(rgi i = n; i >= 1; --i)	r[i] = t.query2(a[i]), t.add2(a[i] - 1, 1);
	for(rgi i = 1; i <= n; ++i)	ans += l[i] * r[i];
//	for(rgi i = 1; i <= n; ++i)	printf("%d %d %d\n", l[i], r[i], l[i] * r[i]);
	printf("%lld", ans);
	return 0;
}
