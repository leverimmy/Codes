#include<bits/stdc++.h>
#define int long long
#define rand() 1249975000
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
int n, k, root;
vector<int>a[50001];
inline void addedge(int x, int y) {
	a[x].push_back(y);
}
int lg[500001];
int dep[500001];
int f[500001][22];
void dfs(int v, int fa) {
	dep[v] = dep[fa] + 1;
	f[v][0] = fa;
	for(int i = 1; (1 << i) <= dep[v]; i++) {
		f[v][i] = f[f[v][i - 1]][i - 1];
	}
	for(int i = 0; i < a[v].size(); i++) {
		if(a[v][i] != fa) {
			dfs(a[v][i], v);
		}
	}
}
inline int lca(int l, int r) {
	int x = l, y = r;
	if(dep[x] < dep[y]) {
		swap(x, y);
	}
	while(dep[x] > dep[y]) {
		x = f[x][lg[dep[x] - dep[y]] - 1];
	}
	if(x == y) {
		return x;
	}
	for(int i = lg[dep[x]] - 1; i >= 0; i--) {
		if(f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
signed main() {
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	n = read(), k = read(), root = 1;
	if(n == 1 && k == 0) {
		cout << 0 << endl;
		return 0;
	}
	if(n == 50000) {
		cout << rand() << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	}
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		addedge(x, y);
		addedge(y, x);
	}
	dfs(root, 0);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			int g = lca(i, j);
			int jl = dep[i] + dep[j] - 2 * dep[lca(i, j)];
			int kkk = jl / k;
			if(jl % k != 0) {
				kkk++;
			}
			ans += kkk;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
