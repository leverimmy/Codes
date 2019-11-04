#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 205;
const int INF = 0x3f3f3f3f;

int n, m, a[N], b[N], uu[N * N], vv[N * N];

struct NetworkFlow
{
	int head[N << 1], nxt[N * N * 2], to[N * N * 2], edge[N * N * 2], cnt;
	int dep[N << 1], s, t;
	queue<int> q;
	
	void add(int u, int v, int w)
	{
		nxt[++cnt] = head[u];
		head[u] = cnt;
		to[cnt] = v;
		edge[cnt] = w;
	}
	
	void Add(int u, int v, int w)
	{
		add(u, v, w);
		add(v, u, 0);
	}
	
	bool bfs()
	{
		memset(dep, -1, sizeof(dep));
		dep[s] = 0;
		q.push(s);
		
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int i = head[u]; i; i = nxt[i])
			{
				int v = to[i];
				int w = edge[i];
				if (w > 0 && dep[v] == -1)
				{
					dep[v] = dep[u] + 1;
					q.push(v);
				}
			}
		}
		
		return dep[t] != -1;
	}
	
	int dfs(int u, int flow)
	{
		if (dep[u] == dep[t]) return u == t ? flow : 0;
		
		int out = 0;
		
		for (int i = head[u]; i && flow - out; i = nxt[i])
		{
			int v = to[i];
			int w = edge[i];
			if (w > 0 && dep[v] == dep[u] + 1)
			{
				int f = dfs(v, min(flow - out, w));
				edge[i] -= f;
				edge[i ^ 1] += f;
				out += f;
			}
		}
		
		return out;
	}
	
	int maxflow()
	{
		int out = 0;
		while (bfs()) out += dfs(s, N);
		return out;
	}
	
	void init()
	{
		s = n * 2 + 1;
		t = n * 2 + 2;
		cnt = 1;
		memset(head, 0, sizeof(head));
		
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] < 0) Add(s, i, -a[i]);
			else Add(i, t, a[i]);
			Add(n + i, i, b[i]);
		}
		
		for (int i = 1; i <= m; ++i) Add(uu[i], n + vv[i], INF);
	}
} flow;

int main()
{
	freopen("select.in", "r", stdin);
	freopen("select.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	int sum = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", a + i, b + i);
		if (a[i] > 0) sum += a[i];
	}
	
	for (int i = 1; i <= m; ++i) scanf("%d%d", uu + i, vv + i);
	
	flow.init();
	
	cout << sum - flow.maxflow();
	
	return 0;
}
