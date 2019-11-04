#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

int read()
{
	int out = 0;
	char c;
	while (!isdigit(c = getchar()));
	for (; isdigit(c); c = getchar()) out = out * 10 + c - '0';
	return out;
}

const int N = 100010;
const int M = 500010;

struct Edge
{
	int u, v, w;
	bool operator<(const Edge& b) const
	{
		return w < b.w;
	}
} e[M];

int head[N], nxt[N << 1], to[N << 1], edge[N << 1], cnt;
int n, m, f[N], mx[N];

void add(int u, int v, int w)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	edge[cnt] = w;
}

void dfs(int u, int fa)
{
	for (int i = head[u]; i; i = nxt[i])
	{
		int v = to[i];
		int w = edge[i];
		if (v == fa) continue;
		mx[v] = max(mx[u], w);
		dfs(v, u);
	}
}

int find(int x)
{
	return x == f[x] ? x : f[x] = find(f[x]);
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	
	n = read();
	m = read();
	
	for (int i = 1; i <= m; ++i)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	
	for (int i = 1; i <= n; ++i) f[i] = i;
	
	sort(e + 1, e + m + 1);
	
	for (int i = 1; i <= m; ++i)
	{
		if (find(e[i].u) == find(e[i].v)) continue;
		add(e[i].u, e[i].v, e[i].w);
		add(e[i].v, e[i].u, e[i].w);
		f[find(e[i].v)] = find(e[i].u);
	}
	
	dfs(1, 0);
	
	int ans = 0;
	
	for (int i = 2; i <= n; ++i) ans += mx[i];
	
	cout << ans << endl;
	
	return 0;
}
