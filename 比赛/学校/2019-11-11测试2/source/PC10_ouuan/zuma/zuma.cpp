#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int n, k;
vector<int> a, f;

int main()
{
	freopen("zuma.in", "r", stdin);
	freopen("zuma.out", "w", stdout);
	
	cin >> n >> k;
	
	a.resize(n);
	
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	f.resize(1 << n, INF);
	
	f[0] = 0;
	for (int i = 1; i < (1 << n); ++i)
	{
		vector<int> tmp, mask;
		for (int j = 0; j < n; ++j)
		{
			if ((i >> j) & 1)
			{
				tmp.push_back(a[j]);
				mask.push_back(1 << j);
			}
		}
		for (int j = tmp.size() - 1; j >= 0; --j)
		{
			if (j < tmp.size() - 1 && tmp[j] == tmp[j + 1]) mask[j] |= mask[j + 1];
			f[i] = min(f[i], f[i ^ mask[j]] + max(0, k - __builtin_popcount(mask[j])));
		}
	}
	
	cout << f[(1 << n) - 1];
	
	return 0;
}
