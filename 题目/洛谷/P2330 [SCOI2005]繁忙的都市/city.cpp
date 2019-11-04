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
#define maxn 310
#define maxm 100010

using namespace std;

int n, m, cnt, big = -1;
int p[maxn];

struct edge
{
	int u, v, w;
} e[maxm << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct edge a, struct edge b)
{
	return a.w < b.w;
}

void init()
{
	for(rgi i = 1; i <= n; ++i)
		p[i] = i;
}

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int uunion(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if(pa != pb)
	{
		p[pa] = pb;
		return 1;
	}
	return 0;
}

int main()
{
	n = read(), m = read();
	init();
	for(rgi i = 1; i <= m; ++i)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	sort(e + 1, e + m + 1, cmp);
	for(rgi i = 1; i <= m; ++i)
	{
		if(cnt == n - 1)
			break;
		if(uunion(e[i].u, e[i].v))
		{
			cnt++;
			big = max(big, e[i].w);
		}
	}
	printf("%d %d", cnt, big);
	return 0;
}

