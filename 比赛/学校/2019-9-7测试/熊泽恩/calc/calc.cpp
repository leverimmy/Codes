#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#define il inline
#define rgi register int
#define rgl register long long
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n;
ll ans;
int p[N], siz[N];

struct edge
{
	int u, v, w;
} e[N << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	for(rgi i = 1; i <= n; ++i)
		p[i] = i, siz[i] = 1;
}

int Find(int x)
{
	return x == p[x] ? x : p[x] = Find(p[x]);
}

bool cmp(struct edge a, struct edge b)
{
	return a.w < b.w;
}

int main()
{
	freopen("calc.in", "r", stdin);
	freopen("calc.out", "w", stdout);
	n = read();
	init();
	for(rgi i = 1; i <= n - 1; ++i)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	sort(e + 1, e + n, cmp);
	for(rgi i = 1; i <= n - 1; ++i)
	{
		int cur_u = e[i].u, cur_v = e[i].v, cur_w = e[i].w;
		int A = Find(cur_u), B = Find(cur_v);
		if(A != B)
		{
			p[A] = B;
			ans += (ll)siz[A] * siz[B] * cur_w;
			siz[B] += siz[A];
		}
	}
	printf("%lld", ans);	
	return 0;
}

