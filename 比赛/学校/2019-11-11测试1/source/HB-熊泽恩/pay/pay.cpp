#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const int N = 200 + 10;
const int M = 5e4 + 10;

ll n, m, p[N], G, D;
ll ans = oo;

struct EDGE {
	ll u, v, g, d;
	bool operator < (const struct EDGE &rhs) const {
		return d < rhs.d;
	}
} e[M];

std::vector <struct EDGE> vec;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(const struct EDGE &a, const struct EDGE &b) {
	return a.g < b.g;
}

ll Find(ll x) {
	return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(ll x, ll y) {
	ll px = Find(x), py = Find(y);
	if(px != py)	p[px] = py;
}

int main() {
	freopen("pay.in", "r", stdin);
	freopen("pay.out", "w", stdout);
	n = read(), m = read();
	G = read(), D = read();
	for(rgi i = 1; i <= m; ++i) {
		e[i].u = read(), e[i].v = read();
		e[i].g = read(), e[i].d = read();
	}
	std::sort(e + 1, e + m + 1, cmp);
	for(rgi i = 1, del = -1, cnt = n; i <= m; ++i, del = -1, cnt = n) {
		for(rgi j = 1; j <= n; ++j)	p[j] = j;
		vec.insert(std::lower_bound(vec.begin(), vec.end(), e[i]), e[i]);
		
		for(rgi j = 0; j < vec.size(); ++j) {
			int u = vec[j].u;
			int v = vec[j].v;
			
			if(Find(u) != Find(v)) {
				cnt--;
				Union(u, v);
			}
			else
				del = j;
		}
		if(~del)	vec.erase(vec.begin() + del);
		if(cnt == 1)	ans = std::min(ans, e[i].g * G + vec.back().d * D);
	}
	if(ans < oo)
		printf("%lld", ans);
	else
		puts("-1");
	return 0;
}
/*
5 10
8 8
1 4 5 7
3 5 8 6
3 4 8 6
4 3 6 10
3 2 5 9
1 3 7 4
1 5 7 7
4 2 6 4
2 1 10 4
4 3 7 5

*/
