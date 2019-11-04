#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <iostream>
#include <set>
#define il inline
#define rgi register int
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 200 + 10;

int n, m, q, ans;
int p[N], enemy[N], siz[N];

set <int> s; 

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int Find(int x)
{
	return x == p[x] ? x : p[x] = Find(p[x]); 
}

void Union(int a, int b)
{
	int pa = Find(a), pb = Find(b);
	if(pa != pb)
	{
		p[pa] = pb;
		siz[pb] += siz[pa];
	}
}

bool Check(int a, int b)
{
	return Find(a) == Find(b);
}

int main()
{
	freopen("geometry.in", "r", stdin);
	freopen("geometry.out", "w", stdout);
	n = read(), m = read(), q = read();
	for(rgi i = 1; i <= n; ++i)	p[i] = i, siz[i] = 1;
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(); 
		char op[4]; scanf("%s", op);
		int v = read();
		if(op[0] == 'p')
		{
			Union(u, v);
			if(enemy[u] && enemy[v])
				if(Check(u, enemy[v]) || Check(enemy[u], v))
				{
					puts("There must be something wrong!");
					return 0;
				}
			if(enemy[u] && enemy[v])
				Union(enemy[u], enemy[v]);
			else if(enemy[u] && !enemy[v])
				enemy[v] = enemy[u];
			else if(!enemy[u] && enemy[v])
				enemy[u] = enemy[v];
		}
		else if(op[0] == 'v')
		{
			if(Check(u, v))
			{
				puts("There must be something wrong!");
				return 0;
			}
			if(!enemy[u])
				enemy[u] = v;
			else
				Union(enemy[u], v);
			if(!enemy[v])
				enemy[v] = u;
			else
				Union(enemy[v], u);
		}
	}
	for(rgi i = 1; i <= n; ++i)
		s.insert(siz[Find(i)]);
	for(set <int> :: iterator it = s.begin(); it != s.end(); ++it)
	{
		int cur_val = *it;
		ans += cur_val * (cur_val - 1) / 2;
	}
	printf("%d\n", ans);
	for(rgi i = 1; i <= q; ++i)
	{
		int u = read(), v = read();
		if(Check(u, v))
			puts("Parallel.");
		else if(Check(u, enemy[v]) || Check(v, enemy[u]))
			puts("Vertical.");
		else
			puts("No idea.");
	}
	return 0;
}
/*
6 5 2
l1 p l2
l2 v l4
l2 p l3
l4 p l5
l4 v l6
l1 l3
l2 l6

2 2 0
l1 v l2
l1 p l2

*/
