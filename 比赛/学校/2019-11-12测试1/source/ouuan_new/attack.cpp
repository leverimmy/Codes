#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
ll ans;
vector<int> a;
vector<vector<ll> > f;
vector<vector<int> > g;

struct FirstThree
{
	ll fi, se, th;
	FirstThree()
	{
		fi = 0;
		se = 0;
		th = 0;
	}
	void insert(ll x)
	{
		if (x > fi)
		{
			th = se;
			se = fi;
			fi = x;
		}
		else if (x > se)
		{
			th = se;
			se = x;
		}
		else if (x > th) th = x;
	}
	ll get(ll x)
	{
		if (x == fi) return se + th;
		else if (x == se) return fi + th;
		else return fi + se;
	}
};

void dfs(int u, int fa)
{
	FirstThree t, tt;
	f[u][0] = a[u];
	for (int i = 0; i < g[u].size(); ++i)
	{
		int v = g[u][i];
		if (v == fa) continue;
		dfs(v, u);
		t.insert(f[v][0]);
		tt.insert(f[v][1]);
		f[u][1] = max(f[u][1], f[v][1]);
		f[u][0] = max(f[u][0], f[v][0] + a[u]);
	}
	f[u][1] = max(f[u][1], t.get(-1) + a[u]);
	ans = max(ans, tt.get(-1));
	ans = max(ans, f[u][1]);
	for (int i = 0; i < g[u].size(); ++i)
	{
		int v = g[u][i];
		if (v == fa) continue;
		ans = max(ans, f[v][1] + t.get(f[v][0]) + a[u]);
	}
}

int main()
{
	freopen("attack.in", "r", stdin);
	freopen("attack.out", "w", stdout);
	
	scanf("%d", &n);
	
	a.resize(n + 1);
	g.resize(n + 1);
	f.resize(n + 1, vector<ll>(2, 0));
	
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	
	for (int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1, 0);
	
	cout << ans << endl;
	
	return 0;
}
