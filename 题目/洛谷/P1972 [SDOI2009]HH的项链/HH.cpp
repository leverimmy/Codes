#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define rgl register long long
#define il inline
#define ll long long

using namespace std;

const int N = 1e6 + 10;
const int M = 1e6 + 10;

int n, m, last = 1;
int a[N], vis[N], c[N], out[M];

struct node
{
	int l, r, id;
} ask[M];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct node a, struct node b)
{
	return a.r < b.r;
}

void Add(int x, int val)
{
	for(; x < N; x += x & -x)
		c[x] += val;
}

int Query(int x)
{
	int res = 0;
	for(; x; x -= x & -x)
		res += c[x];
	return res;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		ask[i].l = read();
		ask[i].r = read();
		ask[i].id = i;
	}
	sort(ask + 1, ask + m + 1, cmp);
	for(rgi i = 1; i <= m; ++i)
	{
		for(rgi j = last; j <= ask[i].r; ++j)
		{
			if(vis[a[j]])
				Add(vis[a[j]], -1);
			Add(j, 1);
			vis[a[j]] = j;
		}
		last = ask[i].r + 1;
		out[ask[i].id] = Query(ask[i].r) - Query(ask[i].l - 1);
	}
	for(rgi i = 1; i <= m; ++i)
		printf("%d\n", out[i]);
	return 0;
}

