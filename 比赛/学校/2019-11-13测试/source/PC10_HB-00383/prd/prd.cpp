#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

set<ll> vis;
int T, cnt;
vector<ll> a, b;

void dfs1(int p, ll x)
{
	if (x) a.push_back(x);
	if (p == 0) return;
	dfs1(p - 1, x * 10 + 4);
	dfs1(p - 1, x * 10 + 7);
}

void dfs2(int p, ll x)
{
	if (p < 0) return;
	if (x != 1) vis.insert(x);
	if (1.0 * a[p] * x  <= 1e12 + 1) dfs2(p, a[p] * x);
	dfs2(p - 1, x);
}

ll solve(ll x)
{
	return upper_bound(b.begin(), b.end(), x) - b.begin();
}

int main()
{
	freopen("prd.in", "r", stdin);
	freopen("prd.out", "w", stdout);
	
	dfs1(12, 0);
	sort(a.begin(), a.end());
	
	dfs2(a.size() - 1, 1);
	
	for (set<ll>::iterator it = vis.begin(); it != vis.end(); ++it) b.push_back(*it);
	
	cin >> T;
	
	while (T--)
	{
		ll l, r;
		cin >> l >> r;
		cout << solve(r) - solve(l - 1) << endl;
	}
	
	return 0;
}
