#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;
const int SIZE = 2010;
int head[SIZE], ver[SIZE * 2], Next[SIZE * 2], tot;
int n, m, t, root, len;
int du[SIZE], cycle[SIZE], v[SIZE];
int d[SIZE];

void add(int x, int y)
{
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void bfs(int st)
{
	memset(d, -1, sizeof(d));
	queue<int> q;
	d[st] = 0; 
	q.push(st);
	while (q.size())
	{
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = Next[i])
		{
			int y = ver[i];
			if (d[y] == -1)
			{
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
}

void dfs(int x)
{
	v[x] = 1; len++;
	for (int i = head[x]; i; i = Next[i])
	{
		int y = ver[i];
		if (v[y]) continue;
		dfs(y);
	}
}

int solve(int t)
{
	int ans = n + 1;
	for (int put = 1; put <= n; put++)
	{
		int cnt = 0;
		bfs(put);
		if (d[root] > t) continue;
		memset(v, 0, sizeof(v));
		for (int i = 1; i <= n; i++)
			if (d[i] <= t) v[i] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (!v[i])
			{
				len = 0;
				dfs(i);
				cnt += (len - 1) / (2 * t + 1) + 1;
			}
		}
		ans = min(ans, cnt + 1);
	}
	//cout << t << ' ' << ans << endl;
	return ans;
}

int main()
{
	freopen("holes.in","r",stdin);
	freopen("holes.out","w",stdout);
	cin >> n >> m >> t;
	tot = 1;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
		du[x]++, du[y]++;
	}
	for (int i = 1; i <= n; i++)
		if (du[i] > 2) root = i;
	if (!root)
	{
		//ceil (n-t)/(2t)
		cout << (n - t + 2 * t - 1) / (2 * t) << endl;
		return 0;
	}
	if (n == t)
	{
		cout << 0 << endl;
		return 0;
	}
	int l = 1, r = n;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (solve(mid) <= t) r = mid; else l = mid + 1;
	}
	cout << l << endl;
}
