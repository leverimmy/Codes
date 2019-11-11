#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Edge
{
	int u, v, a, b;
	bool operator<(const Edge& y) const
	{
		return b < y.b;
	}
};

bool cmp(const Edge& x, const Edge& y)
{
	return x.a < y.a;
}

int n, m, cost_a, cost_b;
vector<Edge> e, t;
vector<int> f;

int find(int x)
{
	return x == f[x] ? x : f[x] = find(f[x]);
}

int main()
{
	freopen("pay.in", "r", stdin);
	freopen("pay.out", "w", stdout);
	
	scanf("%d%d%d%d", &n, &m, &cost_a, &cost_b);
	
	e.resize(m);
	
	for (int i = 0; i < m; ++i) scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].a, &e[i].b);
	
	sort(e.begin(), e.end(), cmp);
	
	f.resize(n + 1);
	
	ll ans = 1e18;
	
	for (int i = 0; i < m; ++i)
	{
		t.insert(lower_bound(t.begin(), t.end(), e[i]), e[i]);
		int del = -1;
		int block = n;
		for (int j = 1; j <= n; ++j) f[j] = j;
		for (int j = 0; j < t.size(); ++j)
		{
			int u = t[j].u;
			int v = t[j].v;
			if (find(u) == find(v)) del = j;
			else
			{
				--block;
				f[find(v)] = find(u);
			}
		}
		if (~del) t.erase(t.begin() + del);
		if (block == 1) ans = min(ans, (ll) e[i].a * cost_a + (ll) t.back().b * cost_b);
	}
	
	if (ans < 1e17) cout << ans;
	else puts("-1");
	
	return 0;
}
