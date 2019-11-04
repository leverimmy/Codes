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
#define maxn 510
#define maxm 500010

using namespace std;

int n, m, k, cnt;
double D = -1.0;
int p[maxn], x[maxn], y[maxn];

struct edge
{
	int u, v;
	double w;
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

double dis(int a, int b)
{
	return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}

int main()
{
	k = read(), n = read();
	init();
	for(rgi i = 1; i <= n; ++i)
	{
		x[i] = read();
		y[i] = read();
	}
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = i + 1; j <= n; ++j)
		{
			m++;
			e[m].u = i;
			e[m].v = j;
			e[m].w = dis(i, j);
		}
	sort(e + 1, e + m + 1, cmp);
	for(rgi i = 1; i <= m; ++i)
	{
		if(cnt == n - k)
			break;
		if(uunion(e[i].u, e[i].v))
		{
			cnt++;
			D = max(D, e[i].w);
		}
	}
	printf("%.2f", D);
	return 0;
}

