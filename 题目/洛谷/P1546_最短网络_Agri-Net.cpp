#include <cstdio>
#include <cstring>
#include <algorithm>
#define rgi register int
#define il inline
#define ll long long
#define maxn 100010
#define maxm 500010

using namespace std;

int n, tot, cnt, sum;
int p[maxn];

struct edge
{
	int u, v, w;
} e[maxm];

bool cmp(struct edge x, struct edge y)
{
	return x.w < y.w;
}

void init()
{
	for(rgi i = 1; i <= maxn; ++i)
		p[i] = i;
}

int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}

int _union(int x, int y)
{
	int px = find(x);
	int py = find(y);
	if(px != py)
	{
		p[px] = py;
		return 1;
	}
	return 0;
}

int main()
{
	init();
	scanf("%d", &n);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
		{
			int val;
			scanf("%d", &val);
			if(j > i)
			{
				e[++cnt].u = i;
				e[cnt].v = j;
				e[cnt].w = val;
			}
		}
//	cnt /= 2;
	sort(e + 1, e + cnt + 1, cmp);
	for(rgi i = 1; i <= cnt; ++i)
	{
		if(_union(e[i].u, e[i].v))
		{
			tot++;
			sum += e[i].w;
		}
		if(tot == n - 1)
			break;
	}
	printf("%d", sum);
	return 0;
}

