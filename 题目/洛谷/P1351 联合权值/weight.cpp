#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 10007;

int n, cnt, ans, max_val = -oo;
int first[N], w[N], son[N], sum[N], dep[N], f[N][2], sqr[N];

struct edge {
	int to, _next;
} e[N << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch = '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int p) {
	int max_son1 = 0, max_son2 = 0;
	dep[x] = dep[p] + 1;
	f[x][0] = p, f[x][1] = f[p][0];
	ans = (ans + w[x] * w[f[x][1]] * 2 % mod) % mod;
	max_val = max(max_val, w[x] * w[f[x][1]]);
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to)
		if(y != p) {
			dfs(y, x);
			sum[x] = (sum[x] + w[y]) % mod;
			sqr[x] = (sqr[x] + w[y] * w[y]) % mod;
			if(w[y] > max_son2) {
				if(w[y] > max_son1) {
					max_son2 = max_son1;
					max_son1 = w[y];
				}
				else
					max_son2 = w[y];
			}
		}
	ans = (ans + sum[x] * sum[x] - sqr[x]) % mod;
	max_val = max(max_val, max_son1 * max_son2);
}

int main() {
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	for(rgi i = 1; i <= n; ++i)	w[i] = read();
	dfs(1, 0);
	printf("%d %d", max_val, ans);
	return 0;
}
/*
5
1 2
2 3
3 4
4 5
1 5 2 3 10

*/
