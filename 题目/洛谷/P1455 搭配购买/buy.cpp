#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define il inline
#define rgi register int
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 10000 + 10;

int n, m, w, tot;
int C[N], P[N], p[N], profit[N], cost[N];
int f[N];

struct t
{
	int c, p;
} things[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int Find(int x){return x == p[x] ? x : p[x] = Find(p[x]);}
void Union(int a, int b){int pa = Find(a), pb = Find(b); if(pa != pb) p[pa] = pb, cost[pb] += cost[pa], profit[pb]+= profit[pa];}
bool cmp(struct t a, struct t b){return a.c < b.c;}

int main()
{
	n = read(), m = read(), w = read();
	for(rgi i = 1; i <= n; ++i)	C[i] = read(), P[i] = read();
	for(rgi i = 1; i <= n; ++i) p[i] = i, profit[i] = P[i], cost[i] = C[i];
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		Union(u, v);
	}
	for(rgi i = 1; i <= n; ++i)
		if(Find(i) == i)
		{
			tot++;
			things[tot].p += profit[i];
			things[tot].c += cost[i];
		}
	sort(things + 1, things + tot + 1, cmp);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = w; j >= things[i].c; --j)
			f[j] = max(f[j], f[j - things[i].c] + things[i].p);
	printf("%d", f[w]);
	return 0;
}
