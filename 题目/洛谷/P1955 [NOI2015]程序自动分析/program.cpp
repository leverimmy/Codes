#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define rgl register long long
#define il inline
#define ll long long

using namespace std;

const int N = 2e5 + 10;

int T, n, tot, flag, cnt;
int p[N], all[N];

struct IN
{
	int u, v, op;
} in[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void init()
{
	tot = flag = 0;
	for(rgi i = 1; i <= n << 1; ++i)
		p[i] = i;
}

int Find(int x)
{
	return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int a, int b)
{
	int pa = Find(a), pb = Find(b);
	if(pa != pb)
		p[pa] = pb;
}

bool cmp(struct IN a, struct IN b)
{
	return a.op > b.op;
}

int main()
{
	T = read();
	for(; T; --T)
	{
		n = read();
		init();
		for(rgi i = 1; i <= n; ++i)
		{
			in[i].u = read();
			in[i].v = read();
			in[i].op = read();
			all[++tot] = in[i].u;
			all[++tot] = in[i].v;
		}
		sort(in + 1, in + n + 1, cmp);
		sort(all + 1, all + tot + 1);
		tot = unique(all + 1, all + tot + 1) - all;
		for(rgi i = 1; i <= n; ++i)
		{
			in[i].u = lower_bound(all + 1, all + tot + 1, in[i].u) - all;
			in[i].v = lower_bound(all + 1, all + tot + 1, in[i].v) - all;
		}
		for(rgi i = 1; i <= n; ++i)
		{
			if(in[i].op)
				Union(in[i].u, in[i].v);
			else if(Find(in[i].u) == Find(in[i].v))
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}

