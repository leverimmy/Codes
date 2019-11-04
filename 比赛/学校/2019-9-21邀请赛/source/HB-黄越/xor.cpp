#include <stack>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <utility>
#include <iostream>
#define printf(...) 1
using namespace std;

const int N = 100010;
struct E { int to, w; E(int a=0, int b=0): to(a), w(b) {} };
vector<E> v[N]; int n, m;
bool vis[N];
stack<int> x6;

int read() {
	int x, c;
	while (!isdigit(c = getchar())); x = c - 48;
	while (isdigit(c = getchar())) x = x * 10 + c - 48;
	return x;
}

pair<int, int> dfs(int x, int fa = -1) {
	printf("dfs(%d, %d)\n", x, fa);
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); ++i)
		if (v[x][i].to != fa) {
			if (vis[v[x][i].to])
				return printf("(%d, %d) is returned\n", v[x][i].w, v[x][i].to), make_pair(v[x][i].w, v[x][i].to);
			else {
				printf("%d to visit %d\n", x, v[x][i].to);
				pair<int, int> k = dfs(v[x][i].to, x);
				printf("%d visited %d\n", x, v[x][i].to);
				if (~k.first)
					k.first ^= v[x][i].w,
					printf("%d goes to %d when backtracing to %d\n", k.first ^ v[x][i].w, k.first, x);
				if (x == k.second && k.first)
					throw printf("Thrown\n");
				return k;
			}
		}
	return make_pair(-1, -1);
}

void solve() {
	n = read(), m = read();
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; ++i)
		v[i].clear();
	for (int i = 0, a, b, k; i < m; ++i)
		a = read(), b = read(), k = read(),
		v[a - 1].push_back(E(b, k)),
		v[b].push_back(E(a - 1, k));
	try {
		for (int i = 0; i <= n; ++i)
			if (!vis[i])
				dfs(i);
	} catch(...) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	for (int t = read(); t--; solve());
	return 0;
}
