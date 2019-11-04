#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <set> 
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 100000 + 10;

int n, m;
int p[N], enemy[N];

set <int> s;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	for(rgi i = 1; i <= n; ++i)
		p[i] = i;
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
		p[pa] = pb;
}

int main()
{
	n = read(), m = read();
	init();
	for(rgi i = 1; i <= m; ++i)
	{
		char op[5];
		scanf("%s", op);
		if(op[0] == 'E')
		{
			int u = read(), v = read();
			if(!enemy[u])
				enemy[u] = v;
			else
				Union(enemy[u], v);
			if(!enemy[v])
				enemy[v] = u;
			else
				Union(enemy[v], u);
		}
		else if(op[0] == 'F')
		{
			int u = read(), v = read();
			Union(u, v);
		}
	}
	for(rgi i = 1; i <= n; ++i)
		s.insert(Find(i));
	printf("%d", s.size());
	return 0;
}

