#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

int m, n;
ll ans = 1;
int p[N], siz[N], edge[N];
bool has_ring[N], done[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	for(rgi i = 0; i < n; ++i)
	{
		p[i] = i;
		siz[i] = 1;
	}
}

int Find(int x)
{
	return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);
	if(pa != pb)
	{
		p[pa] = pb;
		siz[pb] += siz[pa];
		edge[pb] += edge[pa] + 1;
		if(has_ring[pa])
			has_ring[pb] = 1;
	}
}

int main()
{
	m = read(), n = read();
	init();
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		int x = Find(u), y = Find(v);
		if(u == v)
		{
			edge[x]++;
			has_ring[x] = 1;
			continue;
		}
		if(x == y)
		{
			edge[x]++;
			continue;
		}
		Union(x, y);
	}
	for(rgi i = 0; i < n; ++i)
	{
		int x = Find(i);
		if(done[x])
			continue;
		done[x] = 1;
		if(edge[x] > siz[x])
		{
			ans = 0;
			continue;
		}
		if(edge[x] == siz[x] - 1)
		{
			ans = ans * siz[x] % mod;
			continue;
		}
		if(has_ring[x])
			continue;
		ans = ans * 2 % mod;
	}
	printf("%lld", ans % mod);
	return 0;
}

