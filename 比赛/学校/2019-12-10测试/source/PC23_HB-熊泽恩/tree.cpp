#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int mod = 998244353;
const int N = 2e5 + 10;

int n, cnt, ans, a[N], to[N];
int first[N], deg[N];

struct edge {
	int a, b;
} e[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool Chain() {
	for(rgi i = 1; i <= n; ++i) if(deg[i] >= 3) return 0;
	return 1;
}

ll qmod(ll a, ll b) {
	ll res = 1LL % mod;
	while(b) {
		if(b & 1LL) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	} return res;
}

bool Check() {
	/*
	int f[20][20][20] = {0};
	for(rgi i = 1; i <= n; ++i) {
		for(rgi j = (i == n) ? 1 : (i + 1); a[j] != to[a[i]]; j = (j == n) ? 1 : j + 1)
			f[a[i]][to[a[i]]][a[j]] = 1;
		f[a[i]][to[a[i]]][a[i]] = 1;
		f[a[i]][to[a[i]]][to[a[i]]] = 1;
	}
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
			if(i != j && j != to[i] && i != to[j] && to[i] != to[j]) {
				int A = i, B = to[i];
				int C = j, D = to[j];
				if(f[A][B][C] ^ f[A][B][D]) return 0;
			}
	*/
	for(rgi i = 1; i < n; ++i) {
		for(rgi j = 1; j < n; ++j) {
			int x_1 = e[i].a, x_2 = e[i].b;
			int y_1 = e[j].a, y_2 = e[j].b;
			if(a[x_1] < a[x_2]) std::swap(x_1, x_2);
			if(a[y_1] < a[y_2]) std::swap(y_1, y_2);
			if(a[y_2] > a[x_2] && a[y_2] < a[x_1] && a[y_1] > a[x_1]) return 0;
		}
	}
	return 1;
}

void Brute() {
	for(rgi i = 1; i <= n; ++i) a[i] = i;
	do {
		if(Check()) ans++;
		if(ans > mod) ans %= mod;
	} while(std::next_permutation(a + 1, a + n + 1));
	printf("%d", ans);
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read(), v = read();
		deg[u]++, to[u] = v;
		deg[v]++, to[v] = u;
		e[i].a = u;
		e[i].b = v;
	}
	if(Chain()) {
		printf("%lld", n * qmod(2, n - 2) % mod);
	}
	else if(n <= 9) {
		Brute();
	}
	else {
		
	}
	return 0;
}
/*
9
1 5
5 6
6 3
3 7
3 2
3 8
5 4
1 9

6
1 2
1 5
2 3
2 6
1 4

6
1 2
2 3
3 4
4 5
5 6

9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9

5
1 2
1 3
2 4
2 5

9
1 8
8 3
3 4
4 5
5 6
6 7
7 2
2 9

9
2 1
3 1
4 1
5 1
6 2
7 6
8 4
9 6

*/
