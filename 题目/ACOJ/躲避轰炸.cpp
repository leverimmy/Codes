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
#define maxn 100010

using namespace std;

int n, q, j = 1;
int p[maxn], num[maxn], ans[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

struct node
{
	int u, v, w;
} e[maxn];

struct qry
{
	int val, id, _in;
} qy[maxn];

void init(int x)
{
	for(rgi i = 1; i <= x; ++i)
		p[i] = i;
	for(rgi i = 1; i <= x; ++i)
		num[i] = 1;
}

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

void _union(int a, int b)
{
	int pa = find(a);
	int pb = find(b);
	if(pa != pb)
	{
		num[pa] = num[pa] + num[pb];
		num[pb] = num[pa];
		p[pa] = pb;
	}
}

bool cmp1(struct node a, struct node b)
{
	return a.w > b.w;
}

bool cmp2(struct qry a, struct qry b)
{
	return a.val > b.val;
}

int main()
{
	n = read(), q = read();
	for(rgi i = 1; i <= n; ++i)
	{
		p[i] = i;
		num[i] = 1;
	}
	for(rgi i = 1; i <= n - 1; ++i)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	sort(e + 1, e + n + 1, cmp1);
	for(rgi i = 1; i <= q; ++i)
	{
		qy[i].val = read();
		qy[i].id = read();
		qy[i]._in = i;
	}
	sort(qy + 1, qy + q + 1, cmp2);
	for(rgi i = 1; i <= q; ++i)
	{
		while(j < n && e[j].w >= qy[i].val)
		{
			_union(e[j].u, e[j].v);
			j++;
		}
		ans[qy[i]._in] = num[find(qy[i].id)];
	}
	for(rgi i = 1; i <= q; ++i)
		write(ans[i] - 1), putchar('\n');
	return 0;
}

