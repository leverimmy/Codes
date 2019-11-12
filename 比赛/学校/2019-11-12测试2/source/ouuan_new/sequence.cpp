#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, k;
vector<int> a;
vector<ll> pre, lsh;

struct BIT
{
	vector<ll> A;
	
	void init()
	{
		A.assign(lsh.size() + 1, 0);
	}
	
	void add(int p, int x)
	{
		for (++p; p <= lsh.size(); p += (p & -p))
		{
			A[p] += x;
		}
	}
	
	ll query(int p)
	{
		ll out = 0;
		for (++p; p; p -= (p & -p)) out += A[p];
		return out;
	}
} bit;

bool check(ll x)
{
	ll cnt = 0;
	bit.init();
	bit.add(a[0], 1);
	for (int i = 1; i <= n; ++i)
	{
		int p = lower_bound(lsh.begin(), lsh.end(), pre[i] - x) - lsh.begin() - 1;
		if (p >= 0) cnt += bit.query(p);
		if (cnt >= k) return false;
		bit.add(a[i], 1);
	}
	return true;
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	
	a.resize(n + 1);
	pre.resize(n + 1, 0);
	lsh.resize(1, 0);
	
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		pre[i] = pre[i - 1] + a[i];
		lsh.push_back(pre[i]);
	}
	
	sort(lsh.begin(), lsh.end());
	lsh.resize(unique(lsh.begin(), lsh.end()) - lsh.begin());
	
	for (int i = 0; i <= n; ++i) a[i] = lower_bound(lsh.begin(), lsh.end(), pre[i]) - lsh.begin();
	
	ll l = -1e11;
	ll r = 1e11;
	
	while (l < r)
	{
		ll mid = (l + r - 1) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	
	cout << l << endl;
	
	return 0;
}
