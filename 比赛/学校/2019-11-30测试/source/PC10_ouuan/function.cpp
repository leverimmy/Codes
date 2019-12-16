#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a, x, y, ly, f;

struct BIT
{
	int tim;
	vector<int> A, vis;
	
	void resize(int size)
	{
		tim = 0;
		A.resize(size + 1, 0);
		vis.resize(size + 1, 0);
	}
	
	void clear() { ++tim; }
	
	void add(int p, int t)
	{
		for (p = A.size() - p; p < A.size(); p += (p & -p))
		{
			if (vis[p] != tim)
			{
				vis[p] = tim;
				A[p] = 0;
			}
			A[p] = max(A[p], t);
		}
	}
	
	int query(int p)
	{
		int out = 0;
		for (p = A.size() - p; p; p -= (p & -p))
		{
			if (vis[p] != tim)
			{
				vis[p] = tim;
				A[p] = 0;
			}
			out = max(out, A[p]);
		}
		return out;
	}
} bit;

bool cmp(int p, int q)
{
	return x[p] > x[q];
}

void solve(int l, int r)
{
	if (l == r - 1) return;
	int mid = (l + r) >> 1;
	solve(mid, r);
	vector<int> c(a.begin() + l, a.begin() + mid);
	sort(a.begin() + l, a.begin() + mid, cmp);
	vector<int> b(r - l);
	bit.clear();
	int i = l, j = mid, k = 0;
	while (i < mid && j < r)
	{
		if (x[a[i]] >= x[a[j]])
		{
			f[a[i]] = max(f[a[i]], bit.query(y[a[i]] + 1));
			b[k++] = a[i++];
		}
		else
		{
			bit.add(y[a[j]], f[a[j]] + 1);
			b[k++] = a[j++];
		}
	}
	while (i < mid)
	{
		f[a[i]] = max(f[a[i]], bit.query(y[a[i]] + 1));
		b[k++] = a[i++];
	}
	while (j < r) b[k++] = a[j++];
	for (i = l; i < mid; ++i) a[i] = c[i - l];
	solve(l, mid);
	for (i = l; i < r; ++i) a[i] = b[i - l];
}

int main()
{
	freopen("function.in", "r", stdin);
	freopen("function.out", "w", stdout);
	
	scanf("%d", &n);
	
	a.resize(n + 1, 0);
	f.resize(n + 1, 1);
	x = y = ly = a;
	
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &x[i], &y[i]);
		ly[i] = y[i];
	}
	
	sort(ly.begin() + 1, ly.end());
	
	ly.resize(unique(ly.begin() + 1, ly.end()) - ly.begin());
	bit.resize(ly.size() - 1);
	
	for (int i = 1; i <= n; ++i)
	{
		a[i] = i;
		y[i] = lower_bound(ly.begin() + 1, ly.end(), y[i]) - ly.begin();
	}
	
	solve(1, n + 1);
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans = max(ans, f[i]);
	
	cout << ans << endl;
	
	return 0;
}
