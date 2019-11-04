#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int N = 100000 + 10;

int n, p;
ll sa, sp, ans;

struct Interval
{
	int l, r;
} P[N];

struct Node
{
	int val, id;
} q[N << 1];

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp(struct Node a, struct Node b)
{
	return a.val == b.val ? a.id > b.id : a.val < b.val;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		P[i].l = read();
		P[i].r = read();
		sa += P[i].l;
		q[i].val = P[i].l, q[i].id = 1;
		q[i + n].val = P[i].r, q[i + n].id = -1;
	}
	sort(q + 1, q + (n << 1 | 1), cmp);
	for(rgi i = 1; i <= n << 1; ++i)
	{
		if(q[i].id == 1)
		{
			sa -= q[i].val;
			sp++;
			if(ans < sa + sp * q[i].val)
			{
				ans = sa + sp * q[i].val;
				p = q[i].val;
			}
		}
		else if(q[i].id == -1)
		{
			if(ans < sa + sp * q[i].val)
			{
				ans = sa + sp * q[i].val;
				p = q[i].val;
			}
			sp--;
		}
	}
	printf("%d %lld", p, ans);
	return 0;
}

