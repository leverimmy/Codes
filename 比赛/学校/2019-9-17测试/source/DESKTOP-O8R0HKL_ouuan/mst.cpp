#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, m, u[N], v[N], a[N], b[N];

struct Kruskal
{
	struct Edge
	{
		int u, v;
		double w;
		bool operator<(const Edge& y) const
		{
			return w < y.w;
		}
	} e[N];
	
	struct UnionFind
	{
		int f[N];
		
		void reset()
		{
			for (int i = 1; i <= n; ++i)
			{
				f[i] = i;
			}
		}
		
		int find(int x)
		{
			return x == f[x] ? x : f[x] = find(f[x]);
		}
		
		void merge(int x, int y)
		{
			f[find(y)] = find(x);
		}
	} dsu;
	
	double mst()
	{
		double out = 0;
		
		dsu.reset();
		
		sort(e + 1, e + m + 1);
		
		for (int i = 1; i <= m; ++i)
		{
			if (dsu.find(e[i].u) == dsu.find(e[i].v)) continue;
			out += e[i].w;
			dsu.merge(e[i].u, e[i].v);
		}
		
		return out;
	}
} mst;

bool check(double k)
{
	for (int i = 1; i <= m; ++i)
	{
		mst.e[i].u = u[i];
		mst.e[i].v = v[i];
		mst.e[i].w = a[i] - k * b[i];
	}
	
	return mst.mst() < 0;
}

int main()
{
	freopen("mst.in", "r", stdin);
	freopen("mst.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= m; ++i) scanf("%d%d%d%d", u + i, v + i, a + i, b + i);
	
	double l = 0, r = 3e9;
	
	for (int i = 1; i <= 100; ++i)
	{
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}
	
	printf("%.10lf", l);
	
	return 0;
}
