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
const int N = 1e4 + 10;
const int M = 1e4 + 10;
const double EPS = 1e-7;

int n, m; int p[N];
double ans, l, r;

struct edge
{
	int u, v, a, b;
	double w;
} e[M];

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

int Find(int x){return x == p[x] ? x : p[x] = Find(p[x]);}
void Union(int a, int b){p[Find(a)] = Find(b);}
bool Check(int a, int b){return Find(a) == Find(b);}

bool Judge(double ans)
{
	int tot = 0; ll up = 0, down = 0;
	for(rgi i = 1; i <= n; ++i)	p[i] = i;
	for(rgi i = 1; i <= m; ++i)	e[i].w = (double)e[i].a - ans * e[i].b;
	sort(e + 1, e + m + 1, cmp);
	for(rgi i = 1; i <= m; ++i)
	{
		if(!Check(e[i].u, e[i].v))
		{
			up += e[i].a, down += e[i].b;
			Union(e[i].u, e[i].v);
			tot++;
		}
		if(tot == n - 1)
			break;
	}
	return (double)up / down < ans - EPS;
}

int main()
{
	freopen("mst.in", "r", stdin);
	freopen("mst.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].a = read();
		e[i].b = read();
	}
	l = 0, r = 2e9;
	while(r - l > 1e-7)
	{
		double mid = (l + r) / 2;
		if(Judge(mid))
			r = mid;
		else
			l = mid;
		ans = mid;
	}
	printf("%.6f", ans);
	return 0;
}

