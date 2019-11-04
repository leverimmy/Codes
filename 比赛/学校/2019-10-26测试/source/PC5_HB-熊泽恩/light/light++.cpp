#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e5 + 10;

int n, m;
int a[N], ans[N];

struct QUERY {
	int l, r, p, v, id;
	bool operator < (const struct QUERY &rhs)	const {
		if(p == rhs.p) {
			if(l == rhs.l)
				return r < rhs.r;
			else
				return l < rhs.l;
		}
		else
			return p < rhs.p;
	}
} query[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
	
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	for(rgi i = 1; i <= m; ++i) 
		query[i].l = read(), query[i].r = read(), 
		query[i].p = std::min(10001, read()), query[i].v = read(),
		query[i].id = i;
	
	std::sort(query + 1, query + m + 1);
	
	for(rgi i = 1; i <= m; ++i) {
		if(query[i].l == query[i - 1].l) {
			int tmp = query[i].r - query[i - 1].r - 1;
			if(tmp == 0) {
				ans[query[i].id] = ans[query[i - 1].id];
				continue;
			}
			int cur_l = query[i - 1].r + tmp;
			
			for(rgi j = cur_l; j <= query[i].r; ++j)
				ans[query[i].id] += (a[j] % query[i].p == query[i].v);
			ans[query[i].id] += ans[query[i - 1].id];
		}
		else {
			for(rgi j = query[i].l; j <= query[i].r; ++j)
				ans[query[i].id] += (a[j] % query[i].p == query[i].v);
		}
	}
	
	for(rgi i = 1; i <= m; ++i)	printf("%d\n", ans[i]);
	
	return 0;
}

