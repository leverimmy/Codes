#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const ll N = 1e5 + 10;
const ll M = 2e5 + 10;

ll n, k, cnt, root, ans;
ll first[N], dep[N] = {-1}, siz[N], f[N];

struct edge{
	ll to, _next;
} e[M];

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(ll u, ll v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs1(ll x, ll p) {
	
	siz[x] = 1;
	
	for(rgl i = first[x]; ~i; i = e[i]._next) {
		ll y = e[i].to;
		if(y != p) {
			dfs1(y, x);
			siz[x] += siz[y];
		}
	}
	
	ans += siz[x] * (n - siz[x]);
}

ll Ceil(ll up, ll down) {
	ll div = up / down;
	double uu = up, dd = down;
	double divv = uu / dd;
	
	return (divv - div) > 0 ? (div + 1) : div;
}

void dfs2(ll x, ll p) {
	dep[x] = dep[p] + 1;
	if(x > root)
		ans += Ceil(dep[x], k);
	for(rgl i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)	dfs2(e[i].to, x);
}

void dfs3(ll x, ll p) {
	
}

void dfs4(ll x, ll p) {
	ans += f[x];
	
	for(rgl i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)	dfs4(e[i].to, x);
}

int main() {
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	n = read(), k = read();
	memset(first, -1, sizeof(first));
	for(rgl i = 1; i <= n - 1; ++i) {
		ll u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	
	if(k == 1) {
		dfs1(1, 0);
		printf("%lld", ans);
	}
	else {
		for(rgl i = 1; i <= n; ++i)
			root = i, dfs2(i, 0);
		printf("%lld", ans);
	}
	
	return 0;
}
/*
6 1
1 2
1 3
2 4
2 5
4 6

*/
