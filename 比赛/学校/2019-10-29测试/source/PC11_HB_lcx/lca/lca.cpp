#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int n, m, root;
int lg[500001];
vector<int>a[1000001];
int dep[500001];
int fat[500001][22];
void dfs(int v, int fa) {
	dep[v] = dep[fa] + 1;
	fat[v][0] = fa;
	for (int i = 1; (1 << i) <= dep[v]; i++) {
		fat[v][i] = fat[fat[v][i - 1]][i - 1];
	}
	for (int i = 0; i < a[v].size(); i++) {
		if (a[v][i] != fa) {
			dfs(a[v][i], v);
		}
	}
}
inline int lca(int x, int y) {
	int i = x, j = y;
	if (dep[i] < dep[j]) {
		swap(i, j);
	}
	while (dep[i] > dep[j]) {
		i = fat[i][lg[dep[i] - dep[j]] - 1];
	}
	if (i == j) {
		return i;
	}
	for (int k = lg[dep[i]] - 1; k >= 0; k--) {
		if (fat[i][k] != fat[j][k]) {
			i = fat[i][k];
			j = fat[j][k];
		}
	}
	return fat[i][0];
}
signed main() {
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; i++) {
		lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	}
	for (int i = 1; i <= n; i++) {
		int y = read();
		if(y == 0) {
			root = i;
		} else {
			a[i].push_back(y);
			a[y].push_back(i);
		}
	}
	dfs(root, 0);
	int lastans = 0;
	int m = read();
	for (int i = 1; i <= m; i++) {
		int x = read() ^ lastans, y = read() ^ lastans;
		printf("%lld\n", lastans = lca(x, y));
	}
	return 0;
}
/*
10
0 1 2 3 2 4 2 5 4 9
10
3 9
2 7
7 8
1 1
0 6
6 11
6 3
10 7
2 15
*/
