#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e5 + 10;

int n, tot, num[N], c[N], q[N];

struct node {
	int x, y, id;
	bool operator < (const struct node &rhs) const {
		if(y == rhs.y)
			return x < rhs.x;
		else
			return y < rhs.y;
	}
} p[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void add(int x, int val) {
	for(; x < N; x += x & -x)	c[x] += val;
}

int query(int x) {
	int res = 0;
	for(; x; x -= x & -x)	res += c[x];
	return res;
}

int main() {
	freopen("17.in", "r", stdin);
	freopen("17.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i) {
		p[i].x = read();
		p[i].y = read();
		p[i].id = i;
		num[++tot] = p[i].x;
		num[++tot] = p[i].y;
	}
	
	std::sort(num + 1, num + tot + 1);
	tot = std::unique(num + 1, num + tot + 1) - (num + 1);
	for(rgi i = 1; i <= n; ++i) {
		p[i].x = std::lower_bound(num + 1, num + tot + 1, p[i].x) - (num + 1);
		p[i].y = std::lower_bound(num + 1, num + tot + 1, p[i].y) - (num + 1);
	}
	
	std::sort(p + 1, p + n + 1);
	
	for(rgi i = 1; i <= n; ++i) {
		add(p[i].x, 1);
		q[query(p[i].x)]++;
	}
	
	for(rgi i = 1; i <= n; ++i)	printf("%d\n", q[i]);
	
	return 0;
}

