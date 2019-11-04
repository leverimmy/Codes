#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 2e5 + 10;
const int M = 2e5 + 10;

int n, m;
int dis[N], ans[M];

struct NUMBER {
	int val, id;
	bool operator < (const struct NUMBER &rhs)	const {
		return val == rhs.val ? id < rhs.id : val < rhs.val;
	}
} a[N];

struct QUERY {
	int l, r, id;
	bool operator < (const struct QUERY &rhs) const {
		return r < rhs.r;
	}
} q[M];

class BIT {
	private:
		static const int MAX_SIZE = 2e5;
		int c[MAX_SIZE + 10];
	public:
		void add(int x, int val) {
			for(; x; x -= x & -x)
				c[x] = min(c[x], val);
		}
		int query(int x) {
			int res = oo;
			for(; x <= MAX_SIZE; x += x & -x)
				res = min(res, c[x]);
			return res;
		}
		void reset() {
			memset(c, 0x3f, sizeof(c));
		}
		BIT() {
			reset();
		}
} t;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("2737.in", "r", stdin);
	freopen("2737.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i) {
		a[i].val = read();
		a[i].id = i;
	}
	for(rgi i = 1; i <= m; ++i) {
		q[i].l = read();
		q[i].r = read();
		q[i].id = i;
	}
	sort(a + 1, a + n + 1);
	sort(q + 1, q + m + 1);
//	q[m + 1] = (QUERY){1, n, n + 1};
	
	for(rgi i = 2; i <= n; ++i)
		if(a[i].val == a[i - 1].val)
			dis[a[i].id] = a[i].id - a[i - 1].id;
	
	for(rgi i = 1, j = 1; i <= n; ++i) {
		if(dis[i])
			t.add(i - dis[i], dis[i]);
		for(; q[j].r <= i && j <= m; ++j)
			ans[q[j].id] = t.query(q[j].l);
	}
	
	for(rgi i = 1; i <= m; ++i)
		printf("%d\n", ans[i] >= oo ? -1 : ans[i]);
	return 0;
}

