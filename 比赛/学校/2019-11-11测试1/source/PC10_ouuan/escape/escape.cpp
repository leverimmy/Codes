#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int dir[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};

int n, m;
pii s, t;
queue<pii> q;
vector<string> a;
vector<vector<int> > dis;
vector<vector<bool> > vis;

void dfs(int x, int y, int d)
{
	if (x < 1 || x > n || y < 1 || y > m || vis[x][y] || dis[x][y] < d) return;
	vis[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		dfs(tx, ty, d);
	}
}

int main()
{
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);
	
	cin >> n >> m;
	
	a.resize(n + 1);
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		for (int j = 1; j <= m; ++j)
		{
			if (a[i][j] == 'V') s = pii(i, j);
			else if (a[i][j] == 'J') t = pii(i, j);
		}
	}
	
	dis.resize(n + 1, vector<int>(m + 1, -1));
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (a[i][j] == '+')
			{
				dis[i][j] = 0;
				q.push(pii(i, j));
			}
		}
	}
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int d = dis[x][y];
		q.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			int tx = x + dir[i][0];
			int ty = y + dir[i][1];
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && dis[tx][ty] == -1)
			{
				dis[tx][ty] = d + 1;
				q.push(pii(tx, ty));
			}
		}
	}
	
	int l = 0, r = n + m;
	
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		vis.assign(n + 1, vector<bool>(m + 1, false));
		dfs(s.first, s.second, mid);
		if (vis[t.first][t.second]) l = mid;
		else r = mid - 1;
	}
	
	cout << l << endl;
	
	return 0;
}
