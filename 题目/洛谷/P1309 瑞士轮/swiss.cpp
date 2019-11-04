#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 100010 << 1

using namespace std;

int n, r, q;

struct node
{
	int s, w, id;
} p[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a, struct node b)
{
	if(a.s == b.s)
		return a.id < b.id;
	else
		return a.s > b.s;
}

int main()
{
//	freopen("testdata.in", "r", stdin);
//	freopen("tttt.out", "w", stdout);
	n = read(), r = read(), q = read();
	for(rgi i = 1; i <= n << 1; ++i)
	{
		p[i].s = read();
		p[i].id = i;
	}
	for(rgi i = 1; i <= n << 1; ++i)
		p[i].w = read();
	sort(p + 1, p + (n << 1) + 1, cmp);
	for(; r; --r)
	{
		for(rgi i = 1; i <= n; ++i)
		{
			int a = (i << 1) - 1, b = i << 1;
			if(p[a].w > p[b].w)
				p[a].s++;
			else if(p[b].w > p[a].w)
				p[b].s++;
		}
		sort(p + 1, p + (n << 1) + 1, cmp);
	}
	printf("%d", p[q].id);
	return 0;
}

