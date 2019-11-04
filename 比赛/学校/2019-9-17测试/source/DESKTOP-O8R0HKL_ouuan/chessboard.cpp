#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 205;

int n;
char board[N][N];

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
	
	void init()
	{
		s = n * 2 + 1;
		t = n * 2 + 2;
		cnt = 1;
		memset(head, 0, sizeof(head));
		
		for (int i = 1; i <= n; ++i)
		{
			Add(s, i, 1);
			Add(n + i, t, 1);
		}
		
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (board[i][j] == '.') Add(i, n + j, 1);
			}
		}
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
} flow;

int main()
{
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);
	
	scanf("%d", &n);
	
	for (int i = 1; i <= n; ++i) scanf("%s", board[i] + 1);
	
	flow.init();
	
	cout << flow.maxflow();
	
	return 0;
}
